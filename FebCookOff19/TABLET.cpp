#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t,n,b,w,h,p;
    ll max,size;
    cin>>t;
    for(int test=0;test<t;test++){
    	cin>>n>>b;
    	max=0;
    	for(int i=0;i<n;i++){
    		cin>>w>>h>>p;
    		if(p<=b){
    			size=w*h;
    			if(size>max){
    				max=size;
    			}
    		}
    	}

    	if(max==0){
    		cout<<"no tablet"<<endl;
    	}
    	else{
    		cout<<max<<endl;
    	}
    }

}
