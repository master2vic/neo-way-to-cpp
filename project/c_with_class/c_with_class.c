#include <stdio.h>
#include <stdlib.h>

/** TODO:
 *  1. 普通成员变量，静态成员变量
 *  2. 单继承
 * DOC:
 * 
 * 说明：
 * 1. Env 中存放的是唯一全局变量二位列表，这个列表索引就是继承族的次序
 *    (即，在这个环境中第n个继承的类的index就是n)
 * 2. 子类可以通过类型转换的方式成为父类，而本身父类和子类就是一样的指针
 *    所以自然可以用父类指针调用子类方法的方式。
 * 
 * 几点妥协：
 * 1. 如果想做一个可以根据名称直接访问到变量的方式需要做一个map
 *    做一个(名称->地址)的映射关系。但是用纯c手写一个好用的就又
 *    是一个新坑了，所以算了就直接暴力的访问(index->地址)
 * 2. 对于全局变量，对于一个继承树（这里仅仅是一个线性表）来说任
 *    意一个中间level的class来说，上到祖先，下到玄孙皆可访问。
 *    因为我太懒了，一旦做访问权限的管理，又是一番折腾。
 * 3. 本来是想做一个用(void*)可以存放任意类型的数据的，但是三级
 *    指针阅读上不便。而且为了调试和便于表达思维，所以简化问仅仅
 *    支持int。
 * 4. 阅读不方便，确实我没有代码写得像德芙一般丝滑（NOT PPL，
 *    尽管我希望是）。
 */


typedef struct Class Class;

struct Class {
  struct Class *parent_;
  int **static_datas;
  int **static_funcs;
  int **class_local_data_list_;
  int **class_local_func_list_;
};

typedef struct Env {
  int **static_data_lists_;
  int **static_func_lists_;
  struct Class **family_;
  unsigned long int class_num_;
} Env;

Env *make_new_family(int member_num, int max_static_var_num) {
  Env *new_one = (Class *)malloc(sizeof(Class));
  if (NULL != new_one) {
    new_one->class_num_ = 0;

    new_one->family_ = (Class **)malloc(member_num * sizeof(Class *));
    for (int i = 0; i < member_num; i++) {
      new_one->family_ = NULL;
    }

    new_one->static_data_lists_ = (int **)malloc(member_num * sizeof(int *));
    for (int i = 0; i < member_num; i++) {
      new_one->static_data_lists_[i] =
          (int *)malloc(max_static_var_num * sizeof(int));
    }
  }
  return new_one;
}

void make_class_member(int **class_list, int *list, int length) {
  class_list = (int **)malloc(sizeof(int *) * length);
  for (int i = 0; i < length; i++) {
    class_list[i] = &list[i];
  }
  return;
}

Class *make_class(Env *env, Class *father, int *static_data_list, int num_1,
                  int *static_func_list, int num_2, int *class_local_data_list,
                  int num_3, int *class_local_func_list, int num_4) {
  Class *curr;
  curr = (Class *)malloc(sizeof(Class));
  if (NULL != curr) {
    env->class_num_++;
    env->family_[env->class_num_] = curr;
    env->static_data_lists_ = static_data_list;
    env->static_func_lists_ = static_func_list;
    make_class_member(curr->static_datas, static_data_list, num_1);
    make_class_member(curr->static_funcs, static_func_list, num_2);
    make_class_member(curr->class_local_data_list_, class_local_data_list,
                      num_3);
    make_class_member(curr->class_local_func_list_, class_local_func_list,
                      num_4);
    curr->parent_ = father;
  }

  return curr;
}
