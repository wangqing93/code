#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define STACK_SIZE  2

//找最后一个小于等于key的元素
int binarySearch(vector<int>  array, int key)
{
    int l = 0, r = array.size()-1 ,mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (array[mid] > key)
            r = mid - 1;       //找最后一个小于等于key的元素，所以大于key一定在左边， 举例 1 3 3 4
        else
            l = mid + 1;
    }
    return r;
}

//找第一个小于key的元素
int binarySearch1(vector<int>  array, int key)
{
    int l = 0, r = array.size()-1 ,mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (array[mid] > key)
            l = mid + 1;       //找最后一个小于等于key的元素，所以大于key一定在左边， 举例 1 3 3 4
        else
            r = mid - 1; //r会减少1
    }
    return l;
}

int delquene(stack<int>* s1, stack<int>* s2)  //s1有值
{
    int res;
    if (s1->empty())
        return -1;
    while (!s1->empty())
    {
        int e = s1->top();
        s1->pop();
        s2->push(e);
    }
    res = s2->top();
    s2->pop();
    while (!s2->empty())
    {
        int e = s2->top();
        s2->pop();
        s1->push(e);
    }
    return res;
}

void  enquene(stack<int>* s1, stack<int>* s2, int e)
{
    if (s1->size() == STACK_SIZE)
        delquene(s1, s2);
    s1->push(e);
}

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(3);
    test.push_back(3);
    test.push_back(4);
    cout << binarySearch(test, 2) << endl;
    cout << binarySearch(test, 3) << endl;
    test.clear();
    test.push_back(9);
    test.push_back(10);
    test.push_back(11);
    test.push_back(1);
    cout << binarySearch1(test, 2) << endl;

    stack<int> s1;
    stack<int> s2;
    enquene(&s1,&s2,1);
    enquene(&s1,&s2,2);
    enquene(&s1,&s2,3);
    cout << delquene(&s1,&s2) << endl;
    cout << delquene(&s1,&s2) << endl;
    return 0;
}
