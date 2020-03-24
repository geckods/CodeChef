#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int,int> intpair;


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
    	int n,k;
    	cin>>n>>k;

    	vector<int> adj[n];
    	// char temp[n+1];
    	string temp;
    	bool seen[n];

    	for(int i=0;i<n;i++){
    		seen[i]=false;
    		// scanf("%s\n",temp);
    		// cout<<temp;
    		cin>>temp;
    		if(i==n-1)continue;
    		for(int j=max(0,i-k);j<=min(n-1,i+k);j++){
    			if(i==j)continue;
    			if(temp[j]=='1'){
    				adj[i].push_back(j);
    			}
    		}
    	}

    	queue<intpair> myQ;
    	myQ.push({0,0});

    	int ans=-1;
    	int thenext;
    	int first,second;

    	while(myQ.size()>0){

    		if(ans!=-1)break;


    		intpair asd = myQ.front();
    		first=asd.first;
    		second=asd.second;
    		myQ.pop();
    		
    		if(first==n-1){
    			ans=second;
    			break;
    		}


    		seen[first]=true;
    		int asdf = adj[first].size();
    		for(int i=asdf-1;i>=0;i--){
    			thenext=adj[first][i];

    			if(thenext==n-1){
    				ans=second+1;
    				break;
    			}
    			if(!seen[thenext]){
    				myQ.push(make_pair(thenext,second+1));
    			}
    		}

    	}
    	cout<<ans<<endl;
    }

}
