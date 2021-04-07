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

void makeDiagonalZero(vvi &grid, int n)
{
    for (int i = 1; i <= n; ++i)
        grid[i][i] = 0;
}
void copyCurrentRowCol(vvi &previous, vvi &current, int n, int index)
{
    for (int j = 1; j <= n; ++j)
    {
        current[index][j] = previous[index][j];
        current[j][index] = previous[j][index];
    }
}
int main()
{
    fast_io;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    vvi previous(n + 1, vi(n + 1, infinity));
    makeDiagonalZero(previous, n);
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (previous[a][b] > c)
        {
            previous[a][b] = c;
            previous[b][a] = c;
        }
    }
    vvi current(n + 1, vi(n + 1, infinity));
    for (int i = 1; i <= n; ++i)
    {
        for (int a = 1; a <= n; ++a)
        {
            for (int b = 1; b <= n; ++b)
            {
                current[a][b] = infinity;
            }
        }
        makeDiagonalZero(current, n);
        copyCurrentRowCol(previous, current, n, i);

        for (int j = 1; j <= n; ++j)
        {
            if (j == i)
                continue;
            for (int k = 1; k <= n; ++k)
            {
                if (j == k || k == i)
                    continue;
                current[j][k] = min(previous[j][k], previous[j][i] + previous[i][k]);
            }
        }
        previous = current;
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (previous[a][b] >= infinity ? -1 : previous[a][b]) << endl;
    }
}