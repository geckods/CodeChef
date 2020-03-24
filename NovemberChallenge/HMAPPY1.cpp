#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxof(ll a,ll b,ll c){
  if (a>=b && a>=c){
    return a;
  }
  else if (b>=c){
    return b;
  }
  else{
    return c;
  }
}

ll minof(ll a,ll b){
  if (a<b){
    return a;
  }
  else{
    return b;
  }
}

int longest(vector<int> arr){
  int currcount = 0;
  int maxcount = 0;
  int x;
  for(int i=0;i<arr.size();i++){
    x = arr[i];
    if (x==1){
      currcount+=1;
    }
    else{
      if (currcount>maxcount){
        maxcount = currcount;
      }
      currcount=0;
    }
  }
  if (currcount>maxcount){
    maxcount = currcount;
  }
  return maxcount;
}

int main(){
  ll n,q,k;
  cin>>n;
  cin>>q;
  cin>>k;

  int arr[n];
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }

  int qarr[q];
  char qtype;

  for(ll i=0;i<q;i++){
    cin>>qtype;
    if (qtype=='!'){
      qarr[i] = 0;
    }
    else {
      qarr[i] = 1;
    }
  }


  if(n<=1000){
    vector<int> vecarr;
    for(int i=0;i<n;i++){
      vecarr.push_back(arr[i]);
    }
    for(int i=0;i<q;i++){
      if(qarr[i]==1){
        cout<<min((ll)longest(vecarr),k)<<endl;
      }
      else{
        rotate(vecarr.begin(), vecarr.begin()+vecarr.size()-1, vecarr.end());
      }
    }
    exit(0);
  }


//  cout<<endl;
/*
  for(ll i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  for(ll i=0;i<q;i++){
    cout<<qarr[i]<<" ";
  }
  cout<<endl;
*/
  ll startlen;
  int startdone = 0;

  ll longstart;
  ll longend;
  ll longlen=0;

  ll secstart;
  ll secend;
  ll seclen=0;

  ll currstart;
  ll currend;
  ll currlen;
  int inseq = 0;

  for(ll i=0;i<n;i++){
//    cout<<"SEQ: "<<inseq<<" currstart: "<<currstart<<" i: "<<i<<endl; 

    if(!startdone && arr[i] == 0){
      startlen = i-1;
      startdone = 1;
    }

    if(inseq){
      if(arr[i] == 0){
        currend = i-1;
        inseq = 0;
        //assign the sequence here
	currlen = currend-currstart+1;
	if(currlen>longlen){
          longlen = currlen;
          longstart = currstart;
          longend = currend;
        }
        else if (currlen>seclen){
          seclen = currlen;
          secstart = currstart;
          secend = currend;
        }
      }
    }
    else{
      if(arr[i]==1){
        currstart = i;
        inseq = 1;
      }
    }
  }

  //if the last number was 1 and the first number was 1
  if(inseq && !(currstart==0)){
    currlen = n-currstart+startlen+1;
    currend = startlen;
    if (currend == -1) currend = n-1;
    //sequpdate
    if(currlen>longlen){
      longlen = currlen;
      longstart = currstart;
      longend = currend;
    }
    else if (currlen>seclen){
      seclen = currlen;
      secstart = currstart;
      secend = currend;
    }
  }

  if (currstart==0 && inseq){
    longlen = n;
    longstart = 0;
    longend = n-1;
  }

//  cout<<"Longest: "<<longstart<<" to "<< longend <<", length = "<<longlen<<endl;
//  cout<<"Second: "<<secstart<<" to "<< secend <<", length = "<<seclen<<endl;

  ll part1;
  ll part2;

  ll currbreak = 0;//the break point is just before this part
  for(ll i=0;i<q;i++){
//    cout<<"COUNT: "<<currbreak<<endl;
    if (qarr[i]==0){
      currbreak--;
      if (currbreak<0) currbreak += n;
    }
    else{
      if ( ((longstart<=longend) && (currbreak<=longstart || currbreak>longend))/*it is a normal sequence not being broken*/ || ((longstart>longend)&&(currbreak>longend && currbreak<=longstart)) )/*wraparoundsequence,not being broken*/
 	cout<<minof(longlen,k)<<endl;
      else{
        if (longstart<=longend){ //normal sequence being broken
//          cout<<"HI"<<endl;
          part1 = currbreak-longstart;
          part2 = longlen-part1;
        }
        else { //wraparound sequence being broken
          if(currbreak<=longend){
            part1 = longend-currbreak+1;
            part2 = longlen-part1;
          }
          else {
            part1 = currbreak-longstart;
            part2 = longlen-part1;
          }
        }

//	cout<<"K:      "<<k<<endl;
	if(longlen==0) part1 = part2 = 0;
	if(longlen==n) part1 = part2 = n;
        cout<<minof(k,maxof(part1,part2,seclen))<<endl;
      }
    }
  }
}
