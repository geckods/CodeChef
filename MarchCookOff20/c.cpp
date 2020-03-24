#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll t;
    cin>>t;
    while(t--){
    	ll h;
    	cin>>h;

		cout<<2<<" "<<1<<" "<<h<<endl;
		fflush(stdout);

		int curr=2;
		cin>>curr;
		bool done=false;
		int dist=3;
		while(!done){
			if(dist==2){
				dist=0;
			}
			else{
				cout<<1<<" "<<curr<<endl;
				fflush(stdout);
				cin>>dist;				
			}
			if(dist==0){
				cout<<3<<" "<<curr<<endl;
				fflush(stdout);
				done=true;
				cin>>dist;
			}
			else{
				cout<<2<<" "<<curr<<" "<<dist<<endl;
				fflush(stdout);
				// cerr<<"HI"<<endl;
				cin>>curr;
				// cerr<<"HI2"<<endl;
			}
		}
    }
}