#include <iostream>

using namespace std;

//https://hihocoder.com/problemset/problem/1599?sid=1201410
bool findpath(int x, int y, int a, int b)
{
    if (a == x && b == y)
        return true;
    if (a < x || b < y)
        return false;
    if (a <= b)
    {
        return findpath(x, y, a, b%a) || (x == a && !(b%a));
    } else
    {
        return findpath(x, y, a%b, b) || ( y == b && !(a%b));
    }
}
int main()
{
    int nums;
    cin >> nums;
    int x, y, a, b;
    for (int i = 0; i < nums; i++)
    {
        cin >> x >> y >> a >> b;
        if (findpath(x,y,a,b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
