#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countSetBits(ll n){ 
    ll count = 0; 
    while (n){
        n &= (n - 1); 
        count++;
    } 
    return count;
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
    	ll n,q;
    	cin>>n>>q;

    	ll arr[n];
    	ll quer[q];

    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	for(int i=0;i<q;i++){
    		cin>>quer[i];
    	}

    	ll evenC=0;
    	ll oddC=0;

    	for(int i=0;i<n;i++){
    		if(countSetBits(arr[i])%2==0){
    			evenC++;
    		}
    	}

    	oddC=n-evenC;

    	for(int i=0;i<q;i++){
    		if(countSetBits(quer[i])%2==0){
    			cout<<evenC<<" "<<oddC<<"\n";
    		}
    		else{
    			cout<<oddC<<" "<<evenC<<"\n";
    		}
    	}

    }
}