#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t;
    cin>>t;

    ll n,m,k;

    ll abc;
    bool done;

    for(int test=0;test<t;test++){
    	cin>>n>>m>>k;
    	abc = n%m;

    	done = false;
    	while(abc%k!=0){
    		abc+=m;
    		if(abc>=n){
    			cout<<-1<<endl;
    			done = true;
    			break;
    		}
    	}

    	if(!done){
    		cout<<abc/k<<endl;
    	}
    }
}