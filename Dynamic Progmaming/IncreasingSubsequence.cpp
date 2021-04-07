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
int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i)
        cin >> data[i];
    map<int, int> prefix;

    prefix.insert({data[0], 1});
    for (int i = 1; i < n; ++i)
    {
        auto it = prefix.lower_bound(data[i]);
        if (it == prefix.end())
        {
            prefix.insert({data[i], (--it)->second + 1});
            continue;
        }
        if (it != prefix.begin())
        {
            if (it->first > data[i])
            {
                --it;
                int length = it->second + 1;
                ++it;
                if (it->second == length)
                {
                    prefix.erase(it);
                }
                prefix.insert({data[i], length});
            }
            // else if (it->first < data[i])
            // {
            //     prefix.insert({data[i], it->second + 1});
            // }
        }
        else
        {
            if (it->first != data[i])
            {
                if (it->second == 1)
                    prefix.erase(it);
                prefix.insert({data[i], 1});
            }
        }
    }
    auto it = prefix.end();
    --it;
    cout << it->second << endl;
    // for (it = prefix.begin(); it != prefix.end(); ++it)
    // {
    //     cout << it->first << "->" << it->second << endl;
    // }
}