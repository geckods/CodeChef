#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 100000

// I am a genius, I've been thinking about this problem for nearly 2 days and this solution finally worked, I'm so happy, it came to me in my sleep

ll pfpstore[MAXN];
map<ll,ll> sqrts;

ll primeFactorsProdOdd(ll n) 
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
            asd/=2;
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
                asd/=i;
                flip=true;
            }
            n = n/i;  
        }  
    }  
  
    if(n>1)asd*=n;
    return asd;
}


void fillpfp(ll x){
    for(int i=1;i<=x;i++){
        pfpstore[i]=primeFactorsProdOdd(i);
    }
}

void fillsqrts(ll x){
    for(ll i=1;i<=x;i++){
        sqrts[i*i]=i;
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

        //need more data structures
        ans=0;
        map<ll,vector<ll>> xnegp;
        map<ll,vector<ll>> ynegp;

        fillpfp(MAXN);
        fillsqrts(MAXN);

        for(int i=0;i<xneg.size();i++){
            xnegp[pfpstore[abs(xneg[i])]].push_back(xneg[i]);
        }

        for(int i=0;i<yneg.size();i++){
            ynegp[pfpstore[abs(yneg[i])]].push_back(yneg[i]);
        }

        for(int i=0;i<xpos.size();i++){
            cerr<<pfpstore[xpos[i]]<<endl;
            vector<ll> theVec=xnegp[pfpstore[xpos[i]]];
            for(auto j=theVec.begin();j!=theVec.end();j++){
                ll k = *j;
                ll temp=sqrts[-k*xpos[i]];
                if(ys.find(temp)!=ys.end())ans++;
                if(ys.find(-temp)!=ys.end())ans++;
            }
        }

        for(int i=0;i<ypos.size();i++){
            vector<ll> theVec=ynegp[pfpstore[ypos[i]]];
            for(auto j=theVec.begin();j!=theVec.end();j++){
                ll k = *j;
                ll temp=sqrts[-k*ypos[i]];
                if(xs.find(temp)!=xs.end())ans++;
                if(xs.find(-temp)!=xs.end())ans++;
            }
        }


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
