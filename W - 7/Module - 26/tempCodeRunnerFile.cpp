#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int LCS(string a,int n,string b, int m)
{
    if(n==0 || m==0)
    return 0;
    if(a[n-1]==b[m-1])
    {
        return LCS(a,n-1,b,m-1)+1;
    }
    else
    {
        return max(LCS(a,n-1,b,m),LCS(a,n,b,m-1));
    }
}

int main()
{
    string a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<LCS(a,a.size(),b,b.size());
    return 0;
}