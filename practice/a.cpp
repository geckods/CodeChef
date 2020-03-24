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

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;

    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	ll currmax=0;
    	ll leftside[n];
    	for(int i=0;i<n;i++){
    		leftside[i]=min(min((ll)i+1,arr[i]),currmax+1);
    		currmax=leftside[i];
    	}

    	currmax=0;
    	ll rightside[n];
    	for(int i=n-1;i>=0;i--){
    		rightside[i]=min(min((ll)(n-i),arr[i]),currmax+1);
    		currmax=rightside[i];
    	}

    	ll maxheight[n];
    	for(int i=0;i<n;i++){
    		maxheight[i]=min(leftside[i],rightside[i]);
    	}

    	ll leftcum[n];
    	ll leftsum=0;
    	for(int i=0;i<n;i++){
    		leftsum+=arr[i];
    		leftcum[i]=leftsum;
    	}

    	ll rightcum[n];
    	ll rightsum=0;
    	for(int i=n-1;i>=0;i--){
    		rightsum+=arr[i];
    		rightcum[i]=rightsum;
    	}


    	ll minans=LLONG_MAX;

    	for(int i=0;i<n;i++){
    		ll ans;
    		ans=0;
    		ans+=arr[i]-maxheight[i];

    		if(i>0) ans+=leftcum[i-1]-(maxheight[i]*(maxheight[i]-1))/2;
    		if(i<n-1) ans+=rightcum[i+1]-(maxheight[i]*(maxheight[i]-1))/2;
    		if(ans<minans) minans = ans;
    	}

    	cout<<minans<<endl;
    }
}
