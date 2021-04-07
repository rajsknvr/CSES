#include <bits/stdc++.h>
using namespace std;

long getSumRecursion(long *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = (ss + se) / 2;
    return getSumRecursion(st, ss, mid, qs, qe, 2 * index + 1) + getSumRecursion(st, mid + 1, se, qs, qe, 2 * index + 2);
}

long getSum(long *st, int n, int qs, int qe)
{
    return getSumRecursion(st, 0, n - 1, qs, qe, 0);
}

long constructSTRecur(vector<int> &arr, int ss, int se, long *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss + se) / 2;
    st[si] = constructSTRecur(arr, ss, mid, st, si * 2 + 1) +
             constructSTRecur(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}
long *constructST(vector<int> &arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    long *st = new long[max_size];
    constructSTRecur(arr, 0, n - 1, st, 0);
    return st;
}

// To update values

void updateValueRecur(long *st, int ss, int se, int i, int diff, int si)
{
    if (i < ss || i > se)
        return;

    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = (ss + se) / 2;
        updateValueRecur(st, ss, mid, i, diff, 2 * si + 1);
        updateValueRecur(st, mid + 1, se, i, diff, 2 * si + 2);
    }
}

void updateValue(vector<int> &arr, long *st, int n, int i, int newVal)
{
    int diff = newVal - arr[i];
    arr[i] = newVal;
    updateValueRecur(st, 0, n - 1, i, diff, 0);
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
    long *st = constructST(values, n);
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            updateValue(values, st, n, l - 1, r);
        }
        else
        {
            cout << getSum(st, n, l - 1, r - 1) << endl;
        }
    }
}