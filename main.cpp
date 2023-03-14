#include <iostream>
#include "header/Stack.h"
using namespace std;
using namespace adt;
int main()
{
    adt::stack<int> stack1;
    // stack1.push(2);
    // stack1.push(3);
    // stack1.push(4);
    // stack1.push(2);
    // stack1.push(3);
    // stack1.push(4);

    // int popped_value = stack1.pop();
    // cout << popped_value << endl;
    // cout << stack1.size() << endl;
    vector<int> a;
    a.push_back(3);
    int &temp = a.back();
    temp = 4;
    cout << a.back() << endl;
    return 0;
}