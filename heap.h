#ifndef HEAP_H
#define HEAP_H
#include<functional>
#include<stdexcept>
#include<iostream>
#include<vector>
#include<cmath>

template <typename T, typename PComparator = std::less<T>>
class Heap {
 public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c=PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

 private:
  /// Add whatever helper functions and data members you need below
  int m_; // step size of tree graph
  PComparator c_;
  std::vector<T> data_;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data_.size();
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data_.empty();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data_.push_back(item);
  int i = size() - 1;
  while (i > 0) {
    int parentIdx = (i-1)/m_;
    if (c_(data_[i], data_[parentIdx])) {
      std::swap(data_[parentIdx], data_[i]); // swap
      i = parentIdx;
    } else {
      break;
    }
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), c_(c) {
  /*
  Args:
    m (int): How many children per node
    c (PComparator): comparison functor
  */
  if (m_ < 2) {
    throw std::invalid_argument("m must be >= 2");
  }
  data_ = {};
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() { }


template <typename T, typename PComparator>
T const & Heap<T, PComparator>::top() const {
  if(empty()) {
    throw std::underflow_error("Heap is empty, nothing at top.");
  }
  // At least one item, Add code to return the top element, DONT REMOVE
  return data_[0];
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
  if(empty()) {
    throw std::underflow_error("Heap is empty, nothing to pop.");
  }
  int bottomIdx = size() - 1;
  std::swap(data_[0], data_[bottomIdx]);
  data_.pop_back();
  int i = 0;

  if (empty()) { return; }

  while(i*m_ + 1 < (int)size()) { // while current index has at least one child (i.e doesn't go out of bounds)
    // find index of best child among all m children
    /* Conceptually *

    if c_(child, parent):
      swap(child, parent)
      i = childIdx
    else:
      break
    */

    // collection of children:
    // 1. i*m + 1
    // 2. i*m + 2
    // 3. i*m + 3
    //...
    // m. i*m + m

    int firstIdx = i*m_+1;
    int bestIdx = firstIdx; // bestIdx = firstIdx
    int lastIdx = std::min((int)size() - 1, i*m_ + m_);

    for (int currIdx = firstIdx + 1; currIdx <= lastIdx; ++currIdx) {
      if (c_(data_[currIdx], data_[bestIdx])) {
        bestIdx = currIdx;
      }
    }

    if (c_(data_[bestIdx], data_[i])) { // compare "best" child and parent node
      std::swap(data_[bestIdx], data_[i]);
      i = bestIdx;
    } else {
      break;
    }
  }
}



#endif

