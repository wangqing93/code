#include <iostream>

using namespace std;

int main()
{
    int a = 1; int b = 2; int *a1 = &a;
    cout <<a1[0] << endl;
    a = 3;
    cout <<a1[0] << endl;
    *a1 = b;   //1 2 2
    cout <<a1[0] << endl;
    b = 4;
    cout <<a1[0] << endl;
    cout << "Hello world!" << endl;
    return 0;
}
