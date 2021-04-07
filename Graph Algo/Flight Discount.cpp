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
#define iPair pair<ll, pair<int, int>>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
const ll mod = 1000000007LL;
struct Node
{
    ll cost;
    int source;
    bool coupon;
};
class comprator
{
public:
    bool operator()(Node a, Node b)
    {
        return a.cost < b.cost;
    }
};
vector<ll> costWithoutCoupon;
vector<ll> costWithCoupon;
vector<vector<pair<int, int>>> graph;
priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

void dijkestra(int source)
{
    pq.push({0, {source, true}});
    costWithCoupon[1] = 0;
    costWithoutCoupon[1] = 0;
    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();
        if (current.second.second)
        {
            if (costWithoutCoupon[current.second.first] < current.first)
                continue;
        }
        else
        {
            if (costWithCoupon[current.second.first] < current.first)
                continue;
        }

        for (auto child : graph[current.second.first])
        {

            if (current.second.second)
            {
                if (costWithCoupon[child.first] > current.first + child.second / 2)
                {
                    iPair newNode = {current.first + child.second / 2, {child.first, false}};
                    costWithCoupon[child.first] = newNode.first;
                    pq.push(newNode);
                }
                if (costWithoutCoupon[child.first] > current.first + child.second)
                {
                    iPair newNode = {current.first + child.second, {child.first, true}};
                    costWithoutCoupon[child.first] = newNode.first;
                    pq.push(newNode);
                }
            }
            else
            {
                if (costWithCoupon[child.first] > current.first + child.second)
                {
                    iPair newNode = {current.first + child.second, {child.first, false}};
                    costWithCoupon[child.first] = newNode.first;
                    pq.push(newNode);
                }
            }
        }
    }
}
int main()
{
    fast_io;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    costWithoutCoupon.resize(n + 1);
    costWithCoupon.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        costWithCoupon[i] = infinity, costWithoutCoupon[i] = infinity;
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    dijkestra(1);
    ll res = min(costWithCoupon[n], costWithoutCoupon[n]);
    cout << res << endl;
}