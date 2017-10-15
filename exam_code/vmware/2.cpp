#include <iostream>
#include <string>
#include <vector>

using namespace std;

int A[10]= {0};
int mlen;
long long maxdif;
long long ten;
long long a;
long long maxres;
vector<int> vres;

long long getDif(vector<int>& nums) {
    long long b = 0;
    for (int i = 0; i < nums.size(); i++) {
        b = b*10+nums[i];
    }
    return min(abs(a-b), ten-abs(a-b));
}

void dfs(int x, vector<int>& nums) {

    if (x == mlen) {
        /*for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;*/
        long long res = getDif(nums);
        if (res > maxres) {
            maxres = res;
            vres = nums;
            return;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (A[i] != 1) {
            A[i] = 1;
            nums.push_back(i);
            dfs(x+1, nums);
            nums.pop_back();
            A[i] = 0;
        }
    }
}



int main()
{
    string s;
    cin >> s;
    a = 0;
    int len = s.length();
    mlen = len;
    ten = 1;
    for (int i = 0; i < len; i++)
    {
        a = a*10+(s[i]-'0');
        ten = ten*10;
    }
    vector<int> temp;
    dfs(0, temp);
    for (int i = 0; i < vres.size(); i++)
        cout << vres[i];
    cout << endl;
    return 0;
}
