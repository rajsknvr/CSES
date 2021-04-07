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

    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long minValue = min(a, b);
        long long maxValue = max(a, b);
        long long diff = 2 * minValue - maxValue;
        if (diff >= 0 && diff % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}