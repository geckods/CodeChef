#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int substrcount(string s, string sub, vector<int> start){
	int thestart;
	int count=0;
	int mainlen=s.length();
	int len=sub.length();
	int theflag;
	for(int i=0;i<start.size();i++){
		thestart = start[i];
		theflag=1;
//		cout<<thestart<<" ";
		if(thestart>mainlen-len) continue;
		for(int j=0;j<len;j++){
			if(s[thestart+j]!=sub[j]){
				theflag=0;
				break;
			}
		}

		if(theflag){
			count++;
		}
	}
//	cout<<endl;
	return count;
}

int binsearch(string s, vector<int> start, int l, int r, int x,int prevmid){
	int mid=l+(r-l)/2;
//	cout<<mid<<endl;
	if(mid==prevmid){
		return mid-1;
	}
	if(substrcount(s,s.substr(0,mid),start)==x){
		if(substrcount(s,s.substr(0,mid+1),start)<x){
			return mid;
		}
		else{
			return binsearch(s,start,mid,r,x,mid);	
		}
	}
	else{
		return binsearch(s,start,l,mid,x,mid);
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t,n,icount;
    string s;
    cin>>t;
    char ch;

    //in O(n) time, you can find the number of occurances of a prefix
    //First count the number of occurances of the first letter
    //After that, binary search for the end of the prefix that occurs the same number of times (nlogn)

    vector<int> vec;

    for(int test=0;test<t;test++){
    	cin>>n;
    	cin>>s;
    	ch=s[0];
    	icount=0;
    	vec.clear();
    	for(int i=0;i<n;i++){
    		if(ch==s[i]){
    			vec.push_back(i);
    			icount++;
    		}
    	}

//    	cout<<icount<<endl;
    	if(icount==1){
    		cout<<s<<endl;
    	}
    	else{
	    	cout<<s.substr(0,binsearch(s,vec,0,s.length(),icount,-1))<<endl;
	    }
    }
}