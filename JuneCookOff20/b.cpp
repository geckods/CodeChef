#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//THINGS TO REMEMBER
//ENDL is slow, '\n' is fast
//Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN

#define MAXN 200001

ll par[MAXN];
ll sz[MAXN];

int find_set(int v) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v]);
}

void make_set(int v) {
    par[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

vector<ll> adj[MAXN];


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
    	ll n,m;
    	cin>>n>>m;

    	memset(par,0,sizeof(par));
    	memset(sz,0,sizeof(sz));

    	for(int i=0;i<n;i++){
    		make_set(i);
    	}

    	for(int i=0;i<n;i++){
    		adj[i].clear();
    	}

    	ll income[n];
    	ll pop[n];
    	bool used[n];

    	for(int i=0;i<n;i++){
    		cin>>income[i];
    	}

    	for(int i=0;i<n;i++){
    		cin>>pop[i];
    		used[i]=false;
    	}


    	ll u,v;
    	for(int i=0;i<m;i++){
    		cin>>u>>v;
    		u--;
    		v--;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}


    	vector<pair<double,ll>> myVec;
    	for(int i=0;i<n;i++){
    		myVec.push_back({((double)income[i])/(pop[i]),i});
    	}

    	sort(myVec.begin(),myVec.end());
    	reverse(myVec.begin(),myVec.end());

    	int lim=1;
    	while(lim<n && myVec[lim].first==myVec[lim-1].first)lim++;


    	for(int i=0;i<lim;i++){
    		used[myVec[i].second]=true;
    	}

    	for(int i=0;i<n;i++){
    		if(!used[i])continue;
    		for(auto j:adj[i]){
    			if(!used[j])continue;
    			union_sets(i,j);
    		}
    	}

    	vector<ll> ans;
    	ll maxSize=0;
    	ll currSet=-1;

    	for(int i=0;i<n;i++){
    		if(!used[i])continue;
    		if(sz[find_set(i)] > maxSize){
    			maxSize=sz[find_set(i)];
    			currSet=find_set(i);
    			ans.clear();
    			ans.push_back(i);
    		}
    		else if (sz[find_set(i)] == maxSize){
    			if(currSet==find_set(i)){
    				ans.push_back(i);
    			}
    		}
    	}

    	cout<<ans.size()<<endl;
    	for(int i=0;i<ans.size();i++){
    		cout<<ans[i]+1<<" ";
    	}
    	cout<<endl;


    }
}