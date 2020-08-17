#include "FibonacciHeap.h"

namespace fibonacciheap{

FibHeap*  FibHeap::init() {
  FibHeap* heap = nullptr;
  heap = new FibHeap();
  return heap;
}

FibHeap::~FibonacciHeap() {
  delete min_;
  // TODO: delete cons_ inner
  delete cons_;
}

} // fibonacciheap
