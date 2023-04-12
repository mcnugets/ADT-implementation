#include <iostream>
#include "header/Stack.h"
#include "header/Queue.h"
#include "header/LinkedList.h"
#include <vector>

main()
{

    linkedlist<int>::node n3(999);
    linkedlist<int>::node n(23, &n3);
    linkedlist<int>::node n2(222, &n); // 222 23 999
    linkedlist<int> ll(&n2);
    ll.sort(0, 2);
    linkedlist<int>::linkediterator it = ll.begin();
    cout << *it << endl;
    it++;
    cout << *it << endl;
    return 0;
}