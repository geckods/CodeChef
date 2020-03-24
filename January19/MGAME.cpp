#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    long long t,n,p,themod,ans;
    cin>>t;

    for(int test=0;test<t;test++){
    	cin>>n;
    	cin>>p;

    	if (n<3){
    		ans = p*p*p;
    		cout<<ans<<endl;
    		continue;
    	}

    	themod = n%((n/2)+1);
    	ans = (p-themod)*(p-themod) + (p-n)*(p-themod)+(p-n)*(p-n);
    	cout<<ans<<endl;
    }
}
