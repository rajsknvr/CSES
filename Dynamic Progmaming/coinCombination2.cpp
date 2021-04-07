/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
int dp[101][1000001];
int coins[101];
const long mod = 1000000007;
int main()
{
    int n, x;
    cin >> n >> x;
    memset(dp, 0, sizeof(dp));
    memset(coins, 0, sizeof(coins));
    for (int i = 1; i <= n; ++i)
        cin >> coins[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= x; ++j)
        {
            if (coins[i] - j > 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                long diff = j - coins[i];
                long temp = ((long)dp[i - 1][j] + (long)dp[i][diff]) % mod;
                dp[i][j] = (int)temp;
            }
        }
    }
    cout << dp[n][x];
}