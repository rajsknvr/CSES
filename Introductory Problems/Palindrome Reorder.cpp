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
    string st;
    cin >> st;
    int size = st.size();
    vector<int> data;
    for (char i : st)
    {
        data.push_back(i);
    }
    sort(data.begin(), data.end());

    int uniqueCount = 0;
    char unique;

    vector<char> res;
    for (int i = 0; i < size;)
    {
        if (i == size - 1)
        {

            if (uniqueCount == 0)
            {
                unique = (char)data[i];
                uniqueCount = 1;
                i += 1;
            }
            else
            {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
        else
        {
            if (data[i] != data[i + 1])
            {
                if (uniqueCount != 0)
                {
                    cout << "NO SOLUTION" << endl;
                    return 0;
                }
                unique = data[i];
                uniqueCount = 1;
                i += 1;
            }
            else
            {
                res.push_back((char)data[i]);
                i += 2;
            }
        }
    }
    size = res.size();
    for (int i = 0; i < size; ++i)
        cout << res[i];
    if (uniqueCount)
        cout << unique;
    for (int i = size - 1; i >= 0; --i)
        cout << res[i];
    return 0;
}