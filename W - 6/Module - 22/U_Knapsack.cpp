#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int s, int v[], int w[])
{
    if (n == 0 || s == 0) // base case
    {
        return 0;
    }

    if (w[n - 1] <= s)
    {
        int op1 = knapsack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = knapsack(n - 1, s, v, w);
        return max(op1, op2);
    }
    else
    {
        return knapsack(n - 1, s, v, w);
    }
}


int main()
{
    int n,s;
    cin>>n>>s;
    int w[n],v[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    cout<<knapsack(n,s,v,w);
    return 0;

}