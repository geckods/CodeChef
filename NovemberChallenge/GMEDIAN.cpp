#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
const int N = 10001;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 


ll factorialNumInverse[N + 1]; 
  
// array to precompute inverse of 1! to N! 
ll naturalNumInverse[N + 1]; 
  
// array to store factorial of first N numbers 
ll fact[N + 1]; 
  
// Function to precompute inverse of numbers 
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    // precompute inverse of natural numbers 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
// Function to calculate factorial of 1 to N 
void factorial(ll p) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
// Function to return nCr % p in O(1) time 
ll Binomial(ll N, ll R, ll p) 
{ 
    if (R>N) return 0;
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 


int main(){
    ll p = MOD; 
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);

//  cout<<factorials[7]<<endl;
//  cout<<"DEBUG:"<<Binomial(3,2,MOD)<<endl;

//  cout<<power(2,34,MOD)<<endl;
  int t,n;
  cin>>t;
  ll ans;
  for(int test = 0;test<t;test++){

    set<ll> theset;

    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
//    cout<<"READY"<<endl;
    ans = power(2,n-1,MOD);
    
    sort(arr,arr+n);
    int freqarr[2001];
    int lessarr[2001];
    int greaterarr[2001];

    for(int i=0;i<2001;i++){
      freqarr[i]=0;
    }

    for(int i=0;i<n;i++){
      freqarr[arr[i]]++;
    }

    int theind = 0;
    int done = 0;
    for(int i=0;i<2001;i++){
      while(arr[theind]<i){
        if (done) break;
	theind++;
        if(theind==n) done = true;
      }
      lessarr[i] = theind;
    }

    for(int i=0;i<2001;i++){
      greaterarr[i] = n-freqarr[i]-lessarr[i];
    }

/*    cout<<"GOTTEN HERE"<<endl;
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" "<<lessarr[arr[i]]<<" "<<freqarr[arr[i]]<<" "<<greaterarr[arr[i]]<<endl;
    }
*/

    set<int> seen;

    int element,less,freq,great,currlen,init,tocompute;
    for(int i=0;i<n;i++){
      element = arr[i];
      freq = freqarr[element];
      less = lessarr[element];
      great = greaterarr[element];
      if (seen.find(element) == seen.end()){//new element
        for(int nocen = 2;nocen<=freq;nocen++){
	  for(int noleft = 0;noleft<=less;noleft++){
            currlen = nocen+noleft;
            if (currlen%2==0){
              if ((noleft-nocen)%2==0){
                init = noleft-nocen;
              }
              else{
                init = noleft-nocen+1;
              }
            }
            else{
              if ((noleft-nocen)%2==0){
                init = noleft-nocen+1;
              }
              else{
                init = noleft-nocen;
              }
            }
            for(int noright = init+2;noright<currlen;noright+=2){
              if (noright<0) continue;
              tocompute = ((Binomial(freq,nocen,MOD)*Binomial(less,noleft,MOD))%MOD)*Binomial(great,noright,MOD);
//              cout<<nocen<<" "<<noleft<<" "<<noright<<" "<<tocompute<<endl;
//              cout<<"FREQ: "<<freq<<" LESS "<<less<<" MORE "<<great<<endl;
              ans+=tocompute%MOD;
              ans = ans%MOD;
            }
          }
        }
        seen.insert(element);
      }
    }


/*THIS IS INSUFFICIENT
    set<int> seen;

    //this part is for taking only even amongst the repeated things
    int element,toloop,less,great,freq,toadd,denom,denom1,denom2;
    for(int i=0;i<n;i++){
      element = arr[i];
      if (seen.find(element) == seen.end()){//new element
        toloop = min(lessarr[element],greaterarr[element]);
//        cout<<"element: "<<element<<" toloop: "<<toloop<<endl;
        less = lessarr[element];
        great = greaterarr[element];
        freq = freqarr[element];
        toadd = ((power(2,freq-1,MOD)-1)*factorials[less]*factorials[great])%MOD;

	denom = 1;
        for(int j=0;j<=toloop;j++){//j is the number of things we select on either side

	  if (j>0){
       	    denom = denom*power(j,2,MOD)*(less-j)*(great-j);
	    if(denom==0){
              denom1 = denom*power(j,2,MOD)*(great-j);
              denom2 = denom*power(j,2,MOD)*(less-j);
              denom = max(denom1,denom2);
            }
            if(denom==0){
              ans+=(power(2,freq-1,MOD)-1);
            }
            else{
              ans+=((toadd)/(modInverse(denom,MOD)%MOD))%MOD;
            }
          }
          else if (j==0){
//            cout<<"freq"<<freq<<endl;
            ans+=(power(2,freq-1,MOD)-1);
          }
          ans=ans%MOD;
        }
	seen.insert(element);
      }
      else{
        continue;
      }
    }
*/
    cout<<ans<<endl;

  }
}
