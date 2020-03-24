#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll countSetBits(ll n) 
{ 
    ll count = 0; 
    while (n) { 
        n &= (n - 1); 
        count++; 
    } 
    return count; 
} 

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p  
  
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



int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // =

    ll t;
    cin>>t;

    while(t--){
    	ll n;
    	cin>>n;

    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	ll ans=1;
    	for(int i=1;i<n;i++){
    		if((arr[i]|arr[i-1])!=arr[i]){
    			ans=0;
    			break;
    		}	
    		ans*=power(2,countSetBits(arr[i-1]),MOD);
    		ans%=MOD;
    	}

    	cout<<ans<<endl;

    }

}
