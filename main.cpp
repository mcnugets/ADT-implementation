#include <iostream>
#include "header/Stack.h"
#include "header/Queue.h"
#include "header/LinkedList.h"
#include <vector>

struct node
{
    int *value;
    node *next;
    node() : value(0), next(nullptr) {}
    node(const int &value) : value(new int(value)), next(nullptr) {}
    node(const int &value, const node &node_) : value(new int(value)), next(new node(node_)) {}
    ~node() {}
    node &operator=(const node &input)
    {
        value = input.value;
        next = input.next;
        return *this;
    }
};

int main()
{
    linkedlist<int>::node n(2);
    linkedlist<int>::node n2(5, n);
    linkedlist<int> ll(n2);

    cout << *ll.end() << endl;

    return 0;
}