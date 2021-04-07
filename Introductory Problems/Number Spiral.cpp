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
    long long t;
    cin >> t;
    while (t--)
    {
        long long row, col;
        cin >> row >> col;
        if (row == 1LL && col == 1LL)
        {
            cout << 1LL << endl;
            continue;
        }
        if (row >= col)
        {
            long long base = 0LL;
            if (row % 2LL == 0LL)
            {
                base = row * row;
                base -= col - 1LL;
            }
            else
            {
                base = (row - 1) * (row - 1) + 1LL;
                base += col - 1LL;
            }
            cout << base << endl;
        }
        else
        {
            swap(row, col);
            long long base = 0LL;
            if (row % 2LL == 0)
            {
                base = row * row;
                base -= 2LL * row - 1LL - col;
            }
            else
            {
                base = (row - 1) * (row - 1) + 1LL;
                base += 2LL * row - 1LL - col;
            }
            cout << base << endl;
        }
    }
}