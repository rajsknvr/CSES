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
vector<int> visited(100001, 0);
vector<int> ans;
bool found = false;
int dfs(int current, int parent)
{
    if (visited[current] == 1)
    {
        visited[current] = 2;
        found = true;
        return current;
    }
    if (visited[current] == -1)
        return -1;
    visited[current] = 1;
    for (int child : graph[current])
    {
        if (child == parent)
            continue;
        int node = dfs(child, current);
        if (node > 0)
        {
            if (visited[current] == 2)
            {
                ans.push_back(node);
                ans.push_back(current);
                return 0;
            }
            else
            {
                ans.push_back(node);
                return current;
            }
        }
        else if (node == 0)
            return 0;
    }
    visited[current] = -1;
    return -1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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

    for (int i = 1; i <= n; ++i)
    {

        if (found)
            break;
        if (visited[i] == 0)
        {
            dfs(i, 0);
        }
    }
    if (!found)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; --i)
    {
        cout << ans[i] << (i != 0 ? " " : "\n");
    }
}