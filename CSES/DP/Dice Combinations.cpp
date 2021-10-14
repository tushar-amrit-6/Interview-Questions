// Problem: Dice Combinations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1633/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf LLONG_MAX
/******************************************************************************/
int main()
{
	fast_io;
	int n;
	cin>>n;
	ll m=1e9+7;
	ll dp[n+1]={0};
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j>=i-6&&j>=0;j--)
		{
			dp[i]=(dp[i]+dp[j])%m;
		}
	}
	cout<<dp[n];
	
}
