#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t;
    cin>>t;


    ll n,a;
    ll currmin,currmax,curr;

    ll maxprofit;
    ll currprofit;

    for(int test=0;test<t;test++){
    	cin>>n>>a;
    	ll c[n];
    	ll d[n];

    	for(int i=0;i<n;i++){
    		cin>>c[i]>>d[i];
    	}

    	ll cpref[n];
    	ll currpref=0;

    	for(int i=0;i<n;i++){
    		currpref+=c[i];
    		cpref[i]=currpref;
    	}

    	ll dp[n][n];

    	for(int i=0;i<n;i++){
    		currmin=currmax=d[i];
    		dp[i][i]=0;
    		for(int j=i+1;j<n;j++){
    			curr=d[j];
    			if(curr<currmin) currmin=curr;
    			if(curr>currmax) currmax=curr;
    			dp[i][j]=pow(currmin-currmax,2);
    		}
    	}

    	// for(int i=0;i<n;i++){
    	// 	cout<<cpref[i]<<" ";
    	// }
    	// cout<<endl;

		// for(int i=0;i<n;i++){
		// 	for(int j=i;j<n;j++){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }    	

    	maxprofit=0;
    	for(int i=0;i<n;i++){
    		for(int j=i;j<n;j++){
    			if(i>0){
	    			currprofit = (j-i+1)*a -(cpref[j]-cpref[i-1]) -dp[i][j];
	    		}
	    		else{
	    			currprofit = (j-i+1)*a -(cpref[j]) -dp[i][j];
	    		}
//	    		cout<<i<<" "<<j<<" "<<currprofit<<endl;
	    		maxprofit = max(maxprofit,currprofit);
    		}
    	}
    	cout<<maxprofit<<endl;
    }
}