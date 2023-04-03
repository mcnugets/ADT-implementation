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
        struct node
        {
            type *value;
            node *next;
            node() : value(nullptr), next(nullptr) {}
            node(const type &val) : value(&val), next(nullptr) {}
            node(const type &value, node &next) : value(&value), next(&next) {}
            ~node() {}
        };

        class linkediterator
        {
        private:
            const node *ptr;

        public:
            linkediterator();
            linkediterator(const node *ptr);
            ~linkediterator();
            linkediterator &operator++(int);
            linkediterator &operator+(const int value);
            const type &operator*() const;
        };

        // constructors
        explicit linkedlist();
        ~linkedlist();
        explicit linkedlist(node &node);
        explicit linkedlist(const linkedlist<type> &other);
        explicit linkedlist(linkediterator &begin, linkediterator &end, type &value);
        // modifiers
        void insert(const node &input);
        void delete_(const node &input);
        void travel();
        node &search(node &value);
        void sort(linkediterator &begin, linkediterator &end);
        void merge(linkedlist<type> &other);
        void reverse(linkediterator &begin, linkediterator &end);
        void concatenate(linkedlist<type> &other);
        // operators
        // iterator
        linkediterator begin();
        linkediterator end();
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

// Linked list implementation
T linkedlist<type>::linkedlist() : head(nullptr) {}
T linkedlist<type>::linkedlist(node &node) : head(&node) {}
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
    delete this->value;
    delete this->head;
}

T void linkedlist<type>::insert(const node &node_)
{
    node *current = head;
    while (current->next != nullptr)
    {
        current = head->next;
    }
    current->next = &node_;
}
// operator imeplementation

// iterator implementation
T typename linkedlist<type>::linkediterator linkedlist<type>::begin()

{

    return linkediterator(head);
}
T typename linkedlist<type>::linkediterator linkedlist<type>::end()
{
    node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    return linkediterator(current);
}

// list iterator implementation
T linkedlist<type>::linkediterator::linkediterator() {}
T linkedlist<type>::linkediterator::linkediterator(const node *head_) : ptr(head_) {}
T linkedlist<type>::linkediterator::~linkediterator() {}

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
    }
    return *this;
}
T const type &linkedlist<type>::linkediterator::operator*() const
{
    return *ptr->next->value;
}

#endif