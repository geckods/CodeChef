#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
   	freopen("output", "w", stdout);
	#endif

//    cout<<1<<endl;
//    return 0;

    int t,len,numuniq,min,sum,targ;
    string s;
    int alpha[26];

    cin>>t;
    for(int test=0;test<t;test++){
    	cin>>s;
    	len = s.size();
    	for(int i=0;i<26;i++){
    		alpha[i]=0;
    	}


    	for(int i=0;i<len;i++){
    		alpha[s[i]-'A']++;
    	}

    	sort(alpha,alpha+26,greater<int>());

    	for(int i=0;i<26;i++){
    		if(alpha[i]==0){
    			numuniq=i;
    			break;
    		}
    	}

//    	for(int i=0;i<26;i++){
//    		cout<<i<<" "<<alpha[i]<<endl;
//    	}

    	min=INT_MAX;

    	for(int i=1;i<=26;i++){
	    	sum=0;
    		if(len%i==0){
    			//i is a possibility for number of unique chars
    			targ = len/i;
    			
    			for(int j=0;j<i;j++){
    				sum+=abs(alpha[j]-targ);
    			}

    			for(int j=i;j<26;j++){
    				sum+=alpha[j];
    			}

//    			cout<<i<<" "<<targ<<" "<<sum<<endl;

    			if(sum<min) min=sum;
    		}
    	}

    	cout<<min/2<<endl;

    }
}