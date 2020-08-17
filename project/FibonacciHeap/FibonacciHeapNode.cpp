#include "FibonacciHeapNode.h"

namespace fibonacciheap {
FibNode* FibNode::make_node() {
  FibNode* curr = new FibNode();
  return curr;
}

FibNode::~FibonacciHeapNode() {
  delete left_;
  delete right_;
  delete parent_;
  delete child_;
}
} // FibonacciHeapNode
