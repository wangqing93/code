#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> datas;
    MyStack() {
        while(datas.size() > 0)
            datas.pop();
    }

    /** Push element x onto stack. */
    void push(int x) {
        datas.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (datas.size() == 0)
            return -1;
        queue<int> mid;
        while(datas.size() > 1)
        {
            int x = datas.front();
            mid.push(x);
            datas.pop();
        }
        int delete_e = datas.front();
        datas.pop();
        while(mid.size() > 0)
        {
            datas.push(mid.front());
            mid.pop();
        }
        return delete_e;
    }

    /** Get the top element. */
    int top() {
        if (datas.size() == 0)
            return -1;
        queue<int> mid;
        while(datas.size() > 1)
        {
            int x = datas.front();
            mid.push(x);
            datas.pop();
        }
        int delete_e = datas.front();
        mid.push(delete_e);
        datas.pop();
        while(mid.size() > 0)
        {
            datas.push(mid.front());
            mid.pop();
        }
        return delete_e;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        if (datas.size() > 0)
            return false;
        return true;
    }
};

int main()
{

    return 0;
}
