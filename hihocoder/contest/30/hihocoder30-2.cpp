#include <iostream>
#include <vector>


using namespace std;


int main()
{
    int n, t, max_p = 0, temp_p = 0;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        prices.push_back(t);
    }
    //
    int max_v = prices[n-1];
    int ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (max_v > prices[i])
        {
            ans += max_v - prices[i];
        }
        max_v = max(max_v, prices[i]);
    }
    cout << ans << endl;
    return 0;
}
