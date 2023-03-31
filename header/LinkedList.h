#include <iostream>
#include <Iterator.h>
#define T template <typename t>

namespace adt
{
    T class linkedlist
    {
    private:
        struct node
        {
            t *value;
            node *next;
            node();
            node(t &value, node &next) : value(&value), next(&next)
            {
            }
            ~node() {}
        };
        node *head;

    public:
        // constructors
        linkedlist();
        ~linkedlist();
        linkedlist(t &value);
        linkedlist(linkedlist<t> &other);
        linkedlist(iterator<t> &begin, iterator<t> &end, t &value);
        // modifiers
        void insert(node &input);
        void delete_(node &input);
        void travel();
        node &search(node &value);
        void sort(iterator<t> &begin, iterator<t> &end);
        void merge(linkedlist<t> &other);
        void reverse(iterator<t> &begin, iterator<t> &end);
        void concatenate(linkedlist<t> &other);
    };
}