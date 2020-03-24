#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    ll gans=0;
    while(t--){
    	int n;
    	cin>>n;
    	int arr[4][4];
    	for(int i=0;i<4;i++){
    		for(int j=0;j<4;j++){
    			arr[i][j]=0;
    		}
    	}

    	char c;
    	int x;
    	for(int i=0;i<n;i++){
    		cin>>c>>x;
    		arr[c-'A'][x/3 - 1]++;
    	}


    	int ans=INT_MIN;

    	for(int i=0;i<4;i++){
    		for(int j=0;j<4;j++){
    			if(i==j)continue;
    			for(int k=0;k<4;k++){
    				if(i==k||j==k)continue;
    				int l=6-i-j-k;

    				vector<int> temp;
    				temp.push_back(arr[0][i]);
    				temp.push_back(arr[1][j]);
    				temp.push_back(arr[2][k]);
    				temp.push_back(arr[3][l]);
    				sort(temp.begin(),temp.end());
    				int minians=0;
    				for(int z=0;z<4;z++){
    					minians+=temp[z]*25*(z+1);
    					if(temp[z]==0)minians-=100;
    				}
    				ans=max(ans,minians);

    			}
    		}
    	}
    	gans+=ans;
    	cout<<ans<<endl;

    }
    cout<<gans<<endl;
}