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
    	int n;
    	cin>>n;
    	int arr[n];
    	int mymin=INT_MAX;
    	int mymax=INT_MIN;
    	// cerr<<"HI"<<endl;
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		mymin = min(mymin,arr[i]);
    		mymax = max(mymax,arr[i]);
    	}

    	vector<int> factors;

    	for(int i=1;i*i<=mymin;i++){
    		if(mymin%i==0){
    			factors.push_back(i);
    			factors.push_back(mymin/i);
    		}
    	}

    	int ans=0;
    	for(int i=0;i<factors.size();i++){
    		int box1 = factors[i];
    		int box2 = -1;

    		for(int j=0;j<n;j++){
    			if(arr[j]%box1==0){
    			}
    			else{
    				if(box2==-1) box2=arr[j];
    				else{
    					box2=__gcd(box2,arr[j]);
    				}
    			}
    		}

    		if(box2==-1){
    			box2=mymax;
    		}
    		int minians=box1+box2;
    		ans=max(ans,minians);
    	}
    	cout<<ans<<endl;
    }
}
