#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    	ll n,c;
    	cin>>n>>c;

    	map<ll,vector<ll>> myMap;
    	ll x,y;
    	for(int i=0;i<n;i++){
    		cin>>x>>y;
    		myMap[x-y].push_back(x);
    	}

    	ll checkPoint = 0;
    	ll moves=0;
    	for (auto it:myMap){
    		map<ll,vector<ll>> tempMap;
    		for(int j=0;j<it.second.size();j++){
    			ll temp = it.second[j]%c;
    			if(temp<0)temp+=c;
    			if(it.second[j]>=0 || temp==0){
	    			tempMap[temp].push_back(it.second[j]/c);
    			}
    			else{
	    			tempMap[temp].push_back((it.second[j]/c)-1);
    			}
    		}

    		checkPoint+=tempMap.size();
    		for (auto jt:tempMap){
    			sort(jt.second.begin(),jt.second.end());
    			ll median = jt.second[jt.second.size()/2];
    			// cerr<<it.first<<" "<<jt.first<<" "<<jt.second.size()<<" "<<median<<endl;
    			for(int j=0;j<jt.second.size();j++){
    				moves += abs(median-jt.second[j]);
    			}
    		} 
    	}

    	cout<<checkPoint<<" "<<moves<<endl;
    }

}
