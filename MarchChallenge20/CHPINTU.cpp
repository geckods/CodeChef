#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
	    ll n,m;
	    cin>>n>>m;
	    ll f[n];
	    ll p[n];

	    for(int i=0;i<n;i++){
	    	cin>>f[i];
	    }
	    for(int i=0;i<n;i++){
	    	cin>>p[i];
	    }

	    ll ans=INT_MAX;
	    for(int i=1;i<=m;i++){
	    	ll minians=-1;
	    	for(int j=0;j<n;j++){
	    		if(f[j]==i){
	    			if(minians<0)minians=0;
	    			minians+=p[j];
	    		}
	    	}
	    	if(minians>=0)
		    	ans=min(ans,minians);
	    }

	    cout<<ans<<endl;


    }


}
