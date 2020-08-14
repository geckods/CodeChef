#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // =

    ll n;
    cin>>n;

    //max that can be formed is n/2 * 9
    ll maxVal=(n/2)*9+1;
    ll dp[maxVal][10];

    for(int i=0;i<maxVal;i++){
    	
    }