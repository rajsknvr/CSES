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
long long modPow(long base, long exp)
{
    long long ans = 1;
    while (exp > 1)
    {
        if (exp & 1)
        {
            ans = (ans * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    ans = (ans * base) % mod;
    return ans;
}
int main()
{
    long long n;
    cin >> n;
    cout << modPow(2, n) << endl;
}