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
struct Edge
{
    int a, b, c;
};
int main()
{
    fast_io;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, long long>> nodes(n + 1, {0, infinity});
    nodes[1].second = 0;
    vector<Edge> edges;
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, -1 * c});
    }
    for (int i = 1; i < 2 * n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            Edge current = edges[j];
            int a = current.a, b = current.b, c = current.c;
            if (nodes[a].second == infinity)
                continue;
            if (i >= n)
            {
                if (nodes[b].second > nodes[a].second + c)
                    nodes[b].second = -1 * infinity;
            }
            else
            {

                if (nodes[b].second > nodes[a].second + c)
                    nodes[b].second = nodes[a].second + c;
            }
        }
    }
    if (nodes[n].second == -1 * infinity)
        cout << -1 << endl;
    else
        cout << -1 * nodes[n].second << endl;
}