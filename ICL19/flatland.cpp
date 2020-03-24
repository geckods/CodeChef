#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t;
    cin>>t;

    int n;
    int ans;
    int temp;

    for(int i=0;i<t;i++){
    	cin>>n;
    	ans=0;

    	while(n>0){
    		temp = (int)sqrt(n);
    		n-=temp*temp;
    		ans+=1;
    	}
    	
    	cout<<ans<<endl;
    }
}
