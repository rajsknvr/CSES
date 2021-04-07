/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
long dp[7][1000001];
const long mod = 1000000007;
int main()
{
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int coin = 1; coin < 7; ++coin)
    {
        for (int sum = 0; sum <= n; ++sum)
        {
            if (coin > sum)
            {
                dp[coin][sum] = dp[coin - 1][sum];
            }
            else
            {
                long diff = sum - coin;
                dp[coin][sum] = (dp[coin - 1][sum] + dp[coin][diff]) % mod;
            }
        }
    }
    cout << dp[6][n];
}