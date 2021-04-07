/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define inc(x) (x).begin(), (x).end()
const ll mod = 1000000007LL;

vvi points;
vi dp(200001, 0);
ll binary(ll l, ll r, ll value)
{
    if (l >= r)
        return l;
    ll mid = (l + r) / 2;
    if (points[mid][0] == value)
        return mid;
    if (points[mid][0] < value)
        return binary(mid + 1, r, value);
    return binary(l, mid - 1, value);
}
ll travel(ll x)
{

    if (x < 0LL)
        return 0LL;
    if (dp[x])
    {

        return dp[x];
    }

    ll without = travel(x - 1);
    ll index = binary(0, x, points[x][1] - 1);
    if (points[index][0] >= points[x][1])
        --index;
    ll with = points[x][2] + travel(index);
    dp[x] = max(with, without);
    return dp[x];
}
int main()
{
    fast_io;
    ll n, i;
    cin >> n;

    for (i = 0; i < n; ++i)
    {
        ll a, b, p;
        cin >> a >> b >> p;
        points.push_back({b, a, p});
    }
    sort(inc(points));
    cout << travel(n - 1) << endl;
}