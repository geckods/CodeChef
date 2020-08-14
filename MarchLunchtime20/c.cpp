#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
 //    	freopen("error", "w", stderr);
	// #endif
	// ios_base::sync_with_stdio(false);
 //    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<ll> temp;
    	cout<<1<<" "<<0<<endl;
    	fflush(stdout);
    	ll curr;
    	cin>>curr;
    	temp.push_back(curr);
    	ll mask=1;
    	for(int i=0;i<n-1;i++){
    		mask=1;
    		ll lastcurr=curr;
    		while(curr==lastcurr){
    			if((mask^lastcurr)>lastcurr){
    				cout<<1<<" "<<(mask^lastcurr)<<endl;
    				fflush(stdout);
    				cin>>curr;
    			}
    			else{
    				mask=mask<<1;
    			}
    		}
    		temp.push_back(curr);
    	}

    	cout<<2<<" ";
    	fflush(stdout);
    	for(int i=0;i<n;i++){
    		cout<<temp[i]<<" ";
    		fflush(stdout);
    	}
    	cin>>curr;
    	if(curr==-1){
    		return 0;
    	}
    }
}