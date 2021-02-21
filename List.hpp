#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

template <typename T>
class List
{
private:
    struct ListNode
    {
        T element;
        ListNode * prev;
        ListNode * next;
    };
    ListNode * head;
    ListNode * tail;
    unsigned long number_of_elements;
public:
    class NoElement {};
    class BadPosition {};
    List();
    ~List();
    void clear();
    bool is_empty() const;
    unsigned long size() const;
    unsigned long locate(const T &) const;
    T front() const;
    T back() const;
    T retrieve(unsigned long) const;
    void push_front(const T &);
    void push_back(const T &);
    void insert(const T &, unsigned long);
    void pop_front();
    void pop_back();
    void remove(unsigned long);
    void print_forwards() const;
    void print_backwards() const;
};

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), number_of_elements(0UL) {}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
void List<T>::clear()
{
    if (is_empty())
        return;
    ListNode * temp, * elem = head;
    for (unsigned long i = 0UL; i < size(); i++)
    {
        temp = elem;
        elem = elem->next;
        delete temp;
    }
    head = tail = nullptr;
    number_of_elements = 0UL;
}

template <typename T>
bool List<T>::is_empty() const
{
    return number_of_elements == 0UL;
}

template <typename T>
unsigned long List<T>::size() const
{
    return number_of_elements;
}

template <typename T>
unsigned long List<T>::locate(const T & value) const
{
    unsigned long i;
    ListNode * elem = head;
    for(i = 0UL; i < size(); i++)
    {
        if (elem->element == value)
            break;
        elem = elem->next;
    }
    if (i < number_of_elements)
        return i;
    else
        throw NoElement();
}

template <typename T>
T List<T>::front() const
{
    if (! is_empty())
        return head->element;
    else
        throw NoElement();
}

template <typename T>
T List<T>::back() const
{
    if (! is_empty())
        return tail->element;
    else
        throw NoElement();
}

template <typename T>
T List<T>::retrieve(unsigned long position) const
{
    if (is_empty())
        throw NoElement();
    if (position >= size())
        throw BadPosition();
    ListNode * elem = head;
    for (unsigned long i = 0UL; i < position; i++)
        elem = elem->next;
    return elem->element;
}

template <typename T>
void List<T>::push_front(const T & value)
{
    number_of_elements++;
    ListNode * new_node = new ListNode;
    new_node->element = value;
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
        new_node->prev = nullptr;
        new_node->next = nullptr;
        return;
    }
    new_node->prev = nullptr;
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

template <typename T>
void List<T>::push_back(const T & value)
{
    number_of_elements++;
    ListNode * new_node = new ListNode;
    new_node->element = value;
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
        new_node->prev = nullptr;
        new_node->next = nullptr;
        return;
    }
    new_node->next = nullptr;
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
}

template <typename T>
void List<T>::insert(const T & value, unsigned long position)
{
    if (position >= size() + 1UL)
        throw BadPosition();
    number_of_elements++;
    ListNode * new_node = new ListNode;
    new_node->element = value;
    if (head == nullptr)
    {
        new_node->prev = nullptr;
        new_node->next = nullptr;
        head = new_node;
        tail = new_node;
        return;
    }
    if (position == 0UL)
    {
        new_node->prev = nullptr;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }
    if (position == size() - 1UL)
    {
        new_node->prev = tail;
        new_node->next = nullptr;
        tail->next = new_node;
        tail = new_node;
        return;
    }
    ListNode * elem = head;
    for (unsigned long i = 0UL; i < position; i++)
        elem = elem->next;
    new_node->prev = elem->prev;
    new_node->next = elem;
    elem->prev->next = new_node;
    elem->prev = new_node;
}

template <typename T>
void List<T>::pop_front()
{
    if (is_empty())
        throw NoElement();
    number_of_elements--;
    ListNode * temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

template <typename T>
void List<T>::pop_back()
{
    if (is_empty())
        throw NoElement();
    number_of_elements--;
    ListNode * temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

template <typename T>
void List<T>::remove(unsigned long position)
{
    if (is_empty())
        throw NoElement();
    if (position >= size())
        throw BadPosition();
    number_of_elements--;
    ListNode * temp;
    if (position == 0UL)
    {
        temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return;
    }
    if (position == size())
    {
        temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        return;
    }
    temp = head;
    for (unsigned long i = 0UL; i < position; i++)
        temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

template <typename T>
void List<T>::print_forwards() const
{
    ListNode * elem = head;
    for (unsigned long i = 0UL; i < size(); i++)
    {
        std::cout << elem->element << std::endl;
        elem = elem->next;
    }
}

template <typename T>
void List<T>::print_backwards() const
{
    ListNode * elem = tail;
    for (unsigned long i = 0UL; i < size(); i++)
    {
        std::cout << elem->element << std::endl;
        elem = elem->prev;
    }
}

#endif
