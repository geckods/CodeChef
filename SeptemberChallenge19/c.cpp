#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n,k;
   	cin>>n>>k;

   	ll arr[n];

   	map<ll,ll> countMap;
   	vector<ll> uniqVec;
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   		if(countMap[arr[i]]==0){
   			uniqVec.push_back(arr[i]);
   		}
   		countMap[arr[i]]++;
   	}
   	sort(uniqVec.begin(),uniqVec.end());

   	ll m=uniqVec.size();
   	k=min(k,m);
   	ll dp[m][k+1];

   	for(int i=0;i<m;i++){
   		for(int j=0;j<=k;j++){
   			dp[i][j]=0;
   		}
   	}

   	dp[0][1]=countMap[uniqVec[0]];
   	ll ans=0;
   	for(int i=1;i<m;i++){
   		dp[i][1]=dp[i-1][1]+countMap[uniqVec[i]];
   		dp[i][1]%=MOD;   		
   	}
   	ans+=dp[m-1][1]%MOD;


   	for(int i=2;i<=k;i++){
   		for(int j=1;j<m;j++){
   			dp[j][i]=(dp[j-1][i-1]*countMap[uniqVec[j]])%MOD+dp[j-1][i]%MOD;
   			dp[j][i]%=MOD;
   			if(j==m-1){
   				// cout<<dp[j-1][i-1]<<" "<<dp[j][i]<<" "<<j<<" "<<i<<endl;
   				ans+=dp[j][i]%MOD;
   			}
   		}
   	}

   	// for(int j=0;j<=k;j++){
	   // 	for(int i=0;i<m;i++){
   	// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
   	// 	}
   	// }

   	//so we're going to build a 2d DP array, dp[n][k]
   	//dp[i][j] represents the number of subsequences j elements distinct elements while considering only the first i contained primes
   	//dp[i][j]=count[arr[i]]*dp[i-1][j-1]

   	cout<<(ans+1)%MOD<<endl;
}