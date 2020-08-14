#include <bits/stdc++.h>
using namespace std;
typedef int ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // =

    ll n,k,m;
    cin>>n>>k>>m;

    ll arr[n];

    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll pref[n];
    ll closestnonzero[n];
    ll curr=-1;
    for(int i=0;i<n;i++){
    	if(i==0)pref[i]=arr[i];
    	else{
    		pref[i]=pref[i-1]+arr[i];
    	}
    	if(arr[i]>0)curr=i;
    	closestnonzero[i]=curr;
    }

    int i=0;
    ll ans=0;

    while(i<=n-k){
    	ll currval=pref[i+k-1];
    	if(i>0)currval-=pref[i-1];

    	if(currval<m){
    		if(currval==0){
    			ans=-1;
    			break;
    		}

    		ans++;
    		int j=closestnonzero[i+k-1];
    		if(j>n-k)break;

    		int newi=closestnonzero[j+k-1]+1;
    		if(newi<=i){
    			ans=-1;
    			break;
    		}
    		i=newi;
    	}
    	else{
    		i++;
    	}
    }
    cout<<ans<<endl;

}
