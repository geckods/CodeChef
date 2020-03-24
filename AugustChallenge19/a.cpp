#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
	    int ans=0;
	    int n;
	    cin>>n;

	    int a[n];
	    int b[n];
	    for(int i=0;i<n;i++){
	    	cin>>a[i];
	    }

	    for(int i=0;i<n;i++){
	    	cin>>b[i];
	    }

	    for(int i=0;i<n;i++){
	    	ans=max(ans,a[i]*20-b[i]*10);
	    }
	    cout<<ans<<endl;
    }

}
