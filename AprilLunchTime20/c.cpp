#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

#define MAXN 500

bool depend[MAXN][MAXN][32];
ll arr[MAXN];
bool updater[MAXN];
bool depends[MAXN];		
bool getAns[MAXN][MAXN];

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
    	ll n,k;
    	cin>>n>>k;
    	k--;

    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	ll x,y;


    	for(int i=0;i<n;i++){
    		cin>>x>>y;
    		x--;y--;
    		for(int j=0;j<n;j++){
    			depend[i][j][0]=false;
    			if(j>=x&&j<=y)
	    			depend[i][j][0]=true;
    		}
    	}

    	ll km=1;
    	int z=0;
    	while(km<=k){
    		z++;
    		km=km<<1;
    	}
    	z--;
    	km=km>>1;

    	for(int xxx=1;xxx<=z;xxx++){
    		for(int i=0;i<n;i++){
    			// setting the ith row
    			memset(depends,false,sizeof(depends));
    			for(int j=0;j<n;j++){
    				// do j ith row it?
    				if(depend[i][j][xxx-1]){
    					for(int zz=0;zz<n;zz++){
    						depends[zz]^=depend[j][zz][xxx-1];
    					}
    				}
    			}

    			for(int j=0;j<n;j++){
    				depend[i][j][xxx]=depends[j];
    			}

    		}
    	}


    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			getAns[i][j]=false;
    			if(i==j)getAns[i][j]=true;
    		}
    	}

    	while(z>=0){
    		if(km&k){
    			for(int i=0;i<n;i++){
    				// update the i'th row
	    			memset(updater,false,sizeof(updater));
	    			for(int j=0;j<n;j++){
	    				// do j ith row it?
	    				if(getAns[i][j]){
	    					for(int zz=0;zz<n;zz++){
	    						updater[zz]^=depend[j][zz][z];
	    					}
	    				}
	    			}

	    			for(int j=0;j<n;j++){
	    				getAns[i][j]=updater[j];
	    			}
    			}
    		}
    		km=km>>1;
    		z--;
    	}

    	for(int i=0;i<n;i++){
    		ll ans=0;
    		for(int j=0;j<n;j++){
    			if(getAns[i][j])ans^=arr[j];
    		}
    		cout<<ans<<' ';
    	}
    	cout<<"\n";

    }
}