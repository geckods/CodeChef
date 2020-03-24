#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long double dist(ll p0[],ll p1[]){
	return sqrt((long double)(pow(abs(p0[0]-p1[0]),2)+pow(abs(p0[1]-p1[1]),2)));
}


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif

    int t;
    cin>>t;

    while(t--){
    	ll n,m,w,h;
    	cin>>n>>m>>w>>h;
    	string s;
    	cin>>s;

    	ll points[m][2];
    	for(int i=0;i<m;i++){
    		cin>>points[i][0]>>points[i][1];
    	}

    	int reflected[4]={0,0,0,0};//R,L,U,D

    	for(int i=0;i<n;i++){
    		switch(s[i]){
    			case('R'):
    				if(reflected[0]==0)reflected[0]=1;
    				else reflected[1]=1;
    				break;
    			case('L'):
    				if(reflected[1]==0)reflected[1]=1;
    				else reflected[0]=1;
    				break;
    			case('U'):
    				if(reflected[2]==0)reflected[2]=1;
    				else reflected[3]=1;
    				break;
    			case('D'):
    				if(reflected[3]==0)reflected[3]=1;
    				else reflected[2]=1;
    				break;
    		}
    	}

    	long double ans=LDBL_MAX;


    	// cout<<w<<" "<<h<<" "<<n<<" "<<m<<endl;
    	// cout<<ans<<endl;
    	for(int i=0;i<m;i++){
    		if(reflected[0])
    			ans=min(ans,(long double)2*(w-points[i][0]));
    		if(reflected[1])
    			ans=min(ans,(long double)2*(points[i][0]));
    		if(reflected[2])
    			ans=min(ans,(long double)2*(h-points[i][1]));
    		// cout<<i<<" "<<ans<<" "<<points[i][1]<<endl;
    		if(reflected[3])
    			ans=min(ans,(long double)2*(points[i][1]));
    		// cout<<i<<" "<<ans<<endl;
    	}

    	// cout<<ans<<endl;

    	for(int i=0;i<m;i++){
    		for(int j=i+1;j<m;j++){
    			ans=min(ans,dist(points[i],points[j]));
    		}
    	}

    	cout<<setprecision(12)<<ans<<endl;

    }
}