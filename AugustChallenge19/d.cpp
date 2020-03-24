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

    ll t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll n;
    	cin>>n;

    	ll c[n];
    	for(int i=0;i<n;i++){
    		cin>>c[i];
    	}

    	ll h[n];
    	for(int i=0;i<n;i++){
    		cin>>h[i];
    	}

    	ll dr[n+1];
    	memset(dr,0,sizeof(dr));
    	for(int i=0;i<n;i++){
    		dr[max(0ll,i-c[i])]++;
    		dr[min(n,i+c[i]+1)]--;
    	}

    	ll r[n];
    	ll cum=0;
    	for(int i=0;i<n;i++){
    		cum+=dr[i];
    		r[i]=cum;
    		// cout<<i<<" "<<r[i]<<" "<<dr[i]<<endl;
    	}

    	sort(r,r+n);
    	sort(h,h+n);

    	bool done=false;
    	for(int i=0;i<n;i++){
    		if(h[i]!=r[i]){
    			done=true;
    			break;
    		}
    	}

    	if(done){
    		cout<<"NO"<<endl;
    	}
    	else{
    		cout<<"YES"<<endl;
    	}
    }
}