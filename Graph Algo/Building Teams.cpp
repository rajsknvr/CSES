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
void dfs(int current)
{
    for (int child : graph[current])
    {
        if (!visited[child])
        {
            if (visited[current] == 1)
                visited[child] = 2;
            else
                visited[child] = 1;
            dfs(child);
        }
        else
        {
            if (visited[child] == visited[current])
            {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
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

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << visited[i] << (i != n ? " " : "\n");
}