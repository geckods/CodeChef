#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 998244353

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll binpowmod(ll a, ll b, ll p) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%p;
        a = (a * a)%p;
        b >>= 1;
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

    ll t;
    cin>>t;

    while(t--){
	    ll n,m;
	    cin>>n>>m;

	    // see the number of chains of each length
	    // first, get min length

	    ll x = 1;
	    ll curr = n;
	    while(curr>=m){
	    	curr/=m;
	    	x++;
	    }

	    x--;
	    // m^x is the largest power of m that is <= n

	    ll mostNums=0;

	    ll numWays=1;

	    ll alreadySeen=0;
	    ll prevSeen=0;
	    ll newPrevSeen=0;

	    for(ll i=x+1;i>=1;i--){
	    	ll currSeen=(n/(binpow(m,i-1)));

	    	if(i<x+1){
	    		currSeen-= (n/((binpow(m,i))));
	    	}
	    	// newPrevSeen=currSeen;
	    	// currSeen-=prevSeen;
	    	// prevSeen=newPrevSeen;

	    	// cerr<<i<<" "<<" "<<currSeen<<" "<<prevSeen<<" "<<alreadySeen<<endl;
	    	currSeen-=alreadySeen;
	    	// cerr<<currSeen<<endl;
	    	alreadySeen+=currSeen;
	    	
	    	mostNums+=currSeen*((i+1)/2);

	    	if(i%2==0){
		    	numWays*=binpowmod((i/2)+1,currSeen,MOD);
		    	numWays%=MOD;
	    	}

	    }

	    cout<<mostNums<<" "<<numWays<<endl;

    }
}