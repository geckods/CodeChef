#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t;
    cin>>t;
    int a;
    int n;

    int x,y,z;

    for(int test=0;test<t;test++){
    	cin>>a>>n;
    	x = a%10;
    	y = (a/10)%10;
    	z = (a/100)%10;

//    	cout<<x<<" "<<y<<" "<<z<<endl;

    	if(x==y && y==z){
    		cout<<1<<endl;
    	}
    	else if(x==y || y==z || x==z){
    		cout<<8<<endl;
    	}
    	else{
    		cout<<27<<endl;
    	}
    }
}