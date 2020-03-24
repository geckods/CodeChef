#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
   		int n;
   		cin>>n;

   		string s;
   		int arr[10];
   		memset(arr,0,sizeof(arr));

   		for(int i=0;i<n;i++){
   			cin>>s;
   			for(int j=0;j<10;j++){
   				if(s[j]=='1')arr[j]^=1;
   			}
   		}

   		int ans=0;
   		for(int i=0;i<10;i++){
   			if(arr[i])ans++;
   		}

   		cout<<ans<<endl;
   	}
}
