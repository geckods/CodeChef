	#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN

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
    	ll n;
    	cin>>n;

    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	if (n>=64){
    		cout<<"NO"<<endl;
    		continue;
    	}


    	bool works=true;
    	set<ll> mySet;
    	for(int i=0;i<n;i++){
    		ll curr = 0;
    		for(int j=i;j<n;j++){
    			curr|=arr[j];
    			// cerr<<j<<" "<<curr<<endl;
    			if(mySet.find(curr)!=mySet.end()){
    				works=false;
    				break;
    			}
    			mySet.insert(curr);
    		}
    		if(!works)break;
    	}

    	if(works){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}

    }
}
