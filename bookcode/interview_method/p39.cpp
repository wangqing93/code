#include <iostream>
#include <string.h>

using namespace std;


void uppercase1(char str[]) {
    int test = sizeof(str);
    cout << test << endl;
}
int main()
{
    char str[] = "adslhs";
    cout << sizeof(str)/sizeof(str[0]) << endl;  //7
    cout << strlen(str) << endl;   //6
    uppercase1(str); //4
    return 0;
}
