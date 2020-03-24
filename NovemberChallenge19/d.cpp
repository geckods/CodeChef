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
   		ll n,m;
   		cin>>n>>m;

   		ll arr[n];
   		for(int i=0;i<n;i++){
   			cin>>arr[i];
   		}

   		vector<vector<ll> > mainVec(m);
   		for(int i=0;i<n;i++){
   			mainVec[i%m].push_back(arr[i]);
   		}

   		for(int i=0;i<m;i++){
   			sort(mainVec[i].begin(),mainVec[i].end());
   		}

   		set<pair<ll,ll> >mySet;

   		bool endmin=false;

   		for(int i=0;i<m;i++){
   			mySet.insert(make_pair(mainVec[i][0],i));
   		}

   		ll currmin=INT_MAX;
   		ll currmax=0;

   		ll ans=INT_MAX;

   		int pointers[m];
   		memset(pointers,0,sizeof(pointers));

   		while(!mySet.empty()){

   			if(!endmin){
   				currmin=(*mySet.begin()).first;
   			}
   			currmax=(*mySet.rbegin()).first;

   			ans=min(ans,currmax-currmin);

   			int toupdate=(*mySet.begin()).second;
   			pointers[toupdate]++;
   			mySet.erase(mySet.begin());

   			if(pointers[toupdate]<mainVec[toupdate].size()){
   				mySet.insert(make_pair(mainVec[toupdate][pointers[toupdate]],toupdate));
   			}
   			else{
   				endmin=true;
   			}
   		}

   		cout<<ans<<endl;
   	}
}