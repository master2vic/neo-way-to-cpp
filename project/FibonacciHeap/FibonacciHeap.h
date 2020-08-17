#ifndef __FIBONACCIHEAP_H__
#define __FIBONACCIHEAP_H__
namespace fibonacciheap {

class FibonacciHeapNode;

class FibonacciHeap {
public:
  FibonacciHeap(const FibonacciHeap&) = delete;
  FibonacciHeap& operator=(const FibonacciHeap&) = delete;
  virtual ~FibonacciHeap();

  FibonacciHeap* init();
  FibonacciHeap* insert();
private:
  FibonacciHeap() = default;
private:
  int keyNum_{0};
  int max_num_of_degree_{0};
  FibonacciHeapNode* min_{nullptr};
  FibonacciHeapNode** cons_{nullptr};
  FibonacciHeap* root;
};

using FibHeap = FibonacciHeap;

}  // namespace fibonacciheap
#endif  // __FIBONACCIHEAP_H__