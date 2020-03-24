#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int getDigit(ll N, int k){
//	for(int i=0;i<k;i++){
//		N/=10;
//	}

	N/=(ll)pow(10,k);

	return (N%10);
}

int getLength(ll N){
	int i=0;
	while(getDigit(N,i)!=0) i++;
	return i;
}

ll operate(ll N, int k, int d){
	ll theleft = N%(ll)pow(10,k);
	ll originleft = theleft;
	theleft*=10;
	theleft+=d;
	theleft%=(ll)pow(10,k);
	return N-originleft+theleft;
}


ll minimizeDigit(ll N, int k, int d){
	int minPoss = d;
	int temp;
	for(int i=0;i<=k;i++){
		temp =  getDigit(N,i);
		if(temp<minPoss) minPoss = temp;
	}

//	cout<<"MINPOSS"<<minPoss<<endl;
//	cout<<N<<" "<<k<<" "<<d<<endl;

	ll ans = N;
	int j=0;
	while(getDigit(ans,k) != minPoss){
//		cout<<ans<<endl;
//		cout<<minPoss<<endl;
//		cout<<getDigit(ans,k)<<endl;
		ans = operate(ans,k+1,d);
		j++;
		if(j==k+1) break;
	}

	return ans;
}



int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

//    cout<<"HI"<<endl;
//    cout<<operate(123456789,0,1)<<endl;
//    cout<<minimizeDigit(123456789,8,1)<<endl;


    int t;
    cin>>t;

    ll N;
    int d;
    int length;

    for(int test=0;test<t;test++){
    	cin>>N>>d;
    	length = getLength(N);
    	for(int i=length-1;i>=0;i--){
//    		cout<<i<<endl;
    		N = minimizeDigit(N,i,d);
    	}
    	cout<<N<<endl;
    }
}

/*PSEUDOCODE

Main:
For each test case:
	Read n,d
	Determine the length of N (number of digits)
	For length-1 down to 0 as i
		Minimize the ith least significant digit(ith digit from the right, zero indexed) (call minimizeDigit(N,i,d))
	EndFor
EndFor
EndMain

minimizeDigit(N,i,d):
	#determine the lowest that you can possibly make the ith least significant digit as follows
	min = d
	for j from 0 to i(inclusive)
		let x be the jth digit of N
		min = x if x<mix
	endfor

	#after having determined the minimum, simply perform the operation repeatedly until the digit in question becomes that minimum
	while(the ith least significant digit is not equal to min)
		operate(N,i,d) #this will delete the i'th digit and append d to the right of N
	endwhile
endfunction
*/