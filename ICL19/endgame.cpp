#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool isPowerOfTwo(int n) 
{ 
   return (ceil(log2(n)) == floor(log2(n))); 
} 

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

	int t;
	cin>>t;

	int d,h;
	int minx,maxx;
	int ans;

	for(int test=0;test<t;test++){
		cin>>d>>h;
		ans=0;
		minx = min(d,h);
		maxx = max(d,h);

		if(minx==0 && maxx!=0){
			cout<<-1<<endl;
			continue;
		}

		while(minx!=maxx){
			if(maxx/minx>=2){
				while(minx<maxx){
					ans++;
					minx*=2;
				}
				if(minx>maxx){
					ans--;
					minx/=2;
				}
			}
			else{
				minx--;
				maxx--;
				ans++;
			}
		}
		cout<<ans+minx<<endl;
	}
}