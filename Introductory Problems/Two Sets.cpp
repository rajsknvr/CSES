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
    long long sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        sum /= 2;
        vector<int> one;
        vector<int> two;
        long long temp = 0;
        for (int i = n; i >= 1; --i)
        {
            if (temp + i <= sum)
            {

                one.push_back(i);
                temp += i;
            }
            else
            {
                two.push_back(i);
            }
        }
        cout << one.size() << endl;
        for (int i = 0; i < one.size(); ++i)
        {
            if (i != 0)
                cout << " ";
            cout << one[i];
        }
        cout << endl
             << two.size() << endl;
        for (int i = 0; i < two.size(); ++i)
        {
            if (i != 0)
                cout << " ";
            cout << two[i];
        }
    }
}