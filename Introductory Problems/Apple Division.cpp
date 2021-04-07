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
long long minValue = LLONG_MAX;
void travel(long long sum, long long total, vector<long long> &apples, int index, int n)
{
    if (index == n)
        return;
    long long include = sum + apples[index];
    minValue = min(minValue, abs(total - 2 * include));
    travel(include, total, apples, index + 1, n);
    travel(sum, total, apples, index + 1, n);
}

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    vector<long long> apples(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> apples[i];
        sum += apples[i];
    }
    travel(0, sum, apples, 0, n);
    cout << minValue << endl;
}