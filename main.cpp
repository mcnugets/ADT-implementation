#include <iostream>
#include "header/Stack.h"
#include <vector>
using namespace std;
using namespace adt;

int main()
{
    typedef stack<int> stack;
    stack st = {1, 2, 3};
    vector<int> vec = {1, 2, 3};
    stack::iterator it = st.begin();
    it = it + 2;

    cout << *it << endl;

    return 0;
}