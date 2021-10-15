// Problem: Money Sums
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1745
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
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	set<int>s;
	for(int i=0;i<n;i++)
	{
		set<int>t=s;
		for(auto it:s)
		{
			t.insert(it+a[i]);
		}
		t.insert(a[i]);
		s=t;
	}
	cout<<s.size()<<"\n";
	for(auto i:s)
	cout<<i<<" ";
	
}
