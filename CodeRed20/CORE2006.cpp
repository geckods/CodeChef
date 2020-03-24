#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    ll t[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>t[i][j];
    	}
    }

    ll f[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>f[i][j];
    	}
    }

    ll cost[n][m];
    cost[n-1][m-1]=0;
    intpair nextsq[n-1][m-1];
    nextsq[n-1][m-1]={INT_MAX,INT_MAX}; //represents the next place you're going to buy at

    for(int k=n+m-3;k>=0;k--){
    	for(int i=0;i<n;i++){
    		int j=k-i;
    		if(j<0 || j>=m)continue;

    	}
    }




