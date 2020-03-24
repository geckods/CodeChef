#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t,a,b,c,d,ans;
    char ach,bch,cch;
    cin>>t;

    for(int test=0;test<t;test++){
    	cin>>a>>ach>>b>>bch>>c>>cch>>d;
    	ans = a;
    	if(ach=='+') ans+=b;
    	else ans -= b;

    	if(bch=='+') ans +=c;
    	else ans -= c;

    	if(ans==d){
    		cout<<"Valid Equation"<<endl;
    	}
    	else{
    		cout<<"Invalid Equation"<<endl;
    	}
    }
}