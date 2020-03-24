#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
    	ll n,p;
    	cin>>n>>p;
    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	if(p%arr[n-1]!=0){
    		cout<<"YES ";
    		if(arr[n-1]>p){
    			for(int i=0;i<n-1;i++){
    				cout<<0<<" ";
    			}
    			cout<<1<<endl;
    		}
    		else{
    			for(int i=0;i<n-1;i++){
    				cout<<0<<" ";
    			}
    			cout<<p/arr[n-1]+1<<endl;
    		}
    	}
    	else{
    		int wherenotworks=-1;
    		for(int i=n-2;i>=0;i--){
    			if(arr[i+1]%arr[i]!=0){
    				wherenotworks=i;
    				break;
    				//everything needs to perfectly divide everything after it
    			}
    		}

    		if(wherenotworks==-1){
    			cout<<"NO"<<endl;
    		}
    		else{
    			cout<<"YES ";
    			vector<int> myVec;
    			for(int j=n-1;j>wherenotworks;j--){
    				myVec.push_back((p-1)/arr[j]);
    				p-=((p-1)/arr[j])*arr[j];
    			}
    			myVec.push_back(ceil(((double)p)/arr[wherenotworks]));
    			for(int j=wherenotworks-1;j>=0;j--){
    				myVec.push_back(0);
    			}
    			for(int j=n-1;j>=0;j--){
    				cout<<myVec[j]<<" ";
    			}
    			cout<<endl;
    		}
    	}
    }
}
