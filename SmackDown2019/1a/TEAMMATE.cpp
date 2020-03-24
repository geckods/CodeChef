#include <bits/stdc++.h>
#define million 1000000
#define lakh 100000
#define bilmod 1000000007

using namespace std;
typedef long long ll;




int main(){
  int t,n;
  cin>>t;

  ll lookup[lakh+1];

  ll fact=1;

  for(int i=1;i<lakh+1;i++){
    fact*=i;
    if(i%2==0) fact/=2;
    fact%=bilmod;

    lookup[i]=fact;
  }

  for(int q=0;q<t;q++){
    ll ans=1;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }


    int mainarr[million+1] = {0};
    for(int i=0;i<n;i++){
      mainarr[arr[i]]++;
    }

    for(int i=1;i<million+1;i++){
      if (mainarr[i]!=0){
        ans*=lookup[mainarr[i]];
        ans%=bilmod;
      }
    }

    cout<<ans<<endl;
  }
}
