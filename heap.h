#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

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
  std::vector<T> items;
  int aryness;
  PComparator comp;

	void trickleDown(int loc);
	void trickleUp(int loc);
  void swap(int loc1, int loc2);
  bool isLeaf(int loc);

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) {
  aryness = m;
  comp = c;
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::isLeaf(int loc) {
  //check if there is atleast one child node.
  //First Child Index i = (m*i) + 1
  //in a m-ary array
  //if this goes out of bounds (meaning not even first child is present),
  //then loc is a leaf node
  if (((unsigned)(loc*aryness) + 1) >= items.size()) return true; 
  else return false;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(int loc1, int loc2) {
  //helper function to swap two elements in an array
  T temp = items[loc1];
  items[loc1] = items[loc2];
  items[loc2] = temp;
}

//trickleUp helper for push
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc) {
  int parent = (loc-1)/aryness;
  //while parent is atleast 0 (i.e. root node) and items is better than parent, swap
  while (parent >= 0 && comp(items[loc], items[parent])) {
    swap(loc, parent);
    loc = parent;
    parent = (loc-1)/aryness;     
  }
}

//trickleDown helper for pop
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int loc) {
  if (isLeaf(loc)) return;
  int count = 1; //to count how far from the left-most child a node is
  int bestChild = (loc * aryness) + count; //best child is highest-priority in heap (smallest if min-heap or biggest if max-heap)
  //while right child is in bounds of heap
  //and right child conforms to indexing of m-ary array
  while ((unsigned)((loc * aryness) + count) < items.size()-1 && count <= aryness) {
    count++;
    int rChild = (loc * aryness) + count;
    if (comp(items[rChild],items[bestChild])) {
      bestChild = rChild;
    }
  }

  //if highest priority child is better than parent, swap
  //recursively call trickleDown on best child
  if (comp(items[bestChild], items[loc])) {
    swap(bestChild, loc);
    trickleDown(bestChild);  
  }
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Underflow Error");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else {
    return items[0];
  }


}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  items.push_back(item);
  trickleUp(items.size() - 1);
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Underflow Error");
  }

  else {
    items[0] = items.back();
    items.pop_back();
    trickleDown(0);
  }

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return (items.size() == 0);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
	return items.size();
}

#endif

