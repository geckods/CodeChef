#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t,n,x,count,a;
    cin>>t;
    for(int test=0;test<t;test++){
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++){
    		arr[i]=0;
    	}
    	for(int i=0;i<n;i++){
    		cin>>x;
    		arr[x]++;
    	}

    	count=0;
    	a=0;
    	while(a<=count && a<n){
    		count+=arr[a];
    		a++;
    	}
    	cout<<count<<endl;
    }
}