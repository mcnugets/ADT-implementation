#ifndef linkedlist_h
#define linkedlist_h
#include <iostream>
#include "template.h"
#include "Iterator.h"

namespace adt
{
    T class linkedlist
    {

    public:
        // NODE STRUCT/CLASS===================================================================================================
        struct node
        {

            type *value;
            node *next;

        private:
            bool is_allocated = false;

        public:
            // constructors
            node() : value(nullptr), next(nullptr) {}
            node(const type &val) : value(new type(val)), next(nullptr) {}

            node(const type &val, node *next_) : value(new type(val)), next(next_)
            {
            }
            ~node()
            {

                delete value;
                next = nullptr;
                value = nullptr;
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
            linkediterator &operator+(const int value);
            bool operator!=(const linkediterator &other) const;
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
        void sort(linkediterator &begin, linkediterator &end);
        void merge(linkedlist<type> &other);
        void reverse(linkediterator &begin, linkediterator &end);
        void concatenate(linkedlist<type> &other);

        // access
        node &head_() const;

        // operators
        // iterator
        const linkediterator begin() const;
        const linkediterator end() const;
        friend std::ostream &operator<<(std::ostream &os, const linkediterator &it)
        {
            os << it;
            return os;
        }

    private:
        node *head;
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
// operator imeplementation

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
T typename linkedlist<type>::linkediterator &linkedlist<type>::linkediterator::operator+(const int value)
{
    int counter = 0;
    while (counter != value)
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

#endif