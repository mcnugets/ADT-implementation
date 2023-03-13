#include <iostream>
#include "header/Stack.h"
using namespace std;
using namespace adt;
int main()
{
    adt::stack<int> stack1;
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    vector<int> a;
    vector<int>::iterator begin = a.begin();
    cout << stack1[1] << endl;
    return 0;
}