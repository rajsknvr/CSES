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
long long getValue(long long i)
{
    return i * (long long)pow(10, i) - ((long long)pow(10, i) - 1) / 9;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long val = 0;
        long long term = 1;
        for (long long i = 1; i <= 17; ++i)
        {
            long long newVal = getValue(i);
            term = i;
            val = newVal;
            if (newVal >= n)
            {
                break;
            }
            if (i == 17 && newVal < n)
                ++term;
        }

        long long prevVal = getValue(term - 1);
        long long remaining = n - prevVal;

        long long numberPos = (long long)ceil((long double)remaining / (long double)term);
        long long digitPos = remaining % term;
        long long base = (long long)pow(10, term - 1);
        base = base + numberPos - 1LL;
        long long ans = 0;
        if (digitPos == 0)
        {
            ans = base % 10;
        }
        else
        {
            long long loop = term - digitPos;
            for (int i = 0; i < loop; ++i)
                base /= 10;
            ans = base % 10;
        }
        cout << ans << endl;
    }
}