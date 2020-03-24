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
    	ll n,a,b,x,y,z;
    	cin>>n>>a>>b>>x>>y>>z;

    	ll c[n];
    	ll totsum=0;

    	ll copy;

    	for(int i=0;i<n;i++){
    		cin>>c[i];
    		copy = c[i];
    		while(copy>0){
    			totsum+=copy;
    			copy/=2;
    		}
    	}

    	ll numberofdays = ceil((z-b)/(double)y);
    	ll pipercount = a+(numberofdays-1)*x;

    	ll remaining = z-pipercount;
    	ll temp;
    	ll ans=0;

    	if(remaining<=0){
    		cout<<0<<endl;
    		continue;
    	}
    	else if (remaining>totsum){
    		cout<<"RIP"<<endl;
    	}
    	else{
    		priority_queue<ll> pq;
    		for(int i=0;i<n;i++){
    			if(c[i]>=0){
	    			pq.push(c[i]);
	    		}
    		}

    		while(remaining>0){
    			if(pq.empty()){
    				cout<<"RIP"<<endl;
    				ans=-1;
    				break;
    			}
    			temp = pq.top();
    			pq.pop();
    			remaining-=temp;
    			ans++;
    			temp/=2;

    			if(temp>0){
	    			pq.push(temp);
	    		}
    		}

    		if(ans==-1) continue;
    		cout<<ans<<endl;
    	}
    }
}
