/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> graph[200001];
int dp[200001][2];

void travel(int current, int parent)
{
    dp[current][0] = 0;
    dp[current][1] = 0;
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
    vector<pair<int, int>> allChildValue;
    for (int child : graph[current])
    {
        if (child != parent)
        {
            allChildValue.push_back({max(dp[child][0], dp[child][1]), child});
        }
    }
    int allChildSum = 0;
    for (auto val : allChildValue)
        allChildSum += val.first;
    dp[current][0] = allChildSum;
    for (int i = 0; i < allChildValue.size(); ++i)
    {
        dp[current][1] = max(dp[current][1], 1 + allChildSum - allChildValue[i].first + dp[allChildValue[i].second][0]);
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
    travel(1, 0);
    int ans = max(dp[1][0], dp[1][1]);
    cout << ans;
}