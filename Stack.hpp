#ifndef STACK_HPP
#define STACK_HPP
#include "List.hpp"

template <typename T>
class Stack
{
private:
    List<T> internal_list;
public:
    class NoElement {};
    void clear();
    bool is_empty() const;
    unsigned long size() const;
    T top() const;
    void push(const T &);
    void pop();
    void print() const;
};

template <typename T>
void Stack<T>::clear()
{
    internal_list.clear();
}

template <typename T>
bool Stack<T>::is_empty() const
{
    return internal_list.is_empty();
}

template <typename T>
unsigned long Stack<T>::size() const
{
    return internal_list.size();
}

template <typename T>
T Stack<T>::top() const
{
    T value;
    try
    {
        value = internal_list.front();
    }
    catch (typename List<T>::NoElement)
    {
        throw NoElement();
    }
    return value;
}

template <typename T>
void Stack<T>::push(const T & value)
{
    internal_list.push_front(value);
}

template <typename T>
void Stack<T>::pop()
{
    try
    {
        internal_list.pop_front();
    }
    catch (typename List<T>::NoElement)
    {
        throw NoElement();
    }
}

template <typename T>
void Stack<T>::print() const
{
    internal_list.print_forwards();
}

#endif
