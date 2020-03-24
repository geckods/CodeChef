#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

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
    	ll n,k;
    	cin>>n>>k;
    	// ll ans=k-1;
    	// ans%=MOD;

    	// ll curr;
    	// ll init = n-1;

    	// while(k>init){
    	// 	// cout<<init<<endl;
    	// 	ans+=k-(init+1);
    	// 	ans%=MOD;
    	// 	init+=n-1;
    	// 	// curr=k-init;
    	// }

        ll asd = ((k-1)/(n-1));
        ll ans2;
        if(asd%2==0){
            ans2 = ((((asd/2)%MOD)*((asd+1)%MOD))%MOD)*(n-1)%MOD;
        }
        else{
            ans2 = ((((asd)%MOD)*(((asd+1)/2)%MOD))%MOD)*(n-1)%MOD;
        }
        ans2%=MOD;

        // cout<<"aa"<<ans2<<endl;

        ans2+=((((k-1)%(n-1))%MOD)*(asd+1)%MOD)%MOD;

        // ll ans;
        // ll ic = ((k-1)/(n-1));
        // ans=(k-1)%MOD*(ic+1)%MOD;
        // ans%=MOD;

        // ll temp;
        // if(ic%2==0){
        //     temp = ((ic/2)%MOD)*((ic+1)%MOD);
        // }
        // else{
        //     temp = ((ic)%MOD)*(((ic+1)/2)%MOD);
        // }

        // ans-=((temp%MOD)*((n-1)%MOD))%MOD;
        // ans%=MOD;
        // if(ans<0)ans+=MOD;
        if(ans2<0)ans2+=MOD;
        ans2%=MOD;
        cout<<ans2<<endl;

    }
}