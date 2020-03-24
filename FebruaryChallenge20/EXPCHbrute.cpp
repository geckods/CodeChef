#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

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

    	ll ans=0;

    	for(int i=0;i<n;i++){
    		for(int j=i;j<n;j++){
    			int curr=0;
    			for(int k=i;k<=j;k++){
    				if(s[k]=='('){
    					curr++;
    				}
    				else if (s[k]==')'){
    					curr--;
    				}

    				if(curr<0){
    					ans++;
    					curr+=2;
    				}
    			}
    		}
    	}

    	cout<<ans<<" "<<(n*(n+1))/2<<endl;
   	}
}