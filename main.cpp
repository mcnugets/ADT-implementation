#include <iostream>
#include "header/Stack.h"
#include <vector>
using namespace std;
using namespace adt;

int main()
{
    stack<int> st = {1, 2, 3};

    stack<int> st2(st);

    int cunt = st2.top();
    st2.pop();
    size_t soup = st.size();

    soup = 4;
    cout << st.size() << endl;

    return 0;
}