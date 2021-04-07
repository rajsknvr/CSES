#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<long long> values(200001);

    values[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> values[i];
    for (int i = 2; i <= n; ++i)
        values[i] += values[i - 1];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << values[r] - values[l - 1] << endl;
    }
}