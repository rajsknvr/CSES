/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n + 1, 0);
    vector<int> pages(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> price[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> pages[i];
    }
    int dp[1001][100001];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= x; ++j)
        {
            if (price[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                int diff = j - price[i];
                dp[i][j] = max(pages[i] + dp[i - 1][diff], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][x];
}