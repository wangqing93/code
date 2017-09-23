#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void changeVPoint(int* a)
{
    cout << a << endl;
    a++;
    cout << a << endl;
}

void changeV(int &a)
{
    cout << a << endl;
    a++;  
    cout << a << endl;
}
int main()
{
    int a = 1;
    changeV(a); //1 2

    a = 10;
    int* b = (int* )a;
    changeVPoint(b); //a e
    return 0;
}
