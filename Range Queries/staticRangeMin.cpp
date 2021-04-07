#include <bits/stdc++.h>
using namespace std;

int RMQRecursion(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = (ss + se) / 2;
    return min(RMQRecursion(st, ss, mid, qs, qe, 2 * index + 1), RMQRecursion(st, mid + 1, se, qs, qe, 2 * index + 2));
}

int RMQ(int *st, int n, int qs, int qe)
{
    return RMQRecursion(st, 0, n - 1, qs, qe, 0);
}

int constructSTRecur(vector<int> &arr, int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss + se) / 2;
    st[si] = min(constructSTRecur(arr, ss, mid, st, si * 2 + 1),
                 constructSTRecur(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}
int *constructST(vector<int> &arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTRecur(arr, 0, n - 1, st, 0);
    return st;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> values(200000);

    for (int i = 0; i < n; ++i)
        cin >> values[i];
    int *st = constructST(values, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << RMQ(st, n, l - 1, r - 1) << endl;
    }
}