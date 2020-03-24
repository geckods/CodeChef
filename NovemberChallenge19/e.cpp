#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<char,int> isVowel;


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	isVowel['a']=isVowel['e']=isVowel['i']=isVowel['o']=isVowel['u']=1;

   	int t;
   	cin>>t;
   	for(int test=0;test<t;test++){
   		int l;
   		cin>>l;
   		vector<string> myVec;
   		string s;
   		for(int i=0;i<l;i++){
   			cin>>s;
   			myVec.push_back(s);
   		}

   		vector<string> aliceVec;
   		vector<string> bobVec;


   		int lastcons=-3;
   		bool isAlice=true;
   		for(int i=0;i<l;i++){
   			isAlice=true;
   			lastcons=-3;

   			for(int j=0;j<myVec[i].length();j++){
   				if(!isVowel[myVec[i][j]]){
   					if(j-lastcons<3){
   						isAlice=false;
   						break;
   					}
   					else{
   						lastcons=j;
   					}
   				}
   			}

   			if(isAlice){
   				aliceVec.push_back(myVec[i]);
   			}
   			else{
   				bobVec.push_back(myVec[i]);
   			}
   		}

   		// cout<<aliceVec.size()<<" "<<bobVec.size()<<endl;


   		int numRecA[26];
   		int totOccA[26];

   		int numRecB[26];
   		int totOccB[26];

   		for(int i=0;i<26;i++){
   			numRecA[i]=numRecB[i]=totOccB[i]=totOccA[i]=0;
   		}

   		for(int i=0;i<aliceVec.size();i++){
   			unordered_set<char> mySet;
   			for(int j=0;j<aliceVec[i].size();j++){
   				totOccA[aliceVec[i][j]-'a']++;
   				mySet.insert(aliceVec[i][j]);
   			}

   			for(unordered_set<char>::iterator i = mySet.begin();i!=mySet.end();i++){
   				numRecA[*i-'a']++;
   			}
   		}


   		for(int i=0;i<bobVec.size();i++){
   			unordered_set<char> mySet;
   			for(int j=0;j<bobVec[i].size();j++){
   				mySet.insert(bobVec[i][j]);
   				totOccB[bobVec[i][j]-'a']++;
   			}

   			for(unordered_set<char>::iterator i = mySet.begin();i!=mySet.end();i++){
   				numRecB[*i-'a']++;
   			}
   		}

/*
   		double aScoreNum=1;
   		double aScoreDenom=1;

   		double bScoreNum=1;
   		double bScoreDenom=1;


   		// for(unordered_map<char,int>::iterator i = numRecA.begin();i!=numRecA.end();i++){
   		// 	aScoreNum*=i->second;
   		// }

   		for(int i=0;i<26;i++){
   			if(numRecA[i]>0)aScoreNum*=numRecA[i];
   		}

   		// for(unordered_map<char,int>::iterator i = numRecB.begin();i!=numRecB.end();i++){
   		// 	bScoreNum*=i->second;
   		// }

   		for(int i=0;i<26;i++){
   			if(numRecB[i]>0)bScoreNum*=numRecB[i];
   		}


   		// for(unordered_map<char,int>::iterator i = totOccA.begin();i!=totOccA.end();i++){
   		// 	aScoreDenom*=i->second;
   		// }

   		for(int i=0;i<26;i++){
   			if(totOccA[i]>0)aScoreDenom*=totOccA[i];
   		}


   		// for(unordered_map<char,int>::iterator i = totOccB.begin();i!=totOccB.end();i++){
   		// 	bScoreDenom*=i->second;
   		// }

   		for(int i=0;i<26;i++){
   			if(totOccB[i]>0)bScoreDenom*=totOccB[i];
   		}


   		aScoreDenom=pow(aScoreDenom,aliceVec.size());
   		bScoreDenom=pow(bScoreDenom,bobVec.size());

   		if(bobVec.size()==0){
   			cout<<"Infinity"<<endl;
   			continue;
   		}


   		double ans = ((double)bScoreDenom/aScoreDenom)*((double)aScoreNum/bScoreNum);
   		if(ans<=1e7){
	   		cout<<setprecision(15)<<ans<<endl;
   		}
   		else{
   			cout<<"Infinity"<<endl;
   			continue;
   		}
*/

   		//I can probably do some fancy two pointers type multiplication, with 1e7 as a limit

   		if(bobVec.size()==0){
   			cout<<"Infinity"<<endl;
   			continue;
   		}


   		vector<ll> num;
   		vector<ll> denom;

   		ll as = aliceVec.size();
   		ll bs = bobVec.size();

   		for(int i=0;i<26;i++){
   			if(numRecA[i]>0)num.push_back(numRecA[i]);
   		}

   		for(int i=0;i<26;i++){
   			if(numRecB[i]>0)denom.push_back(numRecB[i]);
   		}

   		for(int i=0;i<26;i++){
   			if(totOccA[i]>0){
	   			for(int j=0;j<as;j++){
	   				denom.push_back(totOccA[i]);
	   			}
	   		}
   		}

   		for(int i=0;i<26;i++){
   			if(totOccB[i]>0){
	   			for(int j=0;j<bs;j++){
	   				num.push_back(totOccB[i]);
	   			}
	   		}
   		}

   		double ans=1;
   		int i=0;
   		int j=0;

   		int ns = num.size();
   		int ds = denom.size();

   		//this sorting makes it TLE
   		// sort(num.begin(),num.end());
   		// sort(denom.begin(),denom.end());

   		while(i<ns || j<ds){
   			if(j==ds || (i<ns && ans<1e7)){
   				ans*=num[i++];
   			}
   			else{
   				ans/=denom[j++];
   			}

   			if(j==ds && ans>=1e7){
   				break;
   			}
   		}

   		if(ans>1e7){
   			cout<<"Infinity"<<endl;
   		}
   		else{
   			cout<<setprecision(15)<<ans<<endl;
   		}


   	}
}