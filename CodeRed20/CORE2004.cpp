#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;


ll getMid(ll s, ll e)  
{ 
    return s + (e - s) / 2; 
} 
  
/*  A recursive function to get the sum of 
    values in given range of the array.  
    The following are parameters for this 
    function. 
  
    st       -> Poller to segment tree 
    node     -> Index of current node in  
                the segment tree . 
    ss & se  -> Starting and ending indexes  
                of the segment represented 
                by current node, i.e., st[node] 
    l & r    -> Starting and ending indexes  
                of range query */
ll MaxUtil(ll* st, ll ss, ll se, ll l,  
            ll r, ll node) 
{ 
    // If segment of this node is completely 
    // part of given range, then return  
    // the max of segment 
    if (l <= ss && r >= se) 
        return st[node]; 
  
    // If segment of this node does not 
    // belong to given range 
    if (se < l || ss > r) 
        return -1; 
  
    // If segment of this node is partially 
    // the part of given range 
    ll mid = getMid(ss, se); 
      
    return max(MaxUtil(st, ss, mid, l, r,  
                       2 * node + 1), 
               MaxUtil(st, mid + 1, se, l,  
                       r, 2 * node + 2)); 
} 
  
/* A recursive function to update the nodes which 
   have the given index in their range. The following 
   are parameters st, ss and se are same as defined 
   above index -> index of the element to be updated.*/
void updateValue(ll arr[], ll* st, ll ss, ll se,  
                 ll index, ll value, ll node) 
{ 
    if (index < ss || index > se)  
    { 
        cout << "Invalid Input" << endl; 
        return; 
    } 
      
    if (ss == se)  
    {    
        // update value in array and in segment tree 
        arr[index] = value; 
        st[node] = value; 
    } 
    else { 
            ll mid = getMid(ss, se); 
              
            if (index >= ss && index <= mid) 
                updateValue(arr, st, ss, mid, index,  
                            value, 2 * node + 1); 
            else
                updateValue(arr, st, mid + 1, se,  
                            index, value, 2 * node + 2); 
              
            st[node] = max(st[2 * node + 1],  
                       st[2 * node + 2]); 
    } 
    return; 
} 
  
// Return max of elements in range from 
// index l (query start) to r (query end). 
ll getMax(ll* st, ll n, ll l, ll r) 
{ 
    // Check for erroneous input values 
    if (l < 0 || r > n - 1 || l > r)  
    { 
        cout<<"Invalid Input"<<endl; 
        return -1; 
    } 
  
    return MaxUtil(st, 0, n - 1, l, r, 0); 
} 
  
// A recursive function that constructs Segment 
// Tree for array[ss..se]. si is index of  
// current node in segment tree st 
ll constructSTUtil(ll arr[], ll ss, ll se,  
                    ll* st, ll si) 
{ 
    // If there is one element in array, store 
    // it in current node of segment tree and return 
    if (ss == se)  
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
  
    // If there are more than one elements, then 
    // recur for left and right subtrees and  
    // store the max of values in this node 
    ll mid = getMid(ss, se); 
      
    st[si] = max(constructSTUtil(arr, ss, mid, st,  
                                 si * 2 + 1), 
                 constructSTUtil(arr, mid + 1, se,  
                                 st, si * 2 + 2)); 
      
    return st[si]; 
} 
  
/* Function to construct segment tree from given array. 
   This function allocates memory for segment tree.*/
ll* constructST(ll arr[], ll n) 
{ 
    // Height of segment tree 
    ll x = (ll)(ceil(log2(n))); 
  
    // Maximum size of segment tree 
    ll max_size = 2 * (ll)pow(2, x) - 1; 
  
    // Allocate memory 
    ll* st = new ll[max_size]; 
  
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n - 1, st, 0); 
  
    // Return the constructed segment tree 
    return st; 
} 




#define MOD 1000000007
int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //on each level, build a set of <ll,ll> pairs
    //also have a global set of <value,level> pairs

    ll n;
    cin>>n;

    ll val[n];
    for(int i=0;i<n;i++){
    	cin>>val[i];
    }

    vector<ll> adj[n];

    ll u,v;
    for(int i=0;i<n-1;i++){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    //bfs to assign depth
    bool seen[n];
    ll depth[n];
    memset(seen,false,sizeof(seen));
    queue<intpair> myQ;
    myQ.push({0,0});
    seen[0]=true;
    depth[0]=0;

    ll maxdepth=0;
    while(!myQ.empty()){
    	intpair curr = myQ.front();
    	myQ.pop();
    	for(ll a: adj[curr.first]){
    		if(seen[a])continue;
    		seen[a]=true;
    		depth[a]=curr.second+1;
	    	maxdepth=max(maxdepth,depth[a]);
    		myQ.push({a,curr.second+1});
    	}
    }

    // for(int i=0;i<n;i++){
    // 	cerr<<i<<" "<<depth[i]<<" "<<val[i]<<endl;
    // }

    ll q;
    cin>>q;

    set<intpair> depthSet[maxdepth+1];
    // set<intpair> globalSet;

    ll depthArr[maxdepth+1];


    for(int i=0;i<n;i++){
    	depthSet[depth[i]].insert({val[i],i});
    }


    for(int i=0;i<=maxdepth;i++){
    	// globalSet.insert({(*depthSet[i].rbegin()).first,i});
    	depthArr[i]=(*depthSet[i].rbegin()).first;
    }

    ll* st =constructST(depthArr,maxdepth+1);

    ll c,x,y;
    while(q--){
    	cin>>c;
    	if(c==1){
    		cin>>x>>y;
    		//do update
    		x--;
    		// ll prevdepthbest = (*depthSet[depth[x]].rbegin()).first;

    		auto it = depthSet[depth[x]].lower_bound({val[x],x});
    		depthSet[depth[x]].erase(it);
    		depthSet[depth[x]].insert({y,x});
    		val[x]=y;

    		// it = globalSet.lower_bound({prevdepthbest,depth[x]});
    		// globalSet.erase(it);
	    	// globalSet.insert({(*depthSet[depth[x]].rbegin()).first,depth[x]});

// void updateValue(ll arr[], ll* st, ll ss, ll se,  
//                  ll index, ll value, ll node) 


	    	updateValue(depthArr,st,0,maxdepth,depth[x],(*depthSet[depth[x]].rbegin()).first,0);
    	}
    	else{
    		cin>>x;
    		//do query
    		// auto it = globalSet.upper_bound({x,LLONG_MAX});
    		ll bmin=0;
    		ll bmax=maxdepth+1;

    		while(bmin<bmax){
    			ll bmid=getMid(bmin,bmax);
    			if(getMax(st,maxdepth+1,0,bmid)>x){
    				bmax=bmid;
    			}
    			else{
    				bmin=bmid+1;
    			}
    		}

    		if(bmin==maxdepth+1){
    			cout<<-1<<endl;
    		}
    		else{
    			ll theDepth = bmin;
    			auto it2 = depthSet[theDepth].upper_bound({x,LLONG_MAX});
    			cout<<(*it2).second+1<<endl;
    		}
    	}
    }
}
