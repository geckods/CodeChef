#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOURHFACTOR 101

bool isLeap(ll x){
	return (x%400==0||(x%4==0&&x%100!=0));
}

ll getVal(ll x){
	//looks like its a 400 year cycle

	ll ans=(x/400)*FOURHFACTOR;//number of 400 year cycles in x

	//monday->0
	int day=5;
	for(ll i=0;i<=x%400;i++){
		//the first day of the year is a Saturday
		if(day==2 || (!isLeap(i) && day==3))ans++;
		if(isLeap(i))day+=2;
		else day+=1;
		day%=7;
		// cerr<<i<<" "<<day<<" "<<ans<<endl;
	}

	return ans;
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //days when it has clash = any febuary which starts with a saturday

    //leap/nonleap->jan starts on wednesday OR nonleap and thursday
    //any non-leap year on which feb starts on Sunday -> Jan starts on Thursday

    ll t;
    cin>>t;
    while(t--){
    	ll m1,y1;
    	ll m2,y2;
    	cin>>m1>>y1;
    	cin>>m2>>y2;

    	if(m2==1)y2--;
    	if(m1>2)y1++;

    	cout<<getVal(y2)-getVal(y1-1)<<endl;
    }
}
