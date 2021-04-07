/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
int travel(vector<int> &ans, vector<int> arr[], int i)
{
    if (arr[i].size() == 0)
    {
        return 1;
    }
    int tempAns = 0;
    for (int j = 0; j < arr[i].size(); ++j)
    {
        tempAns += travel(ans, arr, arr[i][j]);
    }
    ans[i] = tempAns;
    return tempAns + 1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1, 0);
    vector<int> graph[n + 1];
    for (int i = 2; i <= n; ++i)
    {
        int temp;
        cin >> temp;
        graph[temp].push_back(i);
    }
    ans[1] = travel(ans, graph, 1) - 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i != 1)
            cout << " ";
        cout << ans[i];
    }
}