#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//lets find the cycle in fibonacci
int fib[100];


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	fib[0]=0;
	fib[1]=1;

	for(int i=2;i<100;i++){
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]%=10;

		// if(fib[i]==1 && fib[i-1]==0){
			// cout<<i<<endl;
		// }
		//the 60th fibonacci number is the 0th
	}

	ll t;
	cin>>t;
	for(int test=0;test<t;test++){
		ll n;
		cin>>n;

		if(n==1){
			cout<<0<<endl;
			continue;
		}

		ll a=1;
		while(a<=n)a*=2;
		a/=2;
		a%=60;
		// cout<<a<<endl;
		cout<<fib[a-1]<<endl;
	}



}
