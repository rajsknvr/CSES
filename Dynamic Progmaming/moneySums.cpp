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
#define vvi vector<vector<ll>>
#define vpi vector<pair<ll, ll>>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
const ll mod = 1000000007LL;
int coins[101] = {0};
int dp[101][100001] = {0};
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> coins[i];
        sum += coins[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= sum; ++j)
        {
            if (coins[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                int diff = j - coins[i];
                dp[i][j] = dp[i - 1][j] + dp[i - 1][diff];
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= sum; ++i)
    {
        if (dp[n][i])
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        if (i != 0)
            cout << " ";
        cout << ans[i];
    }
}