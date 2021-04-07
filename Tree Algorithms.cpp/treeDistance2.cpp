/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> graph[200001];
long dp[200001][2];
long ans[200001];
void getAllSum(int current, int parent)
{
    dp[current][0] = 0;
    dp[current][1] = 1;
    if (graph[current].size() == 1)
        return;
    for (int child : graph[current])
    {
        if (child != parent)
        {
            getAllSum(child, current);
            dp[current][0] += dp[child][0] + dp[child][1];
            dp[current][1] += dp[child][1];
        }
    }
}
void travel(int current, int parent)
{
    long sumOfParentWithoutMe = ans[parent] - dp[current][0] - dp[current][1];
    long childOfParentWithoutMe = dp[parent][1] - dp[current][1];
    ans[current] = dp[current][0] + sumOfParentWithoutMe + childOfParentWithoutMe;
    dp[current][1] += childOfParentWithoutMe;
    if (graph[current].size() == 1)
    {

        return;
    }
    for (int child : graph[current])
    {
        if (child != parent)
        {
            travel(child, current);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    graph[1].push_back(0);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    getAllSum(1, 0);
    dp[0][0] = dp[1][0];
    dp[0][1] = dp[1][1];
    ans[0] = dp[1][0] + dp[1][1];
    travel(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (i != 1)
            cout << " ";
        cout << ans[i];
    }
}