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
    vector<int> data(n);
    for (int i = 0; i < n; ++i)
        cin >> data[i];
    sort(data.begin(), data.end());
    int count = 1;
    for (int i = 1; i < n; ++i)
    {
        if (data[i] != data[i - 1])
            count += 1;
    }
    cout << count << endl;
}