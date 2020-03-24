#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

ll MOD = 1e9+7;

ll gcd(ll a, ll b); 
  
ll power(ll x, ll y, ll m); 
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
ll modInverse(ll a, ll m) 
{ 
    ll g = gcd(a, m); 
    return power(a, m-2, m); 
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
  
// Function to return gcd of a and b 
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
}


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
    	string s;
    	cin>>s;

    	ll offset[n];
    	offset[0]=0;

    	// prefixopen[0]=0;
    	// prefixclose[0]=0;
    	if(s[0]=='(')offset[0]++;
    	if(s[0]==')')offset[0]--;

    	for(int i=1;i<n;i++){
    		offset[i]=offset[i-1];
    		if(s[i]=='(')offset[i]++;
    		if(s[i]==')')offset[i]--;
    	}

    	// i sense some stacky stuff happening ->
    	// if I'm starting at position i with offset a[i], my first move only needs to be when offset [j]<offset[i-1
    	// -> stock span
    		//after making that change, i can ignore the next section i.e pos[j+1]
    	//dp stores the addition for that place

    	ll position[n];//position of i stores the first place where i needs to be toggled
    	// stack<ll> myStack;

    	// set<intpair> mySet;
    	// mySet.insert({INT_MAX,INT_MAX});
    	// for(int i=n-1;i>=0;i--){
    	// 	//i need it to sort by reverse offset, forward index
    	// 	mySet.insert({-offset[i],i});
    	// 	intpair ansPair;
    	// 	if(i>0)
	    // 		ansPair = *mySet.lower_bound({-offset[i-1],INT_MAX});
	    // 	else
	    // 		ansPair = *mySet.lower_bound({0,INT_MAX});

	    // 	position[i]=ansPair.second;
    	// }

    	stack<intpair> myStack;
    	for(int i=n-1;i>=1;i--){
    		myStack.push({offset[i],i});
    		while((!myStack.empty()) && myStack.top().first >= offset[i-1]){
    			myStack.pop();
    		}
    		// cerr<<"HI"<<endl;
    		if(myStack.empty()){
    			position[i]=INT_MAX;
    		}
    		else{
    			position[i]=myStack.top().second;
    		}
    	}

		myStack.push({offset[0],0});
		while((!myStack.empty()) && myStack.top().first >= 0){
			myStack.pop();
		}
		if(myStack.empty()){
			position[0]=INT_MAX;
		}
		else{
			position[0]=myStack.top().second;
		}

    	ll ans=0;//will be divided by n^2
    	ll dp[n];
    	ll minians;
    	int z,zz;

    	for(int i=n-1;i>=0;i--){
    		z=position[i];
    		if(z==INT_MAX){
    			dp[i]=0;
    			continue;
    		}
    		else{
				minians=1;
    			if(z!=n-1){
    				zz=position[z+1];
    				minians+=(n-z-1);
	    			if(zz<n-1){
    					minians+=dp[zz+1];
	    			}
    			}
    		}
    		dp[i]=minians;
    		ans+=minians;
    	}

    	ans%=MOD;

    	ll nsq;
    	if(n%2==0){
    		nsq=(n/2)*(n+1);
    	}
    	else{
    		nsq=(n)*((n+1)/2);
    	}
    	nsq%=MOD;

    	cout<<(ans*modInverse(nsq,MOD))%MOD<<endl;

    }
}