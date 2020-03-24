#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 1000000007

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
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

ll mulmod(ll a, ll b, ll mod) 
{ 
    ll res = 0; // Initialize result 
    a = a % mod; 
    while (b > 0) 
    { 
        // If b is odd, add 'a' to result 
        if (b % 2 == 1) 
            res = (res + a) % mod; 
  
        // Multiply 'a' with 2 
        a = (a * 2) % mod; 
  
        // Divide b by 2 
        b /= 2; 
    } 
  
    // Return result 
    return res % mod; 
} 


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t;
    cin>>t;

    string s;
    ll n;
    ll slen;

    ll ans;
    ll minians;

    for(int test=0;test<t;test++){
    	cin>>n>>s;
    	slen = s.length();

    	if(n==slen){
    		cout<<1<<endl;
    		continue;
    	}
    	else if (n<slen){
    		cout<<0<<endl;
    		continue;
    	}

    	minians = power(26,n-slen,MOD);

    	// for(int i=0;i<slen;i++){
    	// 	ans+=minians;
    	// 	ans%=MOD;
    	// }

    	ans = mulmod(slen+1,minians,MOD);

    	for(int i=1;i<=min(slen,n-slen);i++){
    		ans-=mulmod(slen-i+1,power(26,n-slen-i,MOD),MOD);
    		while(ans<0){
    			ans+=MOD;
    		}
//    		ans-=(((slen-i+1)%MOD)*power(26,n-slen-i,MOD))%MOD;
    		ans%=MOD;
    	}

    	cout<<ans%MOD<<endl;
    }
}