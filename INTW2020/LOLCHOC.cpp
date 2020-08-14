#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

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


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m,k;
    cin>>m>>k;

   	//f(1)=m
   	// sum of coefficients is m
   	//f(m+1)=k
   	// 
   	//f(k)=?

    // if(m==1){
    	// deal with separately
    // }

    if(m==k){
    	cout<<m<<endl;
    	return 0;
    }


    ll kc=k;
    map<ll,ll> myMap;
    ll maxpower=0;
    while(kc){
    	// express k in base m+1


    	ll temp=1;
    	ll i=0;

    	while(temp<=kc){
    		temp*=(m+1);
    		i++;
    	}

    	temp/=(m+1);
    	i--;
    	// cerr<<temp<<" "<<kc<<endl;

    	maxpower=max(maxpower,i);

    	// cerr<<temp<<endl;
    	// <temp is (m+1)^i,i> is largest working power
    	myMap[i]=kc/temp;
    	kc%=temp;
    }

    vector<ll> myVec;

    ll sum=0;
    for(int i=0;i<=maxpower;i++){
    	myVec.push_back(myMap[i]);
    	// cerr<<i<<" "<<myVec[i]<<endl;
    	sum+=myMap[i];
    }

    ll ans=0;
    for(int i=0;i<=maxpower;i++){
    	ans+=(myVec[i]*power(k,i,MOD))%MOD;
    	ans%=MOD;
    }

    cout<<ans<<endl;


}
