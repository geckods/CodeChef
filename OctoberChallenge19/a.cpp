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
   		int n;
   		cin>>n;

   		int arr[n];
   		for(int i=0;i<n;i++){
   			cin>>arr[i];
   		}

   		int sum=0;
   		int temp=0;
   		for(int i=0;i<n;i++){
   			temp=1;
   			for(int j=i-1;j>=max(0,i-5);j--){
   				if(arr[i]>=arr[j]){
   					temp=0;
   					break;
   				}
   			}

   			sum+=temp;
   		}

   		cout<<sum<<endl;
   	}
}
