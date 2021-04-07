/*
    Author:@rajsknvr
*/
#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
const long long mod = 1000000007LL;
vector<int> weight(200001);
vector<int> inTime(200001);
vector<int> outTime(200001);
vector<int> graph[200001];
int timer = 1;
void dfs(int current, int parent)
{
    inTime[current] = timer;
    timer += 1;
    for (int child : graph[current])
    {
        if (child != parent)
        {
            dfs(child, current);
        }
    }
    outTime[current] = timer - 1;
}
class BinaryIndexedTree
{
private:
    vector<long long> bit;
    int size;

public:
    BinaryIndexedTree(int n) : bit(n + 1, 0), size(n + 1) {} //initilize variables;
    void update(int pos, long long difference);
    long long query(int pos);
};
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> weight[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    BinaryIndexedTree BIT(n);
    for (int i = 1; i <= n; ++i)
    {
        BIT.update(inTime[i], weight[i]);
        BIT.update(outTime[i] + 1, -weight[i]);
    }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int position, newValue;
            cin >> position >> newValue;
            long long difference = newValue - weight[position];
            weight[position] = newValue;

            BIT.update(inTime[position], difference);
            BIT.update(outTime[position] + 1, -difference);
        }
        else
        {
            int position;
            cin >> position;
            cout << BIT.query(inTime[position]) << endl;
        }
    }
    return 0;
}

void BinaryIndexedTree::update(int pos, long long difference)
{
    int size = this->size;
    for (; pos < size; pos += (pos & -pos))
    {
        this->bit[pos] += difference;
    }
}
long long BinaryIndexedTree::query(int pos)
{
    long long ans = 0;
    for (; pos > 0; pos -= (pos & -pos))
    {
        ans += this->bit[pos];
    }
    return ans;
}