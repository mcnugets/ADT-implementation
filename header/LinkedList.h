#ifndef linkedlist_h
#define linkedlist_h
#include <iostream>
#include "template.h"
#include "Iterator.h"

namespace adt
{
    // this class has couple issues: destructor and inconsistency with allocating new memory
    // assignment operator creates pointer to reference, while constructor  allocates new memory
    // this needs to be fixed
    T class linkedlist
    {

    public:
        // NODE STRUCT/CLASS===================================================================================================
        struct node
        {

            type *value;
            node *next;

        public:
            // constructors
            node() : value(nullptr), next(nullptr) {}
            node(const type &val) : value(new type(val)), next(nullptr) {}

            node(const type &val, node *next_) : value(new type(val)), next(next_)
            {
            }
            ~node()
            {

                // delete value;
                // next = nullptr;
                // value = nullptr;
            }
            // accessors

            // operators
            friend std::ostream &operator<<(std::ostream &os, const node &node_)
            {
                os << *node_.value;
                return os;
            }
            bool operator!=(const node &other) const
            {
                return *this->value != *other.value;
            }
            node &operator=(const node &other)
            {
                if (this->value == other.value)
                    return *this;

                value = other.value;
                return *this;
            }
            bool operator<=(const node &other) const
            {
                return *this->value <= *other.value;
            }
            bool operator>=(const node &other) const
            {
                return *this->value >= *other.value;
            }
        };
        // LINKED ITERATOR CLASS==============================================================================================
        class linkediterator
        {
        private:
            node *ptr;

        public:
            linkediterator();
            linkediterator(node *ptr);
            ~linkediterator();
            linkediterator &operator++(int);
            linkediterator &operator+(int value);
            bool operator!=(const linkediterator &other) const;
            bool operator<=(const linkediterator &other) const;
            bool operator>=(const linkediterator &other) const;

            node &operator*() const;
        };

        // constructors
        explicit linkedlist();
        ~linkedlist();
        explicit linkedlist(node *head_);
        explicit linkedlist(const linkedlist<type> &other);
        explicit linkedlist(linkediterator &begin, linkediterator &end, type &value);

        // modifiers
        void insert(const node &input);
        void delete_(const node &input);
        void travel() const;
        node &search(const node &value) const;
        void sort(int begin, int end);
        void merge(linkedlist<type> &other);
        void reverse(node *head_);
        void concatenate(linkedlist<type> &other);

        // access
        node &head_() const;
        // operators
        friend std::ostream &operator<<(std::ostream &os, const linkediterator &it)
        {
            os << it;
            return os;
        }
        // iterator
        const linkediterator begin() const;
        const linkediterator end() const;

    private:
        node *head;
        int partition(int i, int j) const;
    };
}
// typedefs
using adt::linkedlist;
T using linkediterator = typename linkedlist<type>::linkediterator;

//-----------------------------------------------------------
// LINKED LIST IMPLEMEMNTATION
T linkedlist<type>::linkedlist() : head(nullptr) {}
T linkedlist<type>::linkedlist(node *head_) : head(head_) {} // this shit causes infinite memory allcation since its recursion
T linkedlist<type>::linkedlist(const adt::linkedlist<type> &other) : head(&other.head) {}
T linkedlist<type>::linkedlist(linkediterator &begin, linkediterator &end, type &input)
{
    linkediterator it = begin;
    while (it != end)
    {
        *it = input;
        it++;
    }
}
T linkedlist<type>::~linkedlist()
{
    // node *current = head;
    // while (current != nullptr)
    // {
    //     node *temp = current;
    //     temp->~node();
    //     current = current->next;
    // }
}
// MODIFIERS
T void linkedlist<type>::insert(const node &node_)
{
    linkediterator it = this->begin();
    while (it != this->end())
    {
        it++;
    }
    *it = node_;
}
T void linkedlist<type>::delete_(const node &node_)
{
    if (!(*head != node_))
    {
        node *temp = head;
        head = head->next;
        temp->~node();
        return;
    }

    node *current = head;
    node *prev = nullptr;
    while (*current != node_)
    {
        prev = current;
        current = current->next;
    }
    if (current->next != nullptr)
        current = current->next;

    if (prev != nullptr)
        prev->next = current;

    delete current;
    delete prev;
}
T void linkedlist<type>::travel() const
{
    node *current = head;
    while (current != nullptr)
    {
        cout << *current << endl;
        current = current->next;
    }
    delete current;
}
T typename linkedlist<type>::node &linkedlist<type>::search(const node &node_) const
{
    node *current = head;
    while (*current != node_)
    {
        current = current->next;
    }
    return current;
}

T int linkedlist<type>::partition(int i, int j) const
{
    linkediterator begin = this->begin();
    linkediterator end = this->begin();
    begin = begin + i;
    end = end + j;

    linkediterator pivot = end;

    node temp1;
    node temp2;
    while (*begin <= *end)
    {
        if (*begin <= *pivot)
        {
            i++;
            linkediterator it = this->begin();
            begin = it + i;
            temp1.value = nullptr;
        }
        else
        {
            temp1 = *begin;
        }
        if (*end >= *pivot)
        {
            j--;
            linkediterator it = this->begin();
            end = it + j;
            temp2.value = nullptr;
        }
        else
        {
            temp2 = *end;
        }
        if (temp1.value != nullptr && temp2.value != nullptr)
        {
            *begin = temp2;
            *end = temp1;
        }
    }

    node temp_pivot = *pivot;
    *pivot = *begin;
    *begin = temp_pivot;

    return i;
}
T void linkedlist<type>::sort(int begin, int end)
{
    if (begin >= end)
        return;
    int i = partition(begin, end);
    sort(begin, i - 1);
    sort(i + 1, end);
}
T void linkedlist<type>::reverse(node *head_)
{
    node *current = head_;
    node *prev = nullptr;
    node *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current = prev;
    head = current;
    // delete current;
}

// iterator implementation
T const typename linkedlist<type>::linkediterator linkedlist<type>::begin() const
{
    return linkediterator(head);
}
T const typename linkedlist<type>::linkediterator linkedlist<type>::end() const
{
    node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    return linkediterator(current);
}
T typename linkedlist<type>::node &linkedlist<type>::head_() const
{
    return *head;
}

//-----------------------------------------------------------------
// LINKED LIST ITERATOR IMPLEMENTATION
T linkedlist<type>::linkediterator::linkediterator()
{
}
T linkedlist<type>::linkediterator::linkediterator(node *head_) : ptr(head_) {}
T linkedlist<type>::linkediterator::~linkediterator()
{
    // this->ptr->~node();
}

T typename linkedlist<type>::linkediterator &linkedlist<type>::linkediterator::operator++(int)
{
    ptr = ptr->next;
    return *this;
}

T typename linkedlist<type>::linkediterator &linkedlist<type>::linkediterator::operator+(int value)
{
    int counter = 0;
    while (counter < value)
    {
        ptr = ptr->next;
        counter++;
    }
    return *this;
}
T typename linkedlist<type>::node &linkedlist<type>::linkediterator::operator*() const
{
    return *ptr;
}
T bool linkedlist<type>::linkediterator::operator!=(const linkediterator &other) const
{
    return (this->ptr != other.ptr);
}
T bool linkedlist<type>::linkediterator::operator<=(const linkediterator &other) const
{
    return ptr <= other.ptr;
}
T bool linkedlist<type>::linkediterator::operator>=(const linkediterator &other) const
{
    return ptr >= other.ptr;
}

#endif