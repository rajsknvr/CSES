/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
pair<int, vector<int>> graph[200001];
int height[200001];
int maxUp = log2(200001);
vector<vector<int>> sparse(200001, vector<int>(maxUp + 1, -1));
int getBoss(int current, int k)
{

    if (current == -1)
        return -1;
    if (k == 0)
        return current;
    int i = log2(k);
    return getBoss(sparse[current][i], k - (1 << i));
}
void travel(int current, int h)
{
    height[current] = h;
    if (graph[current].second.size() == 0)
        return;
    for (int child : graph[current].second)
    {
        travel(child, h + 1);
    }
}
void fillSparseTable(int n)
{
    for (int i = 1; i <= maxUp; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int previParent = sparse[j][i - 1];
            if (previParent == -1)
                continue;

            sparse[j][i] = sparse[previParent][i - 1];
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; ++i)
    {
        int boss;
        cin >> boss;
        graph[boss].second.push_back(i);
        graph[i].first = boss;
        sparse[i][0] = boss;
    }

    travel(1, 0);
    fillSparseTable(n);
    // for (int i = 1; i <= 10; ++i)
    // {
    //     cout << i << "->";
    //     for (int j = 0; j < 5; ++j)
    //     {
    //         cout << sparse[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        // if (height[x] < k)
        //     cout << -1 << endl;
        // else if (height[x] == k)
        //     cout << 1 << endl;
        // else
        cout << getBoss(x, k) << endl;
    }
}