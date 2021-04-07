/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 1000000007;
int main()
{
    int t;
    vector<vector<int>> dp(1000000, vector<int>(2, 0));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < 1000000; ++i)
    {
        ll tempZero = ((ll)dp[i - 1][0] * 4 + (ll)dp[i - 1][1]) % mod;
        ll tempOne = ((ll)dp[i - 1][1] * 2 + (ll)dp[i - 1][0]) % mod;
        dp[i][0] = (int)tempZero;
        dp[i][1] = (int)tempOne;
    }
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        long ans = ((long)dp[n - 1][1] + (long)dp[n - 1][0]) % mod;
        cout << ans << endl;
    }

    return 0;
}