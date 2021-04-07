#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long modPow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long pro = 1;
    while (b > 1)
    {
        if (b & 1)
        {
            pro = (pro * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    pro = (pro * a) % mod;
    return pro;
}
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << modPow(a, b) << endl;
    }
}