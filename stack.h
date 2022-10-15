#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack() {}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
size_t Stack<T>::size() const {
    //return vector method size()
	return this->std::vector<T>::size();
}


template <typename T>
bool Stack<T>::empty() const {
    //return vector method empty()
	return this->std::vector<T>::empty();
}


template <typename T>
void Stack<T>::push(const T& item) {
    //push_back() item to vector container
	this->std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop() {
    //use vector method pop_back() to remove element
    if (this->Stack<T>::empty()) throw std::underflow_error("Underflow Error");
    else this->std::vector<T>::pop_back();
}

template <typename T>
const T& Stack<T>::top() const {
    //use vector method back() to get last-added element (top element of Stack)
    if (this->Stack<T>::empty()) throw std::underflow_error("Underflow Error");
    else return this->back();
}


#endif