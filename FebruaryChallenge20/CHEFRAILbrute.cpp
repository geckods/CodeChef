#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 100000

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    ll ans,halfans;

    while(t--){
        ll n,m;
        cin>>n>>m;

        vector<ll> x;
        vector<ll> y;
        ll p;

        unordered_set<ll> xs;
        unordered_set<ll> ys;

        for(int i=0;i<n;i++){
            cin>>p;
            x.push_back(p);
            xs.insert(p);
        }

        for(int i=0;i<m;i++){
            cin>>p;
            y.push_back(p);
            ys.insert(p);
        }

        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        vector<ll> xpos;
        vector<ll> xneg;

        vector<ll> ypos;
        vector<ll> yneg;

        bool haszero=false;


        for(int i=0;i<n;i++){
            if(x[i]>0){
                xpos.push_back(x[i]);
            }
            else if (x[i]<0){
                xneg.push_back(x[i]);
            }
            else{
                haszero=true;
            }
        }

        for(int i=0;i<m;i++){
            if(y[i]>0){
                ypos.push_back(y[i]);
            }
            else if (y[i]<0){
                yneg.push_back(y[i]);
            }
            else{
                haszero=true;
            }
        }

        ans=0;


//O(n^2) solution
        for(int i=0;i<m;i++){

            if(i%1000==0)cerr<<i<<endl;
            //a^2 =b*c
            ll a=y[i];
            ll asq=a*a;
            //b is xneg
            //c is xpos
            //minimum b is a^2/maxc or 1
            // cerr<<*xpos.end()<<endl;
            // ll bmin=max((asq)/(*xpos.rbegin()),1ll);
            // ll bmax=min((asq)/(*xpos.begin()),(ll)MAXN);

            // int bmaxind=max((int)(lower_bound(xneg.begin(),xneg.end(),-bmax)-xneg.begin()),0);
            // int bminind=min((int)(upper_bound(xneg.begin(),xneg.end(),-bmin)-xneg.begin()+1),(int)xneg.size());
            for(int j=0;j<xneg.size();j++){
                if((asq%abs(xneg[j])==0) && (xs.find(asq/abs(xneg[j]))!=xs.end()) ){
                    // cerr<<a<<" "<<xneg[j]<<" "<<asq/abs(xneg[j])<<endl;
                    ans++;
                }
            }
        }
        // cout<<0<<endl;
        // cerr<<ans<<endl;
        // continue;


        for(int i=0;i<n;i++){
            ll a=x[i];
            ll asq=a*a;
            // ll bmin=max((asq)/(*ypos.rbegin()),1ll);
            // ll bmax=min((asq)/(*ypos.begin()),(ll)MAXN);

            // int bmaxind=max((int)(lower_bound(yneg.begin(),yneg.end(),-bmax)-yneg.begin()),0);
            // int bminind=min((int)(upper_bound(yneg.begin(),yneg.end(),-bmin)-yneg.begin()+1),(int)yneg.size());
            for(int j=0;j<yneg.size();j++){
                if((asq%abs(yneg[j])==0) && (ys.find(asq/abs(yneg[j]))!=ys.end()) ){
                    // cerr<<a<<" "<<yneg[j]<<" "<<asq/abs(yneg[j])<<endl;
                    ans++;
                }
            }
        }




        if(haszero){
            ll llypos = ypos.size();
            ll llyneg = yneg.size();
            ans+=llypos*xpos.size()+llypos*xneg.size();
            ans+=llyneg*xpos.size()+llyneg*xneg.size();
        }
        // cerr<<ans<<endl;
        cout<<ans<<endl;
    }


    return 0;
}








