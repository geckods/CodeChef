#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int,int> intpair;

int global=0;

int recurse(int arr[],int i,int n,int m){
	int ans=0;
	if(i==n){
		bool works=true;
		for(int i=1;i<n-1;i++){
			if(arr[i]==arr[i-1] && arr[i]==arr[i+1]){
				works=false;
				break;
			}
		}

		if(works){
			// for(int k=0;k<n;k++){
			// 	cout<<arr[k]<<" ";
			// }
			// cout<<endl;
			return 1;
		}
		return 0;
	}
	else{
		for(int j=1;j<=m;j++){
			arr[i]=j;
			ans+=recurse(arr,i+1,n,m);
		}
	}
	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif


    for(int n=3;;n++){
	    int m=2;

		int arr[n];
		cout<<n<<" "<<m<<" "<<recurse(arr,0,n,m)<<endl;

    }
}
	//dp[n][2][2]
	//first 2 is whether m or m-1 options
	//next 2 is whether paired or not paired


