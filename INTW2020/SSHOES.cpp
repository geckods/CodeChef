#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    	ll n,k;
    	cin>>n>>k;
    	string s;
    	cin>>s;

    	int shoes[26];
    	memset(shoes,0,sizeof(shoes));
    	for(int i=0;i<n;i++){
    		shoes[s[i]-'a']++;
    	}

    	bool works=true;
    	for(int i=0;i<26;i++){
    		if(shoes[i]%2==1){
    			works=false;
    			break;
    		}
    		shoes[i]/=2;
    		if(shoes[i]>k){
    			works=false;
    			break;
    		}
    	}

    	if(works){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}



    }
}