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

    int t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<ll> a;
    	vector<ll> b;
    	ll x;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		a.push_back(x);
    	}
    	for(int i=0;i<n;i++){
    		cin>>x;
    		b.push_back(x);
    	}
    	sort(a.begin(),a.end());
    	sort(b.begin(),b.end());
    	ll ans=0;
    	for(int i=0;i<n;i++){
    		ans+=min(a[i],b[i]);
    	}
    	cout<<ans<<endl;
    }
}
