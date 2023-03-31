#ifndef linkedlist_h
#define linkedlist_h
#include <iostream>
#include "template.h"
#include "Iterator.h"

namespace adt
{
    T class linkedlist
    {
    private:
        struct node
        {
            type *value;
            node *next;
            node();
            node(type &value, node &next) : value(&value), next(&next)
            {
            }
            ~node() {}
        };
        node *head;

    public:
        // constructors
        linkedlist();
        ~linkedlist();
        linkedlist(node &node);
        linkedlist(linkedlist<type> &other);
        linkedlist(iterator<type> &begin, iterator<type> &end, type &value);
        // modifiers
        void insert(node &input);
        void delete_(node &input);
        void travel();
        node &search(node &value);
        void sort(iterator<type> &begin, iterator<type> &end);
        void merge(linkedlist<type> &other);
        void reverse(iterator<type> &begin, iterator<type> &end);
        void concatenate(linkedlist<type> &other);
        // operators
    };
}

// Linked list implementation
T adt::linkedlist<type>::linkedlist() {}
T adt::linkedlist<type>::linkedlist(node &node) : head(node) {}
T adt::linkedlist<type>::linkedlist(adt::linkedlist<type> &other) : head(&other.head) {}

#endif