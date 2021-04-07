/*
    Author:@rajsknvr
    Institute:IIT BHU
    Name:Rajkumar Yadav
    Url:https://rajsknvr.in
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;
    while (n > 0)
    {
        int temp = n;
        int maxDigit = 0;
        while (temp > 0)
        {
            maxDigit = max(maxDigit, temp % 10);
            temp = temp / 10;
        }
        n -= maxDigit;
        count += 1;
    }
    cout << count;
}