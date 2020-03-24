#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 400
ll dp[2*MAXN+1][MAXN+1];
ll cum[2*MAXN+1];

ll minsum(ll arr[], ll a, ll b, ll n){
	if(a>=2*n){
		// cout<<"FFF"<<endl;
		return 0;
	}

	if(b<=0){
		dp[a][b]=0;
		return 0;
		// return arr[a];
	}

	if(b==1){
		dp[a][b]=0;
		return arr[a];
	}

	if(dp[a][b]!=LLONG_MAX){
		ll curr=cum[a+b-1];
		if(a>0){
			curr-=cum[a-1];
		}
		return curr;
	}

	if(b==2){
		dp[a][b]=arr[a]+arr[a+1];
		return arr[a]+arr[a+1];
	}
	else{
		// if(a<2*n-2)
		// dp[a][b]=min(arr[a]+minsum(arr,a+1,b-1,n)+dp[a+1][b-1],2*(arr[a]+arr[a+1])+minsum(arr,a+2,b-2,n)+dp[a+2][b-2]);
		// cout<<a+2<<" "<<b-2<<" "<<minsum(arr,a+2,b-2)<<" "<<dp[a+2][b-2]<<endl;
		// dp[a][b]=cum[a+b]-((a>0)?cum[a-1]:0);
		for(int k=1;k<b;k++){
			// minsum(arr,a,k,n);
			// minsum(arr,a+k,b-k,n);
			// dp[a][b]=min(dp[a][b],dp[a][k]+dp[a+k][b-k]+cum[a+b]-((a>0)?cum[a-1]:0));
			// cout<<k<<endl;
			dp[a][b]=min(dp[a][b],2*(arr[a]+minsum(arr,a+1,k,n))+dp[a+1][k]+minsum(arr,a+k+1,b-k-1,n)+dp[a+k+1][b-k-1]);
		}
		ll curr=cum[a+b-1];
		if(a>0){
			curr-=cum[a-1];
		}
		// cout<<a<<" "<<b<<" "<<arr[a]+arr[a+1]+minsum(arr,a+2,b-2)+dp[a+2][b-2]<<endl;
		return curr;
	}
}


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll n;
    	cin>>n;

    	ll arr[2*n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	for(int i=n;i<2*n;i++){
    		arr[i]=arr[i-n];
    	}

    	// for(int i=0;i<2*n;i++){
    	// 	cout<<arr[i]<<" ";
    	// }
    	// cout<<endl;

    	for(int i=0;i<=2*n;i++){
    		for(int j=0;j<=n;j++){
    			dp[i][j]=LLONG_MAX;
    		}
    	}

    	cum[0]=arr[0];
    	for(int i=1;i<=2*n;i++){
    		cum[i]=arr[i]+cum[i-1];
    	}

    	// cout<<minsum(arr,2,3);
    	// return 0;

    	for(int i=0;i<2*n;i++){
    		for(int j=1;j<=n;j++){ 	   			
	    		minsum(arr,i,min((ll)j,2*n-i),n);
    		}
    	}

    	ll ans=LLONG_MAX;
    	for(int i=0;i<n;i++){
    		ans=min(ans,dp[i][n]);
    		for(int j=1;j<=n;j++){
	    		ans=min(ans,dp[i][j]+dp[i+j][n-j]+cum[n-1]);
    		}
    	}

    	// for(int i=0;i<n;i++){
    	// 	for(int j=1;j<=n;j++){
    	// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    	// 	}
    	// }

    	cout<<ans<<endl;
    }
}
