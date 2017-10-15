#include <iostream>

using namespace std;

int getFirst(long long x) {
    if ( 0<=x && x<=9)
        return x;
    return getFirst(x/10);
}
int main()
{
    int a, b;
    cin >> a >> b;
    int n = 0;
    long long t = 1;
    int res;
    bool flag = false;
    while (n<=64) {
        if (getFirst(t)==a && t%10==b)
        {
            flag = true;
            break;
        }
        n++;
        t <<= 1;
    }
    if (flag == true)
        cout << n << endl;
    else
        cout << "-1" << endl;
    return 0;
}
