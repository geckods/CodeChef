#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 100000

ll pfpstore[MAXN];

ll primeFactorsProd(ll n) 
{  
    ll asd=1;
    bool flip=true;
    while (n % 2 == 0)  
    {  
        n = n/2;  
        if(flip){
            asd*=2;
            flip=false;
        }
        else{
            flip=true;
        }
    }  
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        flip=true;
        while (n % i == 0)  
        {  
            if(flip){
                asd*=i;
                flip=false;
            }
            else{
                flip=true;
            }
            n = n/i;  
        }  
    }  
  
    if(n>1)asd=n;
    return asd;
}


void fillpfp(ll x){
    for(int i=1;i<=x;i++){
        pfpstore[i]=primeFactorsProd(i);
    }
}


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

        unordered_map<ll,vector<ll> > xToy;//for the key, what multiples are in y
        unordered_map<ll,vector<ll> > yTox;

        //for speedup, potentially make these constants in the comparison - immediate values are faster than variables?
        ll ylim=max(abs(y[0]),abs(y[y.size()-1]));
        ll xlim=max(abs(x[0]),abs(x[x.size()-1]));
        ll themax=max(xlim,ylim);
        fillpfp(themax);
        for(int i=1;i<MAXN;i++){
            for(int j=i;j<=MAXN;j+=i){
                if(ys.find(j)!=ys.end() || ys.find(-j)!=ys.end()){
                    xToy[i].push_back(j);
                }
                if(xs.find(j)!=xs.end() || xs.find(-j)!=xs.end()){
                    yTox[i].push_back(j);
                }                
            }

        }


        ans=0;
        halfans=0;

        ll ac;
        ll b,babs,c,k;


        for(int i=0;i<n;i++){
            if(i%1000==0)cerr<<i<<endl;
            b=x[i];
            babs=abs(b);


            if(b==0)continue;
            ll pfp=pfpstore[babs];
            //can x[i] be a b? we need to find an a which is a multiple of it
            //check for all possible a's


            for(auto z=xToy[pfp].begin()/*lower_bound(xToy[pfp].begin(),xToy[pfp].end(),babs)*/;z!=xToy[pfp].end();z++){
                k=*z;

                if(k<babs)continue;

                // if((k*k)%babs!=0)continue;
                // if(b==-4)cerr<<"HI"<<endl;
                ac=0;
                if(ys.find(k)!=ys.end())ac++;
                if(ys.find(-k)!=ys.end())ac++;
                if(ac>0){
                    //we have an a and a b, find c=a^2/b
                    c = -((k*k)/b);
                    if(xs.find(c)!=xs.end()){
                        //we have an a,b,c
                        // cerr<<b<<" "<<c<<" "<<k<<endl;
                        if(babs==k){
                            halfans+=ac;
                        }
                        else{
                            ans+=ac;
                        }
                    }
                }
            }
        }
        // cerr<<ans<<" "<<halfans<<endl;

        for(int i=0;i<m;i++){
            b=y[i];
            babs=abs(b);
            if(b==0)continue;
            ll pfp=pfpstore[babs];
            //can x[i] be a b? we need to find an a which is a multiple of it
            //check for all possible a's
            for(auto z=yTox[pfp].begin()/*auto z=lower_bound(yTox[pfp].begin(),yTox[pfp].end(),babs)*/;z!=yTox[pfp].end();z++){
                k=*z;

                if(k<babs)continue;

                // if((k*k)%babs!=0)continue;
                ac=0;
                if(xs.find(k)!=xs.end())ac++;
                if(xs.find(-k)!=xs.end())ac++;
                if(ac>0){
                    //we have an a and a b, find c=a^2/b
                    c = -((k*k)/b);
                    if(ys.find(c)!=ys.end()){
                        // cerr<<b<<" "<<c<<" "<<k<<endl;
                        //we have an a,b,c
                        if(babs==k){
                            halfans+=ac;
                        }
                        else{
                            ans+=ac;
                        }
                    }
                }
            }
        }

        ans+=halfans/2;

        if(haszero){
            ll llypos = ypos.size();
            ll llyneg = yneg.size();
            ans+=llypos*xpos.size()+llypos*xneg.size();
            ans+=llyneg*xpos.size()+llyneg*xneg.size();
        }
        cout<<ans<<endl;
    }


    return 0;
}








/*
//O(n^2) solution
        for(int i=0;i<m;i++){
            //a^2 =b*c
            ll a=y[i];
            ll asq=a*a;
            //b is xneg
            //c is xpos
            //minimum b is a^2/maxc or 1
            // cerr<<*xpos.end()<<endl;
            ll bmin=max((asq)/(*xpos.rbegin()),1ll);
            ll bmax=min((asq)/(*xpos.begin()),(ll)MAXN);

            int bmaxind=max((int)(lower_bound(xneg.begin(),xneg.end(),-bmax)-xneg.begin()),0);
            int bminind=min((int)(upper_bound(xneg.begin(),xneg.end(),-bmin)-xneg.begin()+1),(int)xneg.size());
            for(int j=bmaxind;j<bminind;j++){
                if((asq%abs(xneg[j])==0) && (xs.find(asq/abs(xneg[j]))!=xs.end()) ){
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
            ll bmin=max((asq)/(*ypos.rbegin()),1ll);
            ll bmax=min((asq)/(*ypos.begin()),(ll)MAXN);

            int bmaxind=max((int)(lower_bound(yneg.begin(),yneg.end(),-bmax)-yneg.begin()),0);
            int bminind=min((int)(upper_bound(yneg.begin(),yneg.end(),-bmin)-yneg.begin()+1),(int)yneg.size());
            for(int j=bmaxind;j<bminind;j++){
                if((asq%abs(yneg[j])==0) && (ys.find(asq/abs(yneg[j]))!=ys.end()) ){
                    ans++;
                }
            }
        }

*/
