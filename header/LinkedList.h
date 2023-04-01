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
            const type *value;
            const node *next;
            node() : value(0), next(nullptr) {}
            node(const type &val) : value(&val), next(nullptr) {}
            node(const type &value, const node &next) : value(&value), next(&next) {}
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
        explicit ~linkedlist();
        explicit linkedlist(const node &node);
        explicit linkedlist(const linkedlist<type> &other);
        linkedlist(linkediterator &begin, linkediterator &end, node &value);
        // modifiers
        void insert(node &input);
        void delete_(node &input);
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
        const node *head;
    };
}

// Linked list implementation
T adt::linkedlist<type>::linkedlist() : head(nullptr) {}
T adt::linkedlist<type>::linkedlist(const node &node) : head(&node) {}
T adt::linkedlist<type>::linkedlist(const adt::linkedlist<type> &other) : head(&other.head) {}
T adt::linkedlist<type>::linkedlist(linkediterator &begin, linkediterator &end, node &input)
{
    // iterator<type> it = begin;
    // while (it != end)
    // {
    //     it = begin()
    // }
}
T adt::linkedlist<type>::~linkedlist() {}
// operator imeplementation

// iterator implementation
T typename adt::linkedlist<type>::linkediterator adt::linkedlist<type>::begin()
{

    return linkediterator(head);
}
T typename adt::linkedlist<type>::linkediterator adt::linkedlist<type>::end()
{
    node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    return linkediterator(current);
}

// list iterator implementation
T adt::linkedlist<type>::linkediterator::linkediterator() {}
T adt::linkedlist<type>::linkediterator::linkediterator(const node *head_) : ptr(head_) {}
T adt::linkedlist<type>::linkediterator::~linkediterator() {}

T typename adt::linkedlist<type>::linkediterator &adt::linkedlist<type>::linkediterator::operator++(int)
{
    ptr = ptr->next;
    return *this;
}
T typename adt::linkedlist<type>::linkediterator &adt::linkedlist<type>::linkediterator::operator+(const int value)
{
    int counter = 0;
    while (counter != value)
    {
        ptr = ptr->next;
    }
    return *this;
}
T const type &adt::linkedlist<type>::linkediterator::operator*() const
{
    return *ptr->next->value;
}

#endif