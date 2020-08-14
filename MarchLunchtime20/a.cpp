#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 1001

map<ll,ll> primeFactors(ll n)  
{  
	map<ll,ll> temp;
    while (n % 2 == 0)  
    {  
    	temp[2]++;
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
        	temp[i]++;
            n = n/i;  
        }  
    }  
  
    if (n > 2){
    	temp[n]++;
    }
    return temp;
}


map<ll,ll> pfzn[MAXN];

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // =

    // for(int i=2;i<MAXN;i++){
    // 	pfzn[i]=primeFactors(i);
    // }


    ll t;
    cin>>t;
    while(t--){
    	ll n,m;
    	cin>>n>>m;

    	map<ll,ll> currLCM;

    	ll x;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		map<ll,ll> curr = primeFactors(x);
    		for(auto a:curr){
    			currLCM[a.first]=max(currLCM[a.first],a.second);
    		}
    	}

    	ll maxNum=1;
    	ll maxVal=1;

    	for(int i=2;i<=m;i++){
    		map<ll,ll> curr = primeFactors(i);
    		ll currVal=1;
    		for(auto a:curr){
    			currVal*=pow(a.first,max(a.second-currLCM[a.first],0ll));
    		}

    		if(currVal>maxVal){
    			maxVal=currVal;
    			maxNum=i;
    		}
    	}
    	cout<<maxNum<<endl;

    }

}
