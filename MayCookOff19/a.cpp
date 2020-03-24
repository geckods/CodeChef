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
    	ll l,r,g;
    	cin>>l>>r>>g;

    	// double dl,dr,dg;
    	// dl = (double)l;
    	// dr = (double)r;
    	// dg = (double)g;

//    	cout<<dl<<" "<<dr<<" "<<dg<<endl;
//    	ll ans = floor(dr/dg)-floor((dl-1)/dg);
    	ll ans = r/g - (l-1)/g;
    	if(ans==1){
    		if(r/g>1){
	    		ans=0;
	    	}
    	}

    	cout<<ans<<endl;

    }


}
