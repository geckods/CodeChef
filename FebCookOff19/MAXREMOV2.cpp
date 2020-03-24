#include <bits/stdc++.h> 
using namespace std;
#define N 100001

void update(int arr[], int l, int r, int val) 
{ 
    arr[l] += val; 
    arr[r+1] -= val; 
} 
  
// Get the element indexed at i 
int getElement(int arr[], int i) 
{ 
    // To get ith element sum of all the elements 
    // from 0 to i need to be computed 
    int res = 0; 
    for (int j = 0 ; j <= i; j++) 
        res += arr[j]; 
  
    return res; 
}

int main() 
{ 

//	#ifndef ONLINE_JUDGE
//    	freopen("input", "r", stdin);
//    	freopen("output", "w", stdout);
//	#endif


	int t,n,k,l,r;
	cin>>t;
	for(int test=0;test<t;test++){
		int updates[n][2];
		int cakestree[N];
		int cakes[N];		
		cin>>n>>k;
		for(int i=0;i<N;i++){
			cakes[i]=0;
		}

		for(int i=0;i<n;i++){
			cin>>l>>r;
			updates[i][0]=l-1;
			updates[i][1]=r-1;
			update(cakestree,l-1,r-1,1);
		}

		//applied all updates

		int asd=0;
		for(int i=0;i<N;i++){
			asd+=cakestree[i];
			cakes[i]=asd;
		}


		int kplusone[N];
		for(int i=0;i<N;i++){
			if(cakes[i]==k+1){
				kplusone[i]=1;
			}
			else{
				kplusone[i]=0;
			}
		}

		int kp[N];
		for(int i=0;i<N;i++){
			if(cakes[i]==k){
				kp[i]=1;
			}
			else{
				kp[i]=0;
			}
		}


		int prefix=0;
		int prefixcakes[N];
		for(int j=0;j<N;j++){
//			cout<<j<<" "<<N<<endl;
			prefix+=kplusone[j];
			prefixcakes[j]=prefix;
		}

		prefix=0;
		int prefixcakesk[N];
		for(int j=0;j<N;j++){
//			cout<<j<<" "<<N<<endl;
			prefix+=kp[j];
			prefixcakesk[j]=prefix;
		}

		

//		cout<<"HI"<<endl;
//		fflush(stdout);


		int ans=0;
		int minians;

//		for(int i=0;i<20;i++){
//			cout<<kplusone[i]<<" ";
//		}

		for(int i=0;i<n;i++){
			l = updates[i][0];
			r = updates[i][1];
			if(l>0){
				minians = prefixcakes[r]-prefixcakes[l-1] + prefixcakesk[l-1]+prefixcakesk[N-1]-prefixcakesk[r];
			}
			else{
				minians = prefixcakes[r] + prefixcakesk[N-1] - prefixcakesk[r];
			}
//			cout<<i<<" "<<l<<" "<<r<<endl;
			if(minians>ans)
				ans = minians;
		}

		cout<<ans<<endl;
	}
}
