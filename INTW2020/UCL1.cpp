#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<pair<ll,ll>,pair<ll,ll>> TEAM;

struct Tree {
	typedef TEAM T;
	const T LOW = {{-1,-1},{-1,-1}};

	T f(T a, T b) {
		int temp=0;
		if(b.first.first>a.first.first)temp++;

		if(b.first.second>a.first.second)temp++;

		if(b.second.first>a.second.first)temp++;

		if(temp>1){
			return b;
		}
		return a;
	} // (any associative fn)

	vector<T> s; int n;
	Tree(int n = 0, T def = {{-1,-1},{-1,-1}}) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos > 1; pos /= 2)
			s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = LOW, rb = LOW;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // =

    ll x;
    cin>>x;

    ll thePow=pow(2,x);

    Tree myTree(thePow,{{-1,-1},{-1,-1}});

    ll a,b,c;
    for(int i=0;i<thePow;i++){
    	cin>>a>>b>>c;
    	myTree.update(i,{{a,b},{c,i}});
    }


    // cerr<<myTree.query(0,pow(2,x)).second.second<<endl;

    vector<pair<ll,ll> > quer;
    ll m;
    cin>>m;
    while(m--){
		char c;
		ll zz,zzz;
		cin>>c>>zz>>zzz;
		zz--;
		zzz--;

		quer.push_back({zz,zzz});
	}    	

	for(int i=0;i<quer.size();i++){
		ll zz=quer[i].first;
		ll zzz=quer[i].second;
		TEAM temp1=myTree.query(zz,zz+1);
		TEAM temp2=myTree.query(zzz,zzz+1);

		TEAM temptemp1=temp1;
		temptemp1.second.second=temp2.second.second;

		TEAM temptemp2=temp2;
		temptemp2.second.second=temp1.second.second;

		myTree.update(temp1.second.second,temptemp2);
		myTree.update(temp2.second.second,temptemp1);

		cout<<myTree.query(0,thePow).second.second+1<<endl;

		// cout<<"HI"<<endl;

    }

}