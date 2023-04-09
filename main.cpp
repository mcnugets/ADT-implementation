#include <iostream>
#include "header/Stack.h"
#include "header/Queue.h"
#include "header/LinkedList.h"
#include <vector>

int main()
{
    // c2::c1 kk(22);
    // c2 kk_parent(&kk);
    // cout << *kk_parent.ptr2->ptr << endl;

    linkedlist<int>::node n3(999);
    linkedlist<int>::node n(23, &n3);
    linkedlist<int>::node n2(222, &n); // 222 23 999
    linkedlist<int> ll(&n2);

    ll.delete_(n2);
    cout << "head: " << ll.head_() << endl;
    cout << "next: " << *ll.head_().next << endl;

    ll.travel();

    return 0;
}