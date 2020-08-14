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

    // for(ll i=1;i<=10000;i++){
    // 	ll works=-1;
    // 	for(ll j=2;(j*(j+1))/2<=i;j++){
    // 		if((i-j)%(j) == 0){
    // 			works=j;
    // 			break;
    // 		}
    // 	}
    // 	// if(works>26)
	   //  // 	cerr<<i<<" "<<works<<endl;
    // }

    ll t;
    cin>>t;

    while(t--){
    	ll d;
    	cin>>d;

    	if(d==1){
    		cout<<"ab"<<endl;
    	}
    	else if (d==2){
    		// TODO
    		cout<<"aabb"<<endl;
    	}
    	else if (d==4){
    		cout<<"todd"<<endl;
    	}
    	else{
    		if((d-3)%2==0){
    			cout<<"abc";
    			for(int i=0;i<(d-3)/2;i++){
    				if(i%3==0){
    					cout<<"a";
    				}
    				else if (i%3==1){
    					cout<<"b";
    				}
    				else{
    					cout<<"c";
    				}
    			}
    			cout<<endl;
    		}
    		else{
    			ll ac = d/2;
    			ll bc = d/ac;
    			ac++;
    			for(int i=0;i<ac;i++){
    				cout<<"a";
    			}
    			for(int i=0;i<bc;i++){
    				cout<<"b";
    			}
    			cout<<endl;
	    	}
    	}
    }
}