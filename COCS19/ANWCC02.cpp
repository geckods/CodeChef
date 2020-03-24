#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,m;
    cin>>n>>m;

    int coins[n];
    int keys[m];

    for(int i=0;i<n;i++){
    	cin>>coins[i];
    }

    for(int i=0;i<m;i++){
    	cin>>keys[i];
    }

    int maxkeys[m];
    int maxkey = 0;

    for(int i=m-1;i>=0;i--){
    	maxkeys[i]=maxkey;
    	if(keys[i]>maxkey) maxkey=keys[i];
    }

    int averages[n];
    int sum = 0;

    for(int i=0;i<m;i++){
    	sum+=coins[i];
    	averages[0]=sum;
    }

    for(int j=m;j<n;j++){
    	sum-=coins[j-m];
    	sum+=coins[j];
    	averages[j-m+1]=sum;
    }
	
    int count,ave;
    int ans = 0;

    for(int i=0;i<=n-m;i++){
    	count=0;
    	ave = averages[i];
//    	if(((ave/m+1)*maxkey)<ans) continue;
    	for(int j=0;j<m;j++){
    		count+=coins[i+j]*keys[j];
    		ave-=coins[j];
    		if(((ave/(m-j-1)+1)*maxkeys[j])<ans-count) break;
    	}
    	if (count>ans) ans=count;
    }

    //use average of the n, max of the keys


    cout<<ans<<endl;
}