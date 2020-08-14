#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_updateusing namespace std;
using namespace __gnu_pbds;



using namespace std;
typedef long long ll;


typedef pair<ll,ll> intpair;

typedef tree<
    intpair,
    null_type,
    less<intpair>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;


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
    	ll n,q;
    	cin>>n>>q;

    	vector<intpair> myVec;
    	vector<pair<intpair,int>> queries;
    	ordered_set xmy;
    	int t=0;

    	ll x,y;
    	for(int i=0;i<n;i++){
    		cin>>x>>y;
    		myVec.push_back({x-y,x+y});
	    	xmy.insert({x+y,t++});
    	}

    	for(int i=0;i<q;i++){
    		cin>>x>>y;
    		queries.push_back({{x,y},i});    		
    	}

    	sort(myVec.begin(),myVec.end());
    	sort(queries.begin(),queries.end()); 

    	int pointInd=0;
    	int querInd=0;


    	// cerr<<myVec.size()<<endl;

    	vector<intpair> answer;

    	while(querInd<q){

    		if(pointInd!=n && (myVec[pointInd].first < queries[querInd].first.first)){
    			xmy.erase(xmy.lower_bound({myVec[pointInd].second,0}));
    			pointInd++;
    		}
    		else{
    			// cerr<<xmy.size()<<endl;
    			answer.push_back({queries[querInd].second,xmy.order_of_key({queries[querInd].first.second+1,0})});
    			querInd++;
    		}
    	}

    	sort(answer.begin(),answer.end());
    	for(int i=0;i<q;i++){
    		cout<<answer[i].second<<"\n";
    	}

    }
}