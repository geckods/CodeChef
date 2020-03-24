#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	ll t;
	cin>>t;



		// cerr<<"HI"<<endl;
	for(int test=0;test<t;test++){
		ll n;
		cin>>n;

		ll arr[n];
		ll pref[n+1];

		pref[0]=0;

		ll x=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			x^=arr[i];
			pref[i+1]=x;
		}



		map<ll,ll> lastseen;
		for(int i=0;i<=n;i++){
			lastseen[pref[i]]=-1;
		}

		ll lastind[n+1];
		for(int i=0;i<=n;i++){
			lastind[i]=lastseen[pref[i]];
			// cout
			if(lastind[i]==-1)lastind[i]=i;
			lastseen[pref[i]]=i;
		}

		unordered_map<ll,ll,custom_hash>count;
		ll thecount[n+1];
		for(int i=n;i>=0;i--){
			count[pref[i]]++;
			thecount[i]=count[pref[i]];
		}

		unordered_map<ll,ll,custom_hash>lcount;
		ll thelcount[n+1];
		for(int i=0;i<=n;i++){
			lcount[pref[i]]++;
			thelcount[i]=lcount[pref[i]];
			// cout<<i<<" "<<pref[i]<<" "<<lcount[pref[i]]<<endl;
		}


		// for(int i=0;i<=n;i++){
		// 	cout<<i<<" "<<pref[i]<<" "<<lastind[i]<<" "<<count[i]<<endl;
		// }

		ll ans=0;
		for(int i=0;i<=n;i++){
			// cout<<i<<" "<<pref[i]<<" "<<lastind[i]<<" "<<thelcount[i]<<" "<<thecount[i]<<endl;
			ans+=max((i-lastind[i]-1)*thelcount[lastind[i]]*1,0ll);
			ans+=max((i-lastind[i])*thelcount[lastind[i]]*(thecount[i]-1),0ll);

			// if(lastind[i]==0 && i>0)ans-=thecount[i];
		}

		cout<<ans<<endl;
	} 
}