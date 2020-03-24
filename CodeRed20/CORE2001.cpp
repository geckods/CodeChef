#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //must make odd number of moves
    //if n is odd,must do an odd number of two-jumps
    //if n is even, must do an e
    //build dp[startingrow][odd/even]

    ll n,m;
    cin>>n>>m;

    if(n==1){
    	cout<<0<<endl;
    	return 0;
    }

	ll dp[n][m][2];
	//0 is odd, 1 is even jumps till end

	//0 is row 1
	//n-1 is row n

	for(int i=0;i<m;i++){
		dp[n-1][i][0]=0;
		dp[n-1][i][1]=1;
	}


	for(int i=n-2;i>=0;i--){
		for(int j=0;j<m;j++){
			dp[i][j][0]=dp[i][j][1]=0;
			if(j>1){
				dp[i][j][0]+=dp[i+1][j-2][1];
				dp[i][j][1]+=dp[i+1][j-2][0];
			}
			if(j>0 && i<n-2){
				dp[i][j][0]+=dp[i+2][j-1][1];
				dp[i][j][1]+=dp[i+2][j-1][0];				
			}
			if(j<m-1 && i<n-2){
				dp[i][j][0]+=dp[i+2][j+1][1];
				dp[i][j][1]+=dp[i+2][j+1][0];				
			}
			if(j<m-2){
				dp[i][j][0]+=dp[i+1][j+2][1];
				dp[i][j][1]+=dp[i+1][j+2][0];				
			}
			dp[i][j][0]%=MOD;
			dp[i][j][1]%=MOD;
		}
	}

	ll ans=0;
	for(int j=1;j<m;j+=2){
		ans+=dp[0][j][0];
		ans%=MOD;
	}
	cout<<ans<<endl;
}
