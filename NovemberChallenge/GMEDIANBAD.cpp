#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int modinverses[1001];
int factorials[1001];

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

int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
}

int nCrModPFermat(int n, int r, int p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
/*
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    int fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
*/  
    return (factorials[n]* modInverse(factorials[r], p) % p * 
            modInverse(factorials[n-r], p) % p) % p;
}
  


int main(){

  for(int i=0;i<1001;i++){
    modinverses[i] =  modInverse(i,MOD);
  }

  factorials[0] = 1;
  for(int i=1;i<1001;i++){
    factorials[i] = (factorials[i-1]*i)%MOD;
  }


//  cout<<factorials[7]<<endl;
//  cout<<"DEBUG:"<<nCrModPFermat(8,1,MOD)<<endl;

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
        for(int j=0;j<=toloop;j++){

//	  cout<<"a"<<(power(2,freqarr[element]-1,MOD)-1)<<endl;
//	  cout<<"b"<<nCrModPFermat(lessarr[element],j,MOD)<<endl;
//          cout<<"c"<<nCrModPFermat(greaterarr[element],j,MOD)<<endl;

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
    cout<<ans<<endl;

  }
}
