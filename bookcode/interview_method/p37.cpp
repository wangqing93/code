#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char strs[100] = "daoaudafsfsf";
    cout << strlen(strs) <<endl;  //12
    cout << sizeof strs << endl;  //100
    char a[] = "aBcDe";
    cout << strlen(a) <<endl;  //5
    cout << sizeof a << endl;  //6
    cout << "Hello world!" << endl;
    return 0;
}
