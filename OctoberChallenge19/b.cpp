#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int t;
   	cin>>t;


   	for(int test=0;test<t;test++){
   		ll n,m,q;
   		cin>>n>>m>>q;

   		ll narr[n];
   		ll marr[m];

   		memset(narr,0,sizeof(narr));
   		memset(marr,0,sizeof(marr));

   		ll x,y;
   		for(int i=0;i<q;i++){
   			cin>>x>>y;
   			narr[x-1]^=1;
   			marr[y-1]^=1;
   		}

   		ll onecount=0;
   		ll zerocount=0;
   		for(int i=0;i<m;i++){
   			onecount+=marr[i];
   		}
   		zerocount=m-onecount;

   		ll ans=0;
   		for(int i=0;i<n;i++){
   			if(narr[i])ans+=zerocount;
   			else ans+=onecount;
   		}
   		cout<<ans<<endl;
   	}
}