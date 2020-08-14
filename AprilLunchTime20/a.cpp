#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_updateusing namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define MOD 998244353


typedef pair<ll,ll> intpair;

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  



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
    	
    	map<ll,ll> myMap;

    	for(int i=0;i<n;i++){
    		cin>>arr[i];
			myMap[arr[i]]++;    		
    	}

    	ll ans=0;
    	ll currAccum=1;
    	ll leftRemainig=n;

    	ll expected=1;

    	bool done=false;
    	for(auto it:myMap){
    		// cerr<<it.first<<" "<<it.second<<endl;
    		if(it.first!=expected){
    			// add everything
    			ans+=((currAccum*power(2,leftRemainig,MOD))%MOD*expected)%MOD;
    			ans%=MOD;
    			done=true;
    			break;
    		}
    		else{
    			leftRemainig-=it.second;
    			ans+=((currAccum*power(2,leftRemainig,MOD))%MOD*(it.first))%MOD;
    			ans%=MOD;
    			currAccum*=power(2,it.second,MOD)-1;
    			// currAccum--;
    			currAccum%=MOD;
    			expected++;
    		}
    		// cerr<<ans<<" "<<expected<<" "<<currAccum<<" "<<leftRemainig<<endl;
    	}

    	if(!done){
    			ans+=currAccum*power(2,leftRemainig,MOD)*(expected);

    	ans%=MOD;
    	}

    	cout<<ans<<endl;
    	// 

    }

}
