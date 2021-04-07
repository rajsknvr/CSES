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
vector<vector<bool>> grid(7, vector<bool>(7, false));
bool isSafe(int i, int j, int length)
{
    if (i >= 0 && i < 7 && j >= 0 && j < 7 && length <= 48)
        return true;
    return false;
}
int ans = 0;
string path = "";
void travel(int i, int j, int length)
{
    if (!isSafe(i, j, length))
        return;
    if (grid[i][j])
        return;
    if (i == 6 && j == 0 && length == 48)
    {
        ans += 1;
        cout << ans << endl;
        return;
    }
    if (i == 6 && j == 0)
        return;
    if (length == 48)
        return;
    grid[i][j] = true;
    if (path[length] == 'L' || path[length] == '?')
        travel(i, j - 1, length + 1);
    if (path[length] == 'R' || path[length] == '?')
        travel(i, j + 1, length + 1);
    if (path[length] == 'U' || path[length] == '?')
        travel(i - 1, j, length + 1);
    if (path[length] == 'D' || path[length] == '?')
        travel(i + 1, j, length + 1);
    grid[i][j] = false;
}
int main()
{
    string st;
    cin >> st;
    path = st;
    travel(0, 0, 0);
    cout << ans << endl;
}