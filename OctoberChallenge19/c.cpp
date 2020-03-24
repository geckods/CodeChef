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
   		ll n,k;
   		cin>>n>>k;

   		ll arr[n];
   		for(int i=0;i<n;i++){
   			cin>>arr[i];
   		}

   		if(k>=3*n){
   			if(n%2==1){
   				arr[n/2]=0;
   			}
   		}
   		k%=(3*n);


   		for(int i=0;i<k;i++){
   			arr[i%n]^=arr[n-1-(i%n)];
   		}

   		for(int i=0;i<n;i++){
   			cout<<arr[i]<<" ";
   		}
   		cout<<endl;
   	}
}