/*
PRIMES
    2
   3
  5
 7
11
00011
00110
00101
01100
01001
01010
11000
10001
10010
10100
*/

#include <bits/stdc++.h>
#define MAX 700000
using namespace std;

bool prime[MAX + 1]; 
void SieveOfEratosthenes(){ 
    memset(prime, true, sizeof(prime));
  
    prime[1] = false; 
  
    for (int p = 2; p * p <= MAX; p++) { 
  
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) { 
  
            // Set all multiples of p to non-prime 
            for (int i = p * 2; i <= MAX; i += p) 
                prime[i] = false; 
        } 
    } 
}


/*
int main(){
	//generate the first N prime numbers
	//N is at max 50,000, and the 50000th prime is 611953, so max can be 700000
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	
	SieveOfEratosthenes();
    int t,n;
    cin>>t;
    for(int test=0;test<t;test++){
    	cin>>n;
    	long long prevprime = 2;
    	long long newnum,asd;
//    	cout<<prevprime<<" ";
    	for(int i=0;i<n;i++){
    		asd =  prevprime+1;
    		if(prevprime!=2) asd+=1;
    		if((i==n-2 || i==n-1) && asd%3==0) asd+=2;
//    		if(asd%9==0) asd+=2;
//    		while(!prime[asd]) asd++;

    		if (i==n-1){
//    			if (prevprime%3==0) newnum/= prevprime;
    			newnum=prevprime*asd*2;
    		}
    		else{
	    		newnum = prevprime*asd;
	    	}
    		cout<<newnum<<" ";
    		prevprime = asd;
    	}
    	cout<<endl;
    }
}

int main(){
	//generate the first N prime numbers
	//N is at max 50,000, and the 50000th prime is 611953, so max can be 700000
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	
	SieveOfEratosthenes();

	int primes[50000];
	int a=1;
	for(int i=0;i<50000;i++){
		//get the ith prime
		do{
			a++;
		} while (!prime[a]);
		primes[i] = a;
//		cout<<a<<endl;
	}
//	return 0;

	int t,n,count,b,ans,i;
    cin>>t;
    for(int test=0;test<t;test++){
    	cin>>n;
    	count = 0;
		a = 1;
		b = a-1;
		i = 1;
		while(count<n-1){
			ans = primes[a]*primes[b];
			cout<<ans<<" ";//<<count<<endl;
			a+=i;
			b = a-i;
			count++;
			if(primes[a]*primes[b]>1000000000){
				cout<<primes[b]*2<<" ";
				count++;
				i++;
				a = i;
				b = 0;
			}
		}
		if (count==n-1){
			ans=primes[b]*2;
			cout<<ans<<" ";
		}
		cout<<endl;
	}
}
*/

int main(){
	//generate the first N prime numbers
	//N is at max 50,000, and the 50000th prime is 611953, so max can be 700000
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	
	SieveOfEratosthenes();

	int primes[50000];
	int a=1;
	for(int i=0;i<50000;i++){
		//get the ith prime
		do{
			a++;
		} while (!prime[a]);
		primes[i] = a;
//		cout<<a<<endl;
	}
//	return 0;

	int t,n,count,b,ans,i;
    cin>>t;
    for(int test=0;test<t;test++){
    	cin>>n;
    	if(n==3){
    		cout<<"6 10 15"<<endl;
    		continue;
    	}
    	int primeno = 3;
    	bool  startwithtwo = true;
    	bool usingtwo = true;
    	bool prevusedtwo = true;
    	bool prevprevusedtwo = true;
    	bool justswitched = false;

    	int arr[n];
    	arr[0]=6;

    	for(int i=1;i<n-1;i++){
    		if (usingtwo){
    			arr[i]=primes[primeno]*2;
    			prevprevusedtwo = prevusedtwo;
    			prevusedtwo = true;
    			usingtwo = false;
    			justswitched = false;
    			if (!startwithtwo){
    				justswitched = true;
    				primeno++;
    				startwithtwo = true;
    				usingtwo = true;
    			}
    		}
    		else{
    			arr[i]=primes[primeno]*3;
    			prevprevusedtwo = prevusedtwo;
    			prevusedtwo = false;
    			usingtwo = true;
    			justswitched = false;
    			if (startwithtwo){
    				justswitched = true;
    				primeno++;
    				startwithtwo = false;
    				usingtwo = false;
    			}
    		}
    	}

    	if(justswitched){
    		if(prevusedtwo){
    			arr[n-2]=primes[primeno-1]*5;
    			arr[n-1]=15;
    			arr[0]=6;
    			//make n-2 = prime*5
    			//make n-1 = 5*3
    			//make 0 = 2*3
    		}
    		else{
    			arr[n-1]=15;
    			arr[0]=10;
    			//make n-1 3*5
    			//make 0 = 2*5
    		}
    	}
    	else{
    		if(prevusedtwo){
    			arr[n-1]=primes[primeno]*3;
    			arr[0]=6;
    			//n-1 prime+1 * 3
    			//0  = 2*3
    		}
    		else{
    			arr[n-1]=primes[primeno]*5;
    			arr[0]=10;
    			//n-1 is prime+1 * 5
    			//0 = 10
    		}
    	}

    	for(int i=0;i<n;i++){
    		cout<<arr[i]<<' ';
    	}

    	cout<<endl;
	}
}
