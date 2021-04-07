/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inc(x) (x).begin(), (x).end()
#define vi vector<ll>
#define infinity 1LL << 60
#define pi pair<ll, ll>
#define vvi vector<vector<ll>>
#define vpi vector<pair<ll, ll>>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
const ll mod = 1000000007LL;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> data(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> data[i];
    }
    vvi dp(n + 2, vi(m + 2, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1)
            {
                if (data[i] == 0 || data[i] == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (data[i] == 0 || data[i] == j)
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= m; ++i)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << endl;
}