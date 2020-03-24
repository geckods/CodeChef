#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

	int t,n,x;
	int pos,neg;
    cin>>t;

    for(int test=0;test<t;test++){
    	cin>>n;
    	pos=neg=0;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		if(x>0) pos++;
    		else neg++;
    	}

    	cout<<max(pos,neg)<<" "<<((min(pos,neg)==0)?max(pos,neg):min(pos,neg))<<endl;
    }
}