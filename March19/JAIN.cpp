// we're going to need an "exatly" array and an "at least" array
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int canwork(int a,int b){
	for(int k=0;k<5;k++){
		if (((a & ( 1 << k )) >> k) || ((b & ( 1 << k )) >> k)){
		}
		else{
			return 0;
		}
	}
	return 1;
}

int issuperset(int a,int b){
	for(int k=0;k<5;k++){
		if (((a & ( 1 << k )) >> k) && !((b & ( 1 << k )) >> k)){
			return 0;
		}
	}
	return 1;
}

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif


    int t,n;
    cin>>t;

    string s;

//    Bitmask for extracting the kth bit
//    (n & ( 1 << k )) >> k 


	for(int test=0;test<t;test++){
		cin>>n;
		ll hasarr[n][5];
		memset(hasarr,0,n*5*sizeof(ll));

		for(int i=0;i<n;i++){
			cin>>s;
//			cout<<s<<endl;
			for(int j=0;j<s.length();j++){
				if(s[j]=='a') hasarr[i][0]=1;
				if(s[j]=='e') hasarr[i][1]=1;
				if(s[j]=='i') hasarr[i][2]=1;
				if(s[j]=='o') hasarr[i][3]=1;
				if(s[j]=='u') hasarr[i][4]=1;
			}
		}

		ll exactlyarr[32];
		memset(exactlyarr,0,32*sizeof(ll));

		ll atleastarr[32];
		memset(atleastarr,0,32*sizeof(ll));


		ll ans=0;
		int ind=0;

		for(int i=0;i<n;i++){
			ind = hasarr[i][0]*1+hasarr[i][1]*2+hasarr[i][2]*4+hasarr[i][3]*8+hasarr[i][4]*16;
//			cout<<hasarr[i][0]<<" "<<hasarr[i][1]<<" "<<hasarr[i][2]<<" "<<hasarr[i][3]<<" "<<hasarr[i][4]<<endl;
//			cout<<ind<<endl;
//			fflush(stdout);
			exactlyarr[ind]++;
		}

/*
		for(int i=0;i<32;i++){
			for(int j=0;j<32;j++){
				if(issuperset(i, j)){
					atleastarr[i]+=exactlyarr[j];
				}
			}
		}
*/

		for(int i=0;i<32;i++){
//			cout<<exactlyarr[i]<<" "<<atleastarr[i]<<endl;
			for(int j=0;j<32;j++){
				if(canwork(i,j)){
//					cout<<i<<" "<<exactlyarr[i]<<" "<<j<<" "<<exactlyarr[j]<<endl;
					ans+=exactlyarr[i]*exactlyarr[j];
				}
			}
		}

		cout<<(ans/2 - exactlyarr[31]/2)<<endl;

	}

}