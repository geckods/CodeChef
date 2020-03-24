#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C[51][51]; 
void binomialCoeff() 
{ 
    ll i, j; 
  
    for (i = 0; i <= 50; i++) 
    { 
        for (j = 0; j <= min(i, 50ll); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return; 
} 


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	binomialCoeff();

   	ll t;
   	cin>>t;

   	for(int test=0;test<t;test++){
   		ll k,n;
   		cin>>n>>k;

   		ll arr[n];
   		map<ll,ll> myMap;
   		for(int i=0;i<n;i++){
   			cin>>arr[i];
   			myMap[arr[i]]++;
   		}

   		sort(arr,arr+n);
   		//get the number of occurances of the k-1th number

   		//aCb
   		ll a,b;
   		a=myMap[arr[k-1]];
   		b=0;
   		int j=k-1;
   		while(j>=0 && arr[j]==arr[k-1]){
   			b++;
   			j--;
   		}

   		cout<<C[a][b]<<endl;
   	}
}