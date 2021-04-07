/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price;
    vector<int> pages;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        price.push_back(temp);
    }
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        pages.push_back(temp);
    }
    vector<pair<float, pair<int, int>>> data;
    for (int i = 0; i < n; ++i)
    {
        float ratio = (float)price[i] / (float)pages[i];
        data.push_back({ratio, {price[i], pages[i]}});
    }
    sort(data.begin(), data.end());
    for (int i = 1; i < n; ++i)
    {
        int temp = i;
        while (temp > 0 && data[temp].first == data[temp - 1].first && data[temp].second.second > data[temp - 1].second.second)
        {
            swap(data[i], data[i - 1]);
            --temp;
        }
    }
    int pageSum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (data[i].second.first <= x)
        {
            pageSum += data[i].second.second;
            x -= data[i].second.first;
        }
    }
    cout << pageSum;
}