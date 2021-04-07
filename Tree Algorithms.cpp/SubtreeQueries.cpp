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
vi graph[200001];
vi weight(200001);
vi arr(400002);
vi start(200001);
vi term(200001);
int val = ceil(log2(400002));
const int stSize = 2 * (1 << val);
vi st(stSize);
ll timer = 1;
void travel(ll current, ll parent);

long getSumRecursion(int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = (ss + se) / 2;
    return getSumRecursion(ss, mid, qs, qe, 2 * index + 1) + getSumRecursion(mid + 1, se, qs, qe, 2 * index + 2);
}

long getSum(int n, int qs, int qe)
{
    return getSumRecursion(1, n, qs, qe, 0);
}

ll constructSTRecur(int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = weight[arr[ss]];
        return weight[arr[ss]];
    }
    int mid = (ss + se) / 2;
    st[si] = constructSTRecur(ss, mid, si * 2 + 1) +
             constructSTRecur(mid + 1, se, si * 2 + 2);
    return st[si];
}
void constructST(int n)
{
    constructSTRecur(1, n, 0);
}

// To update values

void updateValueRecur(int ss, int se, int i, ll diff, int si)
{
    if (i < ss || i > se)
        return;

    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = (ss + se) / 2;
        updateValueRecur(ss, mid, i, diff, 2 * si + 1);
        updateValueRecur(mid + 1, se, i, diff, 2 * si + 2);
    }
}

void updateValue(int n, int i, int newVal)
{
    ll diff = newVal - weight[arr[i]];

    updateValueRecur(1, n, i, diff, 0);
}

int main()
{
    fast_io;
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
    {
        cin >> weight[i];
    }
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    travel(1, 0);
    constructST(2 * n);
    int m = 2 * n;

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int s, x;
            cin >> s >> x;
            int l = start[s];
            int r = term[s];
            updateValue(2 * n, l, x);
            updateValue(2 * n, r, x);
            weight[s] = x;
        }
        else
        {
            int s;
            cin >> s;
            int l = start[s];
            int r = term[s];

            ll sum = getSum(2 * n, l, r);
            cout << sum / 2 << endl;
        }
    }
}

void travel(ll current, ll parent)
{
    arr[timer] = current;
    start[current] = timer;
    for (int child : graph[current])
    {
        if (child != parent)
        {
            ++timer;
            travel(child, current);
        }
    }
    ++timer;
    arr[timer] = current;
    term[current] = timer;
}