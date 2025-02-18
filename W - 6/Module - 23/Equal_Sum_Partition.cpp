#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 0)
    {
        sum = sum / 2;
        bool dp[n + 1][sum + 1];
        dp[0][0] = true;
        for (int j = 1; j <= sum; j++)
        {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        if(dp[n][sum]) cout<<"yes";
        else cout<<"no";
    }
    else
    {
        cout << "no";
    }
    return 0;
}
/*
4
1 4 4 9
*/