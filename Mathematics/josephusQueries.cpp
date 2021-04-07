#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        int a = 1;
        int d = 1;
        int r = 0;
        while (true)
        {
            //cout << a << " " << d << " " << k << endl;
            if (k == 1 && n == 1)
            {
                cout << a << endl;
                break;
            }
            int newa, newd, newr;
            newd = 2 * d;
            if (!r)
            {
                newa = a + d;
                if (k <= n / 2)
                {
                    int target = newa + (k - 1) * newd;
                    cout << target << endl;
                    break;
                }
                else
                {

                    if ((a + (n - 1) * d) == (newa + (n / 2 - 1) * newd))
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }

                    k -= (n / 2);
                    n -= (n / 2);
                    d = newd;
                }
            }
            else
            {

                if (k <= (n + 1) / 2)
                {
                    int target = a + (k - 1) * newd;
                    cout << target << endl;
                    break;
                }
                else
                {
                    if ((a + (n - 1) * d) == (a + ((n + 1) / 2 - 1) * newd))
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                    a = a + d;

                    k -= ((n + 1) / 2);
                    n -= ((n + 1) / 2);
                    d = newd;
                }
            }
        }
    }
}