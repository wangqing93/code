#include <iostream>

using namespace std;
bool judgeChar(char x)
{
    if (x >= 'a' && x <= 'z')
        return true;
    else if (x >= 'A' && x <= 'Z')
        return true;
    return false;
}

int main()
{
    char str[805];
    cin.getline(str, 805);
    string s(str), temp;
    for (int i = 0, j; i < s.length(); ++i)
    {
        if (s[i] == '@')
        {
            temp = "";
            for (j = i+1; j < s.length(); ++j)
            {
                if (judgeChar(s[j]))
                    temp+=s[j];
                else
                    break;
            }
            if (temp != "")
                cout << temp << " ";
            i = j-1;
        }
    }
    return 0;
}
