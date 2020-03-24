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
    	string s;
    	cin>>s;
    	int onecount=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i]=='1')onecount++;
    	}

    	if(onecount%2==0){
    		cout<<"LOSE"<<endl;
    	}
    	else{
    		cout<<"WIN"<<endl;
    	}
    }
}