//I have no idea how this fenwick tree data structure works but if it provides the time complexity claimed then I have a solution

#include <bits/stdc++.h> 
using namespace std;
#define N 100001
  
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    index = index + 1; 
  
    while (index <= n) 
    { 
        BITree[index] += val; 
  
        index += index & (-index); 
    } 
} 
  
int *constructBITree(int arr[], int n) 
{ 
    int *BITree = (int*)malloc(sizeof(int)*(n+1));
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    for (int i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
    //for (int i=1; i<=n; i++) 
    //      cout << BITree[i] << " "; 
  
    return BITree; 
} 
  
int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Iniialize result 
  
    index = index + 1; 
  
    while (index>0) 
    { 
        sum += BITree[index]; 
  
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void update(int BITree[], int l, int r, int n, int val) 
{ 
    updateBIT(BITree, n, l, val); 
  
    updateBIT(BITree, n, r+1, -val); 
} 
  
int main() 
{ 

//	#ifndef ONLINE_JUDGE
//    	freopen("input", "r", stdin);
//    	freopen("output", "w", stdout);
//	#endif

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif


	int t,n,k,l,r;
	cin>>t;
	for(int test=0;test<t;test++){
		int updates[n][2];
		int cakes[N];
		cin>>n>>k;

		
		for(int i=0;i<N;i++){
			cakes[i]=0;
		}

		int *BITree = constructBITree(cakes,N);

		for(int i=0;i<n;i++){
			cin>>l>>r;
			updates[n][0]=l-1;
			updates[n][1]=r-1;
		}

		cout<<"HIASD"<<n<<endl;
		fflush(stdout);


		for(int i=0;i<n;i++){
			update(BITree,updates[i][0],updates[i][1],N,1);
		}

		for(int i=0;i<10;i++){
			cout<<BITree[i]<<" ";
		}
		cout<<endl;
		cout<<getSum(BITree,0)<<endl;
		fflush(stdout);

		int kplusone[N];
		for(int i=0;i<N;i++){
			cakes[i]=getSum(BITree,i);
			if(cakes[i]==k+1){
				kplusone[i]=1;
			}
			else{
				kplusone[i]=0;
			}
		}

		cout<<"HI"<<endl;
		fflush(stdout);

		int prefix=0;
		int prefixcakes[n];
		for(int i=0;i<N;i++){
			prefix+=kplusone[i];
			prefixcakes[i]=prefix;
		}

		int ans=0;
		int minians;
		for(int i=0;i<n;i++){
			l = updates[i][0];
			r = updates[i][1];
			if(l>0){
				minians = prefixcakes[r]-prefixcakes[l-1];
			}
			else{
				minians = prefixcakes[r];
			}
			if(minians>ans)
				ans = minians;
		}

		cout<<ans<<endl;
	}

/*
    int arr[] = {0, 0, 0, 0, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int *BITree = constructBITree(arr, n); 
  
    // Add 2 to all the element from [2,4] 
    int l = 2, r = 4, val = 2; 
    update(BITree, l, r, n, val); 
  
    // Find the element at Index 4 
    int index = 4; 
    cout << "Element at index " << index << " is " << 
         getSum(BITree,index) << "\n"; 
  
    // Add 2 to all the element from [0,3] 
    l = 0, r = 3, val = 4; 
    update(BITree, l, r, n, val); 
  
    // Find the element at Index 3 
    index = 3; 
    cout << "Element at index " << index << " is " << 
         getSum(BITree,index) << "\n" ; 
  
    return 0; 
*/
} 