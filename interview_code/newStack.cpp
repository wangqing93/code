#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

struct node
{
    int value;
    int before_min; //
    node(int x, int y)
    {
        value = x;
        before_min = y;
    }
};

struct newStack
{
    vector<node> values;
    void push(int e)
    {
        if (values.size() == 0)
        {
            values.push_back(node(e, MAX_INT));
            return;
        }
        node temp = values[values.size()-1];
        node temp1(e, min(temp.value, temp.before_min));
        values.push_back(temp1);
    }
    void pop()
    {
        values.pop_back();
    }
    int top()
    {
        return values[values.size()-1].value;
    }
    int min_v()
    {
        node temp = values[values.size()-1];
        return min(temp.value, temp.before_min);
    }
};


int main()
{
    newStack test;
    test.push(3);
    test.push(6);
    test.push(1);
    test.push(10);
    cout << test.min_v() << endl;
    test.pop();
    cout << test.min_v() << endl;
    test.pop();
    cout << test.min_v() << endl;
    cout << "Hello world!" << endl;
    return 0;
}
