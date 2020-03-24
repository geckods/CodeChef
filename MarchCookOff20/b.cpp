#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 500000

ll tree[MAX] = { 0 }; 
  
// To store pending updates 
ll lazy[MAX] = { 0 }; 
  
// si -> index of current node in segment tree 
// ss and se -> Starting and ending indexes of 
// elements for which current nodes stores sum 
// us and ue -> starting and ending indexes of update query 
// diff -> which we need to add in the range us to ue 
void updateRangeUtilMAX(ll si, ll ss, ll se, ll us, 
                     ll ue, ll diff) 
{ 
    // If lazy value is non-zero for current node of segment 
    // tree, then there are some pending updates. So we need 
    // to make sure that the pending updates are done before 
    // making new updates. Because this value may be used by 
    // parent after recursive calls (See last line of this 
    // function) 
    if (lazy[si] != 0) { 
        // Make pending updates using value stored in lazy 
        // nodes 
        tree[si] += lazy[si]; 
  
        // Checking if it is not leaf node because if 
        // it is leaf node then we cannot go further 
        if (ss != se) { 
            // We can postpone updating children we don't 
            // need their new values now. 
            // Since we are not yet updating children of si, 
            // we need to set lazy flags for the children 
            lazy[si * 2 + 1] += lazy[si]; 
            lazy[si * 2 + 2] += lazy[si]; 
        } 
  
        // Set the lazy value for current node as 0 as it 
        // has been updated 
        lazy[si] = 0; 
    } 
  
    // Out of range 
    if (ss > se || ss > ue || se < us) 
        return; 
  
    // Current segment is fully in range 
    if (ss >= us && se <= ue) { 
        // Add the difference to current node 
        tree[si] += diff; 
  
        // Same logic for checking leaf node or not 
        if (ss != se) { 
            // This is where we store values in lazy nodes, 
            // rather than updating the segment tree itelf 
            // Since we don't need these updated values now 
            // we postpone updates by storing values in lazy[] 
            lazy[si * 2 + 1] += diff; 
            lazy[si * 2 + 2] += diff; 
        } 
        return; 
    } 
  
    // If not completely in range, but overlaps 
    // recur for children 
    ll mid = (ss + se) / 2; 
    updateRangeUtilMAX(si * 2 + 1, ss, mid, us, ue, diff); 
    updateRangeUtilMAX(si * 2 + 2, mid + 1, se, us, ue, diff); 
  
    // And use the result of children calls 
    // to update this node 
    tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]); 
} 
  
// Function to update a range of values in segment 
// tree 
// us and eu -> starting and ending indexes of update query 
// ue -> ending index of update query 
// diff -> which we need to add in the range us to ue 
void updateRangeMAX(ll n, ll us, ll ue, ll diff) 
{ 
    updateRangeUtilMAX(0, 0, n - 1, us, ue, diff); 
} 
  
// A recursive function to get the sum of values in given 
// a range of the array. The following are the parameters 
// for this function 
// si --> Index of the current node in the segment tree 
// Initially, 0 is passed as root is always at index 0 
// ss & se --> Starting and ending indexes of the 
// segment represented by current node 
// i.e., tree[si] 
// qs & qe --> Starting and ending indexes of query 
// range 
ll getSumUtilMAX(ll ss, ll se, ll qs, ll qe, ll si) 
{ 
  
    // If lazy flag is set for current node of segment tree 
    // then there are some pending updates. So we need to 
    // make sure that the pending updates are done before 
    // processing the sub sum query 
    if (lazy[si] != 0) { 
  
        // Make pending updates to this node. Note that this 
        // node represents sum of elements in arr[ss..se] and 
        // all these elements must be increased by lazy[si] 
        tree[si] += lazy[si]; 
  
        // Checking if it is not leaf node because if 
        // it is leaf node then we cannot go further 
        if (ss != se) { 
            // Since we are not yet updating children os si, 
            // we need to set lazy values for the children 
            lazy[si * 2 + 1] += lazy[si]; 
            lazy[si * 2 + 2] += lazy[si]; 
        } 
  
        // Unset the lazy value for current node as it has 
        // been updated 
        lazy[si] = 0; 
    } 
  
    // Out of range 
    if (ss > se || ss > qe || se < qs) 
        return LLONG_MIN; 
  	// cerr<<"HI"<<endl;
    // At this point, we are sure that pending lazy updates 
    // are done for current node. So we can return value 
    // (same as it was for a query in our previous post) 
  
    // If this segment lies in range 
    if (ss >= qs && se <= qe) 
        return tree[si]; 
  
    // If a part of this segment overlaps with the given 
    // range 
    ll mid = (ss + se) / 2; 
    return max(getSumUtilMAX(ss, mid, qs, qe, 2 * si + 1), 
               getSumUtilMAX(mid + 1, se, qs, qe, 2 * si + 2)); 
} 
  
// Return sum of elements in range from index qs (query 
// start) to qe (query end). It mainly uses getSumUtil() 
ll getSumMAX(ll n, ll qs, ll qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n - 1 || qs > qe) { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtilMAX(0, n - 1, qs, qe, 0); 
} 
  
// A recursive function that constructs Segment Tree for 
// array[ss..se]. si is index of current node in segment 
// tree st. 
void constructSTUtilMAX(ll arr[], ll ss, ll se, ll si) 
{ 
    // out of range as ss can never be greater than se 
    if (ss > se) 
        return; 
  
    // If there is one element in array, store it in 
    // current node of segment tree and return 
    if (ss == se) { 
        tree[si] = arr[ss]; 
        return; 
    } 
  
    // If there are more than one elements, then recur 
    // for left and right subtrees and store the sum 
    // of values in this node 
    ll mid = (ss + se) / 2; 
    constructSTUtilMAX(arr, ss, mid, si * 2 + 1); 
    constructSTUtilMAX(arr, mid + 1, se, si * 2 + 2); 
  
    tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]); 
} 
  
// Function to construct a segment tree from a given array 
// This function allocates memory for segment tree and 
// calls constructSTUtil() to fill the allocated memory 
void constructSTMAX(ll arr[], ll n) 
{ 
    // Fill the allocated memory st 
    constructSTUtilMAX(arr, 0, n - 1, 0); 
} 










ll treeMIN[MAX] = { 0 }; 
  
// To store pending updates 
ll lazyMIN[MAX] = { 0 }; 
  
// si -> index of current node in segment tree 
// ss and se -> Starting and ending indexes of 
// elements for which current nodes stores sum 
// us and ue -> starting and ending indexes of update query 
// diff -> which we need to add in the range us to ue 
void updateRangeUtilMIN(ll si, ll ss, ll se, ll us, 
                     ll ue, ll diff) 
{ 
    // If lazy value is non-zero for current node of segment 
    // tree, then there are some pending updates. So we need 
    // to make sure that the pending updates are done before 
    // making new updates. Because this value may be used by 
    // parent after recursive calls (See last line of this 
    // function) 
    if (lazyMIN[si] != 0) { 
        // Make pending updates using value stored in lazy 
        // nodes 
        treeMIN[si] += lazyMIN[si]; 
  
        // Checking if it is not leaf node because if 
        // it is leaf node then we cannot go further 
        if (ss != se) { 
            // We can postpone updating children we don't 
            // need their new values now. 
            // Since we are not yet updating children of si, 
            // we need to set lazy flags for the children 
            lazyMIN[si * 2 + 1] += lazyMIN[si]; 
            lazyMIN[si * 2 + 2] += lazyMIN[si]; 
        } 
  
        // Set the lazy value for current node as 0 as it 
        // has been updated 
        lazyMIN[si] = 0; 
    } 
  
    // Out of range 
    if (ss > se || ss > ue || se < us) 
        return; 
  
    // Current segment is fully in range 
    if (ss >= us && se <= ue) { 
        // Add the difference to current node 
        treeMIN[si] += diff; 
  
        // Same logic for checking leaf node or not 
        if (ss != se) { 
            // This is where we store values in lazy nodes, 
            // rather than updating the segment tree itelf 
            // Since we don't need these updated values now 
            // we postpone updates by storing values in lazy[] 
            lazyMIN[si * 2 + 1] += diff; 
            lazyMIN[si * 2 + 2] += diff; 
        } 
        return; 
    } 
  
    // If not completely in range, but overlaps 
    // recur for children 
    ll mid = (ss + se) / 2; 
    updateRangeUtilMIN(si * 2 + 1, ss, mid, us, ue, diff); 
    updateRangeUtilMIN(si * 2 + 2, mid + 1, se, us, ue, diff); 
  
    // And use the result of children calls 
    // to update this node 
    treeMIN[si] = min(treeMIN[si * 2 + 1], treeMIN[si * 2 + 2]); 
} 
  
// Function to update a range of values in segment 
// tree 
// us and eu -> starting and ending indexes of update query 
// ue -> ending index of update query 
// diff -> which we need to add in the range us to ue 
void updateRangeMIN(ll n, ll us, ll ue, ll diff) 
{ 
    updateRangeUtilMIN(0, 0, n - 1, us, ue, diff); 
} 
  
// A recursive function to get the sum of values in given 
// a range of the array. The following are the parameters 
// for this function 
// si --> Index of the current node in the segment tree 
// Initially, 0 is passed as root is always at index 0 
// ss & se --> Starting and ending indexes of the 
// segment represented by current node 
// i.e., tree[si] 
// qs & qe --> Starting and ending indexes of query 
// range 
ll getSumUtilMIN(ll ss, ll se, ll qs, ll qe, ll si) 
{ 
  
    // If lazy flag is set for current node of segment tree 
    // then there are some pending updates. So we need to 
    // make sure that the pending updates are done before 
    // processing the sub sum query 
    if (lazyMIN[si] != 0) { 
  
        // Make pending updates to this node. Note that this 
        // node represents sum of elements in arr[ss..se] and 
        // all these elements must be increased by lazy[si] 
        treeMIN[si] += lazyMIN[si]; 
  
        // Checking if it is not leaf node because if 
        // it is leaf node then we cannot go further 
        if (ss != se) { 
            // Since we are not yet updating children os si, 
            // we need to set lazy values for the children 
            lazyMIN[si * 2 + 1] += lazyMIN[si]; 
            lazyMIN[si * 2 + 2] += lazyMIN[si]; 
        } 
  
        // Unset the lazy value for current node as it has 
        // been updated 
        lazyMIN[si] = 0; 
    } 
  
    // Out of range 
    if (ss > se || ss > qe || se < qs) 
        return LLONG_MAX; 
  
    // At this point, we are sure that pending lazy updates 
    // are done for current node. So we can return value 
    // (same as it was for a query in our previous post) 
  
    // If this segment lies in range 
    if (ss >= qs && se <= qe) 
        return treeMIN[si]; 
  
    // If a part of this segment overlaps with the given 
    // range 
    ll mid = (ss + se) / 2; 
    return min(getSumUtilMIN(ss, mid, qs, qe, 2 * si + 1), 
               getSumUtilMIN(mid + 1, se, qs, qe, 2 * si + 2)); 
} 
  
// Return sum of elements in range from index qs (query 
// start) to qe (query end). It mainly uses getSumUtil() 
ll getSumMIN(ll n, ll qs, ll qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n - 1 || qs > qe) { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtilMIN(0, n - 1, qs, qe, 0); 
} 
  
// A recursive function that constructs Segment Tree for 
// array[ss..se]. si is index of current node in segment 
// tree st. 
void constructSTUtilMIN(ll arr[], ll ss, ll se, ll si) 
{ 
    // out of range as ss can never be greater than se 
    if (ss > se) 
        return; 
  
    // If there is one element in array, store it in 
    // current node of segment tree and return 
    if (ss == se) { 
        treeMIN[si] = arr[ss]; 
        return; 
    } 
  
    // If there are more than one elements, then recur 
    // for left and right subtrees and store the sum 
    // of values in this node 
    ll mid = (ss + se) / 2; 
    constructSTUtilMIN(arr, ss, mid, si * 2 + 1); 
    constructSTUtilMIN(arr, mid + 1, se, si * 2 + 2); 
  
    treeMIN[si] = min(treeMIN[si * 2 + 1], treeMIN[si * 2 + 2]); 
} 
  
// Function to construct a segment tree from a given array 
// This function allocates memory for segment tree and 
// calls constructSTUtil() to fill the allocated memory 
void constructSTMIN(ll arr[], ll n) 
{ 
    // Fill the allocated memory st 
    constructSTUtilMIN(arr, 0, n - 1, 0); 
} 

































struct Tree {
	typedef ll T;
	static const T LOW = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; ll n;
	Tree(ll n = 0, T def = 0) : s(2*n, def), n(n) {}
	void update(ll pos, T val) {
		for (s[pos += n] = val; pos > 1; pos /= 2)
			s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
	}
	T query(ll b, ll e) { // query [b, e)
		T ra = LOW, rb = LOW;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}


};


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

    	memset(tree,0,sizeof(tree));
    	memset(lazy,0,sizeof(lazy));
    	memset(treeMIN,0,sizeof(treeMIN));
    	memset(lazyMIN,0,sizeof(lazyMIN));


    	ll n,q;
    	cin>>n>>q;

    	//need a sum segment tree for computing prefixes, 

    	//a min segment tree on prefixes, +LAZYPROP
    	//and a max segment tree on prefixes +LAZYPROP

		ll barr[n];
		ll pb[n];
		Tree myTree = Tree(n,0);
		for(int i=0;i<n;i++){
			cin>>barr[i];
			// myTree.update(i,barr[i]);
			if(i==0)pb[i]=barr[i];
			else{
				pb[i]=pb[i-1]+barr[i];
			}
			// cerr<<i<<" "<<pb[i]<<endl;
		}

		constructSTMAX(pb,n);
		constructSTMIN(pb,n);

		// cerr<<getSumMAX(n,4,4)<<endl;

		// cout<<myTree.query(3,5); inclusive, exclusive

		for(int i=0;i<q;i++){
			char c;
			ll a,b;
			cin>>c>>a>>b;

			if(c=='U'){
				a--;
				updateRangeMAX(n,a,n-1,b-barr[a]);
				updateRangeMIN(n,a,n-1,b-barr[a]);
				// cerr<<a<<" "<<b<<endl;
				// cerr<<getSumMAX(n,0,0)<<endl;
				// myTree.update(a,b);
				barr[a]=b;
			}
			else{
				a--;
				b--;
				ll firstpart;
				if(a==0)
					firstpart=0;
				else
					firstpart=min(0ll,getSumMIN(n,0,a-1));
				
				ll secondpart=getSumMAX(n,b,n-1);
				// cerr<<a<<" "<<b<<" "<<firstpart<<" "<<secondpart<<secondpart-firstpart<<endl;
				cout<<secondpart-firstpart<<endl;
			}
		}

    }
}