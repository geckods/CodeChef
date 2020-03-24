#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int t;
   	cin>>t;

	int count[128];
	int last[128];

	for(int i=0;i<128;i++){
		count[i]=0;
		last[i]=-1;
	}

	int x=0;
	int prevx=0;
	count[0]=1;

	int ans[200];

	ans[1]=1;
	for(int i=0;i<128;i++){
		// cout<<i<<" "<<x<<" "<<count[x]<<" "<<last[x]<<endl;
		prevx=x;
		if(count[prevx]==1){
			x=0;
		}
		else{
			x=i-last[prevx];
		}

		count[x]++;
		ans[i+2]=count[x];
		// cout<<i+2<<" "<<x<<" "<<ans[i+2]<<endl;
		last[prevx]=i;
	}




   	for(int test=0;test<t;test++){
   		int n;
   		cin>>n;

   		cout<<ans[n]<<endl;

   	}
}