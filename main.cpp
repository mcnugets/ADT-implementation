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
    linkedlist<int>::node n(23);
    linkedlist<int>::node n2(222, &n);

    linkedlist<int> ll(&n2);
    cout << ll.head_() << endl;

    return 0;
}