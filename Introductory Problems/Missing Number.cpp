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
    long long n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int temp;
        cin >> temp;
        sum += temp;
    }
    cout << ((n * (n + 1)) / 2 - sum) << endl;
}