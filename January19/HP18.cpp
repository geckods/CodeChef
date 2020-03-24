#include <bits/stdc++.h>
using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif


	int t,n,a,b,ac,bc,abc;
	bool moda,modb,alice;
	cin>>t;
	for(int test=0;test<t;test++){
		cin>>n;
		cin>>b;
		cin>>a;

		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		ac = bc = abc = 0;

		for(int i=0;i<n;i++){
			moda = (arr[i]%a==0);
			modb = (arr[i]%b==0);
//			cout<<arr[i]<<" "<<moda<<" "<<modb<<endl;
			if (moda && !modb) ac++;
			else if (!moda && modb) bc++;
			else if (moda && modb) abc++;
		}

//		cout<<ac<<' '<<bc<<' '<<abc<<endl;

		if (abc>0) bc++;

		if (ac>=bc) alice = true;
		else alice = false;

		if (alice){
			cout<<"ALICE"<<endl;
		}
		else{
			cout<<"BOB"<<endl;
		}
	}
}