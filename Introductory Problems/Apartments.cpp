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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> applicant(n);
    vector<ll> appartment(m);
    for (int i = 0; i < n; ++i)
        cin >> applicant[i];
    for (int i = 0; i < m; ++i)
        cin >> appartment[i];
    sort(appartment.begin(), appartment.end());
    sort(applicant.begin(), applicant.end());
    int count = 0;
    int i = 0, j = 0;
    while (true)
    {
        if (i == n || j == m)
            break;
        ll upperBound = applicant[i] + k;
        ll loweBound = applicant[i] - k;
        if (appartment[j] <= upperBound && appartment[j] >= loweBound)
        {
            count += 1;
            ++i, ++j;
        }
        else if (appartment[j] > upperBound)
            i += 1;
        else
        {
            j += 1;
        }
    }
    cout << count << endl;
}