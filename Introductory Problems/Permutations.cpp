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
    if (n == 1)
        cout << 1 << endl;
    else if (n <= 3)
        cout << "NO SOLUTION" << endl;
    else if (n == 4)
        cout << "3 1 4 2" << endl;
    else
    {
        int even = n / 2;
        int odd;
        if (n % 2 == 0)
        {
            odd = n / 2;
        }
        else
        {
            odd = (n + 1) / 2;
        }
        for (int i = 1; i <= odd; ++i)
            cout << 2 * i - 1 << " ";
        for (int i = 1; i <= even; ++i)
        {
            cout << i * 2;
            if (i != even)
                cout << " ";
        }
    }
}