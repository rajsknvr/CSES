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

int main()
{
    int n, x;
    cin >> n >> x;
    memset(dp, 0, sizeof(dp));
    memset(coins, 0, sizeof(coins));
    for (int i = 1; i <= n; ++i)
        cin >> coins[i];
    for (int i = 1; i <= x; ++i)
    {
        dp[0][i] = INT_MAX;
    }
    sort(coins + 1, coins + n + 1);

    for (int coin = 1; coin <= n; ++coin)
    {
        for (int sum = 0; sum <= x; ++sum)
        {
            if (coins[coin] > sum)
            {
                dp[coin][sum] = dp[coin - 1][sum];
            }
            else
            {
                long diff = sum - coins[coin];
                if (dp[coin][diff] != INT_MAX)
                {
                    dp[coin][sum] = min(1 + dp[coin][diff], dp[coin - 1][sum]);
                }
                else
                    dp[coin][sum] = dp[coin - 1][sum];
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= n; ++i)
    {
        ans = min(dp[i][x], ans);
    }
    ans == INT_MAX ? cout << -1 : cout << ans;
}