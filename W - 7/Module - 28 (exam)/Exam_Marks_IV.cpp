#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n, num;
        cin >> n >> num;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s = 1000 - num;

        int dp[n + 1][s + 1];
        dp[0][0] = 1;
        for (int j = 1; j <= s; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = (dp[i][j - a[i - 1]] + dp[i - 1][j]) % MOD;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j]) % MOD;
                }
            }
        }

        cout << dp[n][s] << endl;
    }

    return 0;
}