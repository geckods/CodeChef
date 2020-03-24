#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool lessthan(vector<int> a, vector<int> b){
	if(a[0]>b[0])return false;
	if(a[0]<b[0])return true;

	for(int i=1;i<10;i++){
		if(a[i]<b[i])return false;
		if(a[i]>b[i])return true;
	}
	return true;
}
map<int,bool> isSqr;

vector<int> coins = {3,8,15,24,35,48,63,80};

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	// it looks like this can be solved with a variant of coin change that tries to minimize the coins used

   	int t;
   	cin>>t;

   	vector<int> squares;

   	int tsq=1;
   	while(tsq*tsq<=9000000){
   		squares.push_back(tsq*tsq);
   		isSqr[tsq*tsq]=true;
   		tsq++;
   	}


   	for(int test=0;test<t;test++){
   		int n;
   		cin>>n;

	   	int firstsq = lower_bound(squares.begin(),squares.end(),n)-squares.begin();
	   	vector<int> target;
	   	while(firstsq<squares.size() && squares[firstsq]<=30*n){//emperical magic. For completeness, this multiplier must be 81, but it is a constant factor slowdown that wasn't letting me pass. gg
	   		target.push_back(squares[firstsq++]);
	   		// cout<<squares[firstsq-1]<<endl;
	   	}
   		// cerr<<test<<" "<<n<<" "<<firstsq<<" "<<target[firstsq]<<endl;

	   	int maxsearch = target[target.size()-1]-n;
	   	// cout<<maxsearch<<endl;
	   	// cerr<<maxsearch<<endl;

	   	// int dp[maxsearch+1][10];
	   	vector<vector<int> > dp(maxsearch+1);
	   	for(int i=0;i<=maxsearch;i++){
	   		dp[i]=vector<int>(10);
	   		dp[i][0]=INT_MAX;
	   	}
	   	// cerr<<"HI"<<endl;

	   	dp[0][0]=0;
	   	vector<int> temp(10);

	   	int currMin=INT_MAX;
	   	multiset<int> mySet;

	   	for(int i=1;i<=maxsearch;i++){
	   		// cout<<i<<endl;
	   		for(int j=0;j<9;j++){
	   			if(coins[j]<=i){
	   				if(dp[i-coins[j]][0]!=INT_MAX){
	   					for(int k=0;k<10;k++){
	   						temp[k]=dp[i-coins[j]][k];
	   					}
	   					temp[0]++;
	   					temp[j+1]++;

	   					if(lessthan(temp,dp[i])){
		   					for(int k=0;k<10;k++){
		   						dp[i][k]=temp[k];
		   					}	   						
	   					}
	   				}
	   			}
	   		}

	   		mySet.insert(dp[i][0]);
	   		if(i>80){
	   			mySet.erase(mySet.find(dp[i-80][0]));
	   		}

	   		if(isSqr[i+n] && dp[i][0]!=INT_MAX){
	   			currMin=min(currMin,dp[i][0]);
	   		}

	   		if(*mySet.begin()>currMin){
	   			break;
	   		}


	   		// cout<<i<<" "<<endl;
	   		// for(int j=0;j<10;j++){
	   		// 	cout<<dp[i][j]<<" ";
	   		// }
	   		// cout<<endl<<endl;
	   	}

	   	temp[0]=INT_MAX;

	   	for(int i=0;i<target.size();i++){
	   		// cout<<target[i]-n<<" "<<endl;
	   		// for(int j=0;j<10;j++){
	   		// 	cout<<dp[target[i]-n][j]<<" ";
	   		// }
	   		// cout<<endl<<endl;

	   		if(lessthan(dp[target[i]-n],temp)){
	   			// cout<<"HI"<<" "<<dp[target[i]]<<endl;
	   			for(int k=0;k<10;k++){
		   			temp[k]=dp[target[i]-n][k];
		   		}
	   		}
	   	}

	   	// cout<<n<<"->"<<endl;
	   	// for(int i=0;i<10;i++){
	   	// 	cout<<temp[i]<<" ";
	   	// }
	   	// cout<<endl<<endl;

	   	if(temp[0]>n){
	   		cout<<-1<<endl;
	   	}
	   	else{
	   		for(int i=0;i<n-temp[0];i++){
	   			cout<<1;
	   		}
	   		for(int i=1;i<10;i++){
	   			for(int j=0;j<temp[i];j++){
	   				cout<<i+1;
	   			}
	   		}
	   		cout<<endl;
	   	}

	   	// dp.clear();
	   	// dp.swap(vector<vector<int> >());

	   	//coins are 3,8,15,24,35,48,63,80



   	}

}