/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
long long dp[1000001];
int visited[1000001];
const long long mod = 1000000007;
long travel(int n)
{
    if (n < 0)
        return 0;
    if (dp[n])
        return dp[n];
    long long sum = 0;
    for (int i = 6; i >= 1; --i)
    {
        if (n - i >= 0)
        {
            if (visited[n - i])
            {

                sum += dp[n - i];
            }
            else
            {
                visited[n - i] = 1;
                sum += travel(n - i);
            }
        }
    }
    sum = sum % mod;
    dp[n] = sum;
    return sum;
}
int main()
{
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(visited, 0, sizeof(visited));
    dp[0] = 1;
    visited[0] = 1;
    cout << travel(n);
}