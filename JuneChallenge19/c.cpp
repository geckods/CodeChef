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
    	ll n;
    	cin>>n;

    	ll arr[n];
    	ll sum=0;

    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		sum+=arr[i];
    	}

    	ll k,x;
    	cin>>k;
    	cin>>x;

    	ll updateval[n];
    	for(int i=0;i<n;i++){
    		updateval[i]=(arr[i]^x)-arr[i];
    	}
    	sort(updateval,updateval+n);
    	

    	ll cumupdate[n];
    	cumupdate[n-1]=updateval[n-1];
 
     	ll maxcum=cumupdate[n-1];
    	ll maxcumind=n-1;

    	for(int i=n-2;i>=0;i--){
    		cumupdate[i]=updateval[i]+cumupdate[i+1];
    		if(cumupdate[i]>maxcum){
    			maxcum=cumupdate[i];
    			maxcumind=i;
    		}
    	}

    	if(k==n){
    		cout<<max(sum,sum+cumupdate[0])<<endl;
    		continue;
    	}

    	if(k%2==1 || (n-maxcumind)%2==0){
    		cout<<max(sum,sum+maxcum)<<endl;
    	}
    	else{
    		ll ans=sum;
    		if(maxcumind>0){
    			ans=max(ans,sum+cumupdate[maxcumind-1]);
    		}
    		if(maxcumind<n-1){
    			ans=max(ans,sum+cumupdate[maxcumind+1]);    				
    		}
    		cout<<max(sum,ans)<<endl;
    	}
    }
}