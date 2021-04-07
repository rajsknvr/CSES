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
    long long previous;
    cin >> previous;
    long long count = 0;
    for (int i = 1; i < n; ++i)
    {
        long long current;
        cin >> current;
        if (current < previous)
        {
            count += (previous - current);
        }
        else
        {
            previous = current;
        }
    }
    cout << count << endl;
}