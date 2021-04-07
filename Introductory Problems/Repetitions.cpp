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
    string st;
    cin >> st;
    int size = st.size();
    int maxVal = 1;
    int count = 1;
    for (int i = 1; i < size; ++i)
    {
        if (st[i] == st[i - 1])
        {
            count += 1;
            maxVal = max(maxVal, count);
        }
        else
        {
            count = 1;
        }
    }
    cout << maxVal << endl;
}