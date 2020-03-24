#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin>>t;

    for(int test=0;test<t;test++){
    	ll n;
    	string s;
    	cin>>n;

    	ll pt = 0;
    	ll nc=n;
    	while(nc%2==0){
    		nc/=2;
    		pt++;
    	}

    	if(pt%2==0){
    		cout<<"Win"<<endl;
    		fflush(stdout);
    		while(n>0){
	    		if(n%2==0){
	    			n/=2;
	    			cout<<"/2"<<endl;
    			}
    			else{
    				if(n==1){
    					cout<<"-1"<<endl;
    					n--;    					
    				}
    				else if( ((n-1)/2)%2 == 1){
    					cout<<"-1"<<endl;
    					n--;
    				}
    				else{
    					cout<<"+1"<<endl;
    					n++;
    				}
    			}
    			fflush(stdout);
    			cin>>s;
    			if(s[0]!='G'){
    				if(s[0]=='-'){
    					n--;
    				}
    				else if(s[0]=='+'){
    					n++;
    				}
    				else{
    					n/=2;
    				}
    			}
    		}
    	}
    	else{
    		cout<<"Lose"<<endl;
    		fflush(stdout);
    		cin>>s;
    		if(s[0]=='W'){
    			return 0;
    		}
    	}
    }
}
