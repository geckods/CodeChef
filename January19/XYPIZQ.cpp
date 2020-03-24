#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
	if(a==0) return b;
	return gcd(b%a,a);
}

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

	int T;
	cin>>T;
	int N,t,x,y,z;
	int n,m;
	for(int test=0;test<T;test++){
		cin>>N>>t>>x>>y>>z;
		m = 2*N+1;

		if(t==1){
			if(z==x) n = x;
			else n = m-z;
		}
		else if (t==2 || t==4 ){
			n = m-2*y;
		}
		else if (t==3){
			if(z==x) n = x;
			else n=m-x;
		}
		int gcdnm = gcd(n,m);
		n = n/gcdnm;
		m = m/gcdnm;
		cout<<n<<" "<<m<<endl;
	}	
}