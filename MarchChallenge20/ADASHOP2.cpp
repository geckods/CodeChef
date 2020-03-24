#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

intpair goTo(ll r0,ll c0,ll r1,ll c1){
	if(r0-c0==r1-c1 || r0+c0==r1+c1){
		return {r1,c1};
	}
	else{
		//x-y==r0-c0 -> x==r0-c0+y
		//x+y==r1+c1
		//r0-c0+2y==r1+c1
		
		//x==(r1+c1+r0-c0)/2
		//y==(r1+c1-r0+c0)/2

		//x+y==r0+c0 -> x==r0+c0-y
		//x-y==r1-c1
		//r0+c0-2y==r1-c1
		//x=(r0+c0+r1-c1)/2
		//y=(r0+c0-r1+c1)/2


		ll possx=(r1+c1+r0-c0)/2;
		ll possy=(r1+c1-r0+c0)/2;

		if(possx>=1 && possx<=8 && possy>=1 && possy<=8){
			return {possx,possy};
		}
		else{
			possx=(r0+c0+r1-c1)/2;
			possy=(r0+c0-r1+c1)/2;
			return {possx,possy};
		}
	}
}

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
    	ll r0,c0;
    	cin>>r0>>c0;
    	vector<intpair> myVec;
    	for(int i=1;i<=8;i++){
    		for(int j=1;j<=8;j++){
    			if((i+j)%2==1)continue;
    			while(r0!=i || c0!=j){
    				// cerr<<r0<<" "<<c0<<" "<<i<<" "<<j<<endl;
    				intpair temp=goTo(r0,c0,i,j);
    				myVec.push_back(temp);
    				r0=temp.first;
    				c0=temp.second;
    			}
    		}
    	}
	    cout<<myVec.size()<<endl;
	    for(int i=0;i<myVec.size();i++){
	    	cout<<myVec[i].first<<" "<<myVec[i].second<<endl;
	    }
    }
}