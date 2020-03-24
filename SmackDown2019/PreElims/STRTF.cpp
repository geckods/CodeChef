#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE 30

int main(){
  ll n,q;
 
  cin>>n;
  cin>>q;
  ll arr[n];


//  cout<<"HI"<<endl;

  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }

  ll qarr[q][2];

  for(ll i=0;i<q;i++){
    cin>>qarr[i][0];
    cin>>qarr[i][1];
  }

  //for each bit, i need to see where it starts counting
  //first, store in bitwise representation

//  int thelog = (int)(log(max)/log(2));
  int bitarr[n][SIZE];

  ll curr;
  for(ll i=0;i<n;i++){
    curr = arr[i];
    bitarr[i][SIZE-1] = curr%2;

    for(int j=SIZE-2;j>=0;j--){
      curr = curr/2;
      bitarr[i][j] = curr%2;
    }
  }

/*
  for(int i=0;i<n;i++){
    for(int j=0;j<SIZE;j++){
      cout<<bitarr[i][j]<<" ";
    }
    cout<<endl;
  }
*/

  ll whichbit[SIZE] = {-1};
  ll thestart[SIZE] = {-1};
  for(int i=0;i<SIZE;i++){
    whichbit[i] = -1;
  }

  //cheking where the last 1 is in this bit
  for(int i=0;i<SIZE;i++){
    for(ll j=n-1;j>=0;j--){
      if (bitarr[j][i]==1){
        whichbit[i] = j;
        break;
      }
    }
  }

  for(ll i=0;i<SIZE;i++){
    cout<<whichbit[i]<<" ";
  }
  cout<<endl;

  for(ll i=0;i<SIZE;i++){
    curr = 0;
    if(whichbit[i]==-1||whichbit[i]==0){
      thestart[i]=0;
      continue;
    }
    for(ll j=n-1;j>=0;j--){
      curr+=pow(2,n-1-j)*bitarr[j][i];
    }
    thestart[i] = curr;
  }

  for(ll i=0;i<SIZE;i++){
    cout<<thestart[i]<<" ";
  }
  cout<<endl;

  ll thisx;
  ll thisk;
  ll thisno;
  int thebit;
  int thebitsweneed[SIZE];

  for(ll qn=0;qn<q;qn++){
    thisk = qarr[qn][0];
    thisx = qarr[qn][1];
    for(int i=0;i<SIZE;i++){
      thisno = thestart[i]+(thisk*pow(2,n-whichbit[i]));
      thebit = thisno/pow(2,thisx
//USE ARRAYS
}
