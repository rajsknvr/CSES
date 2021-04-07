#include <bits/stdc++.h>
using namespace std;
#define MAX 524288

long tree[MAX] = {0};
long lazy[MAX] = {0};

void updateRangeRecur(long si, long ss, long se, long us, long ue, long diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se - ss + 1) * lazy[si];

        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > se || ss > ue || se < us)
        return;
    if (ss >= us && se <= ue)
    {
        tree[si] += (se - ss + 1) * diff;
        if (ss != se)
        {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }
    long mid = (ss + se) / 2;
    updateRangeRecur(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeRecur(si * 2 + 2, mid + 1, se, us, ue, diff);

    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}
void updateRange(long n, long us, long ue, long diff)
{
    updateRangeRecur(0, 0, n - 1, us, ue, diff);
}
long getSumRecur(long ss, long se, long qs, long qe, long si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > se || ss > qe || se < qs)
        return 0;
    if (ss >= qs && se <= qe)
        return tree[si];
    long mid = (ss + se) / 2;
    return getSumRecur(ss, mid, qs, qe, 2 * si + 1) +
           getSumRecur(mid + 1, se, qs, qe, 2 * si + 2);
}
long getSum(long n, long qs, long qe)
{
    return getSumRecur(0, n - 1, qs, qe, 0);
}
void constructSTRecur(vector<long> &arr, long ss, long se, long si)
{
    if (ss > se)
        return;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
    long mid = (ss + se) / 2;
    constructSTRecur(arr, ss, mid, si * 2 + 1);
    constructSTRecur(arr, mid + 1, se, si * 2 + 2);
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}
void constructST(vector<long> &arr, long n)
{
    constructSTRecur(arr, 0, n - 1, 0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, q;
    cin >> n >> q;
    vector<long> arr(n);
    for (long i = 0; i < n; ++i)
        cin >> arr[i];
    constructST(arr, n);
    while (q--)
    {
        long t;
        cin >> t;
        if (t == 1)
        {
            long a, b, u;
            cin >> a >> b >> u;
            updateRange(n, a - 1, b - 1, u);
        }
        else
        {
            long k;
            cin >> k;
            cout << getSum(n, k - 1, k - 1) << endl;
        }
    }
    return 0;
}
