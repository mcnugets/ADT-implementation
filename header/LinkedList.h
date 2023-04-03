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
        private:
            type *value;
            node *next;

        public:
            node() : value(nullptr), next(nullptr) {}
            node(const type &val) : value(new type(val)), next(nullptr) {}

            node(const type &val, node *next_) : value(new type(val)), next(next_) {}
            ~node()
            {
                // delete value;
                // if (next != nullptr)
                //     delete next;
            }
            friend std::ostream &operator<<(std::ostream &os, const node &node_)
            {
                os << *node_.value;
                return os;
            }
            type &value_() const
            {
                return *value;
            };
            node &next_() const
            {
                return *next;
            };
        };

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
        void travel();
        node &search(node &value);
        void sort(linkediterator &begin, linkediterator &end);
        void merge(linkedlist<type> &other);
        void reverse(linkediterator &begin, linkediterator &end);
        void concatenate(linkedlist<type> &other);

        // access
        node &head_() const;

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
T linkedlist<type>::linkedlist(node *head_) : head(head_) {} // this shit causes infinite memory allcation since its recursion
T linkedlist<type>::linkedlist(const adt::linkedlist<type> &other) : head(&other.head) {}
T linkedlist<type>::linkedlist(linkediterator &begin, linkediterator &end, type &input)
{
    linkediterator it = begin;
    while (it != end)
    {
        *it = input; // crate assignment operator for linkediterator
        it++;
    }
}
T linkedlist<type>::~linkedlist()
{
    // node *current = head;
    // while (current != nullptr)
    // {
    //     node *temp = current;
    //     delete temp->value;
    //     delete temp;
    //     current = current->next;
    // }
}

T void linkedlist<type>::insert(const node &node_)
{
    linkediterator &it = this->begin();
    while (*it.next != nullptr)
    {
        it++;
    }
    *it.next = node_;
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
T typename linkedlist<type>::node &linkedlist<type>::head_() const
{
    return *head;
}

// list iterator implementation
T linkedlist<type>::linkediterator::linkediterator()
{
}
T linkedlist<type>::linkediterator::linkediterator(node *head_) : ptr(head_) {}
T linkedlist<type>::linkediterator::~linkediterator()
{
    delete this->ptr;
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
    }
    return *this;
}
T typename linkedlist<type>::node &linkedlist<type>::linkediterator::operator*() const
{
    return *ptr;
}

#endif