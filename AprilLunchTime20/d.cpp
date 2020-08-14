#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

#define MOD 998244353

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
    	ll n,m,q;
    	cin>>n>>m>>q;
    	// m--;
    	if(q>1)return 0;
    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	ll pos,val;
    	vector<intpair> quer;
    	for(int i=0;i<q;i++){
    		cin>>pos>>val;
    		pos--;
    		quer.push_back({pos,val});
    	}

    	for(int i=0;i<q;i++){
    		arr[quer[i].first]=quer[i].second;
    		ll multiplier[n];
    		ll pref[n];
    		ll sum=0;
    		pref[0]=arr[0];
    		for(int i=1;i<n;i++){
    			pref[i]=arr[i]+pref[i-1];
    			pref[i]%=MOD;
    			// cerr<<i<<" "<<pref[i]<<endl;
    		}

    		ll pref2[m];
    		for(int i=0;i<m;i++){
    			pref2[i]=pref[n-m+i];
    			if(i>0)pref2[i]-=pref[i-1];

    			pref2[i]%=MOD;
    			if(pref2[i]<0)pref2[i]+=MOD;
    		}

    		ll pref3[m];
    		pref3[0]=pref2[0];
    		for(int i=1;i<m;i++){
    			pref3[i]=pref3[i-1]+pref2[i];
    			pref3[i]%=MOD;
    			// cerr<<i<<" "<<pref3[i]<<endl;
    			if(pref3[i]<0)pref3[i]+=MOD;
    		}

    		ll ans=0;
    		for(int i=0;i<n;i++){
    			ll mult=pref3[min(m-1,(ll)i)];
    			if(i>=n-m+1){
    				mult-=pref3[i-n+m-1];
    			}
    			if(mult<0)mult+=MOD;
    			// cerr<<i<<" "<<mult<<endl;
    			// if(i>=m)mult-=pref2[i-m];
    			// if(mult<0)mult+=MOD;
    			ans+=arr[i]*mult;
    			ans%=MOD;
    		}
    		cout<<ans<<endl;

    	}
    }
}