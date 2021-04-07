/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> graph[200001];
int height[200001];
int ans[200001];
void calHeight(int current, int parent)
{
    height[current] = 0;
    if (graph[current].size() == 1)
        return;
    for (int child : graph[current])
    {
        if (child != parent)
        {
            calHeight(child, current);
            height[current] = max(height[current], 1 + height[child]);
        }
    }
}
void travel(int current, int parent, int without)
{
    ans[current] = max(height[current], 1 + without);
    if (graph[current].size() == 1)
        return;
    vector<int> prefix;
    vector<int> suffix;
    for (int child : graph[current])
    {
        if (child != parent)
        {
            prefix.push_back(height[child] + 1);
            suffix.push_back(height[child] + 1);
        }
    }
    int size = prefix.size();
    for (int i = 1; i < size; ++i)
    {
        prefix[i] = max(prefix[i - 1], prefix[i]);
        suffix[size - i - 1] = max(suffix[size - i - 1], suffix[size - i]);
    }

    int childNo = 0;
    for (int child : graph[current])
    {
        if (child != parent)
        {
            int pre = childNo == 0 ? 0 : prefix[childNo - 1];
            int suff = childNo == size - 1 ? 0 : suffix[childNo + 1];
            int withoutChild = max(1 + without, max(pre, suff));
            travel(child, current, withoutChild);
            childNo += 1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    graph[1].push_back(0);
    height[0] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    calHeight(1, 0);
    travel(1, 0, -1);
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
            cout << " ";
        cout << ans[i + 1];
    }
}