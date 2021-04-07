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
pair<int, vector<int>> graph[200001];
vector<int> ans(200001, 0);
int maxUp = log2(200001);
vector<vector<int>> sparse(200001, vector<int>(maxUp + 1, -1));
void fillSparseTable(int n)
{
    for (int i = 1; i <= maxUp; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int prevParent = sparse[j][i - 1];
            if (prevParent == -1)
                continue;
            sparse[j][i] = sparse[prevParent][i - 1];
        }
    }
}
void fillHeight(int current, int parent)
{
    sparse[current][0] = parent;
    graph[current].first = graph[parent].first + 1;
    for (int child : graph[current].second)
    {
        if (child != parent)
        {
            fillHeight(child, current);
        }
    }
}
int getLCA(int a, int b)
{
    if (graph[a].first < graph[b].first)
        swap(a, b);
    int diff = graph[a].first - graph[b].first;
    while (diff > 0)
    {
        int i = log2(diff);
        diff -= (1 << i);
        a = sparse[a][i];
    }
    if (a == b)
        return a;
    for (int i = maxUp; i >= 0; --i)
    {
        if (sparse[a][i] == sparse[b][i])
            continue;
        a = sparse[a][i];
        b = sparse[b][i];
    }
    return sparse[a][0];
}
int subTreeSum(int current, int parent)
{
    int total = 0;
    for (int child : graph[current].second)
    {
        if (child != parent)
        {
            total += subTreeSum(child, current);
        }
    }
    ans[current] += total;
    return ans[current];
}
int main()
{
    fast_io;
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].second.push_back(b);
        graph[b].second.push_back(a);
    }
    graph[0].first = -1;
    fillHeight(1, 0);
    sparse[1][0] = -1;
    fillSparseTable(n);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int lca = getLCA(a, b);
        ans[a] += 1;
        ans[b] += 1;
        ans[lca] -= 1;
        int lcaParent = sparse[lca][0];
        if (lcaParent != -1)
            ans[lcaParent] -= 1;
    }
    ans[1] = subTreeSum(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (i != 1)
            cout << " ";
        cout << ans[i];
    }
    return 0;
}