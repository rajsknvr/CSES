/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
long dp[1000001];
int coins[101];
const long mod = 1000000007;
int visited[1000001];
long travel(int x, int n)
{
    long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (x - coins[i] >= 0)
        {
            if (visited[x - coins[i]])
                sum += dp[x - coins[i]];
            else
            {
                visited[x - coins[i]] = 1;
                sum += travel(x - coins[i], n);
            }
        }
        else
        {
            break;
        }
    }
    sum = sum % mod;
    dp[x] = sum;
    return sum;
}
int main()
{
    int n, x;
    cin >> n >> x;
    memset(dp, 0, sizeof(dp));
    memset(coins, 0, sizeof(coins));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; ++i)
        cin >> coins[i];
    sort(coins, coins + n);
    dp[0] = 1;
    visited[0] = 1;
    cout << travel(x, n);
}