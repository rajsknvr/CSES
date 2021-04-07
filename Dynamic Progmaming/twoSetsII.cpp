/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long modPow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long pro = 1;
    while (b > 1)
    {
        if (b & 1)
        {
            pro = (pro * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    pro = (pro * a) % mod;
    return pro;
}
int main()
{
    long long n;
    cin >> n;
    vector<vector<long long>> dp(501, vector<long long>(62627, 0));

    dp[0][0] = 1;

    long total = (n * (n + 1)) / 2;
    if (total % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    total /= 2;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = 0; j <= total; ++j)
        {
            if (i > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                long long diff = j - i;
                dp[i][j] = (long long)(((long long)dp[i - 1][j] + (long long)dp[i - 1][diff]) % mod);
            }
        }
    }
    long long ans = ((dp[n][total]) * (modPow(2, mod - 2))) % mod;
    cout << ans << endl;
}