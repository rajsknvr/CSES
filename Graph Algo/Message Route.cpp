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

    queue<int> nodes;
    vector<int> parent(100001, 0);
    visited[1] = true;
    nodes.push(1);
    nodes.push(0);
    parent[1] = 0;
    while (nodes.size() > 1)
    {
        int top = nodes.front();
        if (top == 0)
        {
            nodes.pop();
            nodes.push(0);
            top = nodes.front();
        }
        for (int child : graph[top])
        {
            if (child != parent[top] && !visited[child])
            {
                visited[child] = true;
                parent[child] = top;
                nodes.push(child);
                if (child == n)
                    break;
            }
        }
        nodes.pop();
    }
    if (!parent[n])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    stack<int> ans;
    int index = n;

    while (index)
    {
        ans.push(index);
        index = parent[index];
    }
    cout << ans.size() << endl;
    while (ans.size() > 0)
    {
        int top = ans.top();
        ans.pop();
        cout << top;
        if (ans.size() != 0)
            cout << " ";
    }
}
