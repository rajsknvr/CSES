/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define inc(x) (x).begin(), (x).end()
#define vi vector<ll>
#define infinity 1LL << 60
#define vvi vector<vector<ll>>
#define vpi vector<pair<ll, ll>>
#define pi pair<ll, ll>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
const ll mod = 1000000007LL;
int main()
{
    ll n;
    cin >> n;
    ll coins[5001];
    vector<vector<ll>> dp(5011, vi(5011, 0));
    for (int i = 1; i <= n; ++i)
        cin >> coins[i];
    for (int i = 1; i <= n; ++i)
    {

        for (int j = 1; j <= n; ++j)
        {
            if (i == 1)
            {
                dp[j][j] = coins[j];
                continue;
            }
            int begin = j;
            int end = j + i - 1;
            long choiceFirst = coins[begin] + (end == begin + 1 ? 0 : dp[end][begin + 1]);
            long choicSecond = coins[end] + (end - 1 == begin ? 0 : dp[end - 1][begin]);
            if (choiceFirst > choicSecond)
            {
                dp[begin][end] = choiceFirst;
                dp[end][begin] = dp[begin + 1][end];
            }
            else
            {
                dp[begin][end] = choicSecond;
                dp[end][begin] = dp[begin][end - 1];
            }
        }
    }
    cout << dp[1][n] << endl;
}