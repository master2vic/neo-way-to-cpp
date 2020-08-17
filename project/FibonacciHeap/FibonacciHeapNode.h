#ifndef __FIBONACCIHEAPNODE_H__
#define __FIBONACCIHEAPNODE_H__

namespace fibonacciheap {

class FibonacciHeapNode {
public:
  FibonacciHeapNode(const FibonacciHeapNode&) = delete;
  FibonacciHeapNode& operator=(const FibonacciHeapNode&) = delete;

  FibonacciHeapNode* make_node();

  virtual ~FibonacciHeapNode() ;
private:
  FibonacciHeapNode() = default;
private: 
  int key_{0};
  int degree{0};
  FibonacciHeapNode *left_{nullptr};
  FibonacciHeapNode *right_{nullptr};
  FibonacciHeapNode *parent_{nullptr};
  FibonacciHeapNode *child_{nullptr};
  bool is_del_first_child{false};
};

using FibNode = FibonacciHeapNode;

}

#endif // __FIBONACCIHEAPNODE_H__