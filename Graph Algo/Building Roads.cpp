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
vector<int> graph[100001];
vector<bool> visited(100001, false);
void dfs(int current, int parent)
{
    if (visited[current])
        return;
    visited[current] = true;
    for (int child : graph[current])
    {
        if (child != parent)
        {
            dfs(child, current);
        }
    }
}
int main()
{
    fast_io;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> isolatedNodes;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            isolatedNodes.push_back(i);
            dfs(i, 0);
        }
    }
    int size = isolatedNodes.size();
    cout << (size > 1 ? size - 1 : 0) << endl;
    for (int i = 1; i < size; ++i)
    {
        cout << isolatedNodes[i - 1] << " " << isolatedNodes[i] << endl;
    }
}