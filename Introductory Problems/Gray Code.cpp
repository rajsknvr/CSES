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
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); ++i)
    {
        int value = i ^ (i >> 1);
        for (int j = n - 1; j >= 0; --j)
        {
            cout << (value & (1 << j) ? 1 : 0);
        }
        cout << endl;
    }
}