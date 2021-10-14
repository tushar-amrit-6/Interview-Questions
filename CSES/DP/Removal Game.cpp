// Problem: Removal Game
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1097
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
	ll m = 1e9+7;
    ll dp[5005][5005];
    
    ll f(int l, int r, vector <int> &piles) {
        if(l == r-1) return max(piles[l], piles[r]);
        
        if(dp[l][r] != -1) return dp[l][r];
        
        ll ifleft = piles[l] + min(f(l+2, r, piles), f(l+1, r-1, piles));
        ll ifright = piles[r] + min(f(l+1, r-1, piles), f(l, r-2, piles));
        
        return dp[l][r] = max(ifleft, ifright);
    }
    ll stoneGame(vector<int>& piles) {
        int l = 0, r = piles.size()-1;
        memset(dp, -1, sizeof(dp));
        return f(l, r, piles);
    }
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<stoneGame(a);
	
}
