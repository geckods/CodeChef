#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define MAXN 100001

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

ll power(ll x, ll y, ll m); 
  
ll modInverse(ll a, ll m) 
{ 
    ll g = gcd(a, m); 
    if (g != 1) 
        return -1;
    else
    { 
        // If a and m are relatively prime, then modulo inverse 
        // is a^(m-2) mode m 
        // cout << "Modular multiplicative inverse is "
        return power(a, m-2, m); 
    } 
} 
  
// To compute x^y under modulo m 
ll power(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
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
	ll bottomC[MAXN];
	ll topC[MAXN];

    for(int i=0;i<MAXN;i++){
    	bottomC[i]=(i+1)/2;
    	topC[i]=(2*(power(4,(i)/2,MOD)-1))*modInverse(3,MOD);
    }

    ll t;
    cin>>t;
    while(t--){

    	ll dmax;
    	cin>>dmax;

    	//a must be an odd ancestor of b

    	ll numerator=0;

    	ll nodeCount=power(2,dmax+1,MOD)-1;

    	ll denominator=(nodeCount*(nodeCount-1))%MOD*2;
    	denominator%=MOD;




    	for(int d=0;d<=dmax;d++){
    		// numerator+=((power(2,d,MOD))*(((d+1)/2)+(2*(power(4,(dmax-d+1)/2,MOD)-1))*modInverse(3,MOD)))%MOD;
    		numerator+=power(2,d,MOD)*(bottomC[d]+topC[dmax-d+1]);
    		numerator%=MOD;
    		// cerr<<d<<" "<<(2*(pow(4,(dmax-d+1)/2)-1))/3<<" "<<(pow(2,d))*(((d+1)/2)+(2*(pow(4,(dmax-d+1)/2)-1))/3)<<" "<<endl;
    	}

    	// ll theGCD=gcd(numerator,denominator);
    	// numerator/=theGCD;
    	// denominator/=theGCD;

    	ll newDem=modInverse(denominator,MOD);

    	// cerr<<numerator<<" "<<denominator<<" "<<newDem<<" "<<numerator*newDem<<endl;
    	cout<<(numerator*newDem)%MOD<<endl;
    }
}