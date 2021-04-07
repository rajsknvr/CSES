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
#define pi pair<ll, int>
#define vvi vector<vector<ll>>
#define vpi vector<pair<ll, ll>>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
const ll mod = 1000000007LL;
vector<pair<int, int>> graph[100001];
vector<int> parent(100001);
vector<ll> dist(100001, infinity);
vector<bool> visited(100001, false);
void solve(int n, int source)
{
    parent[source] = 0, dist[source] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, source});

    while (pq.size() > 0)
    {
        auto current = pq.top().second;
        pq.pop();
        for (auto child : graph[current])
        {
            int node = child.first;
            int weight = child.second;
            if (dist[node] > dist[current] + weight)
            {
                dist[node] = dist[current] + weight;
                parent[node] = current;
            }
            if (!visited[node])
            {
                pq.push({dist[node], node});
                visited[node] = true;
            }
        }
    }
}
int main()
{
    fast_io;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int noOfVertices, noOfEgdes;
    cin >> noOfVertices >> noOfEgdes;
    for (int i = 0; i < noOfEgdes; ++i)
    {
        int u, v;
        ll weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        //graph[v].push_back({u, weight});
    }
    solve(noOfVertices, 1);
    for (int i = 1; i <= noOfVertices; ++i)
    {
        cout << dist[i] << (i != noOfVertices ? " " : "\n");
    }
}