/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
char grid[1000][1000];
bool visited[1000][1000];
int ans[1000][10000];
int N;
const long mod = 1000000007;
bool isSafe(int i, int j)
{
    if (i >= 0 && i < N && j >= 0 && j < N && grid[i][j] != '*')
        return true;
    return false;
}
int travel(int i, int j)
{
    if (!isSafe(i, j))
        return 0;
    if (visited[i][j])
        return ans[i][j];
    if (i == j && i == N - 1)
        return 1;

    int right = 0;
    if (isSafe(i, j + 1))
    {
        right = travel(i, j + 1);
    }
    int down = 0;
    if (isSafe(i + 1, j))
    {
        down = travel(i + 1, j);
    }
    long total = ((long)right + (long)down) % mod;
    ans[i][j] = (int)total;
    visited[i][j] = 1;
    return ans[i][j];
}

int main()
{
    int n;
    cin >> n;
    N = n;

    memset(ans, 0, sizeof(ans));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
    }
    cout << travel(0, 0);
}