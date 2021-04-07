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
ll dp[501][501] = {0};
ll travel(ll a, ll b)
{
    if (a == b)
        return 0;
    if (dp[a][b])
        return dp[a][b];
    ll ans = LLONG_MAX;
    for (int i = 1; i < b; ++i)
    {
        ans = min(1 + travel(a, b - i) + travel(a, i), ans);
    }
    for (int i = 1; i < a; ++i)
    {
        ans = min(ans, 1 + travel(i, b) + travel(a - i, b));
    }
    dp[a][b] = ans;
    dp[b][a] = ans;
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;

    cout << travel(a, b) << endl;
}