#include <iostream>
#include "header/Stack.h"
#include "header/Queue.h"
#include <vector>

int main()
{
    typedef adt::stack<int> stack;
    stack st = {3, 2, 1};
    vector<int> vec = {1, 2, 3};
    adt::iterator<int> it = st.begin();
    st.push(5);
    st.push(6);
    st.pop();
    st.pop();
    std::cout << *st.begin() << std::endl;
    std::cout << *st.end() << std::endl;

    typedef adt::queue<int> queue;

    queue q = {2, 4, 6};
    cout << *q.begin() << endl;

    return 0;
}