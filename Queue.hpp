#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "List.hpp"

template <typename T>
class Queue
{
private:
    List<T> internal_list;
public:
    class NoElement {};
    void clear();
    bool is_empty() const;
    unsigned long size() const;
    T front() const;
    void enqueue(const T &);
    void dequeue();
    void print() const;
};

template <typename T>
void Queue<T>::clear()
{
    internal_list.clear();
}

template <typename T>
bool Queue<T>::is_empty() const
{
    return internal_list.is_empty();
}

template <typename T>
unsigned long Queue<T>::size() const
{
    return internal_list.size();
}

template <typename T>
T Queue<T>::front() const
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
void Queue<T>::enqueue(const T & value)
{
    internal_list.push_back(value);
}

template <typename T>
void Queue<T>::dequeue()
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
void Queue<T>::print() const
{
    internal_list.print_forwards();
}

#endif
