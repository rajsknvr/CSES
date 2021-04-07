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
int N, M;
char grid[1000][1000];
bool isValid(int i, int j)
{
    if (i < N && i >= 0 && j < M && j >= 0 && grid[i][j] == '.')
    {
        return true;
    }
    return false;
}
void travel(int i, int j)
{
    if (!isValid(i, j))
        return;
    grid[i][j] = '#';
    travel(i, j + 1);
    travel(i + 1, j);
    travel(i - 1, j);
    travel(i, j - 1);
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    N = n;
    M = m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '.')
            {
                count += 1;
                travel(i, j);
            }
        }
    cout << count << endl;
}