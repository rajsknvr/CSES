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
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();
    int dp[5001][5001];
    for (int i = 0; i <= n; ++i)
        dp[i][0] = i;
    for (int i = 0; i <= m; ++i)
        dp[0][i] = i;
    for (int i = 1; i <= n; ++i)
    {

        for (int j = 1; j <= m; ++j)
        {
            if ((str1[i - 1] == str2[j - 1]))
            {

                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    cout << dp[n][m] << endl;
}