#include <bits/stdc++.h>
using namespace std;


int min(int a, int b){
  if (a<b) return a;
  return b;
}

int givesquare(int a, int b, int x, int y, int n, int m){
  int ans=0;

  if (a==x && b==y){
    return 0;
  }

  if (b==y && x<a){
    ans += a-x-1;
  }
  else{
    ans += a-1;
  }

  if (b==y && x>a){
    ans += x-a-1;
  }
  else{
    ans += n-a;
  }


  if (a==x && y>b){
    ans += y-b-1;
  }
  else{
    ans += m-b;
  }

  if (a==x && y<b){
    ans += b-y-1;
  }
  else{
    ans += b-1;
  }

  if ((x-y == a-b) && x<a){
    ans += a-x-1;
  }
  else{
    ans += min(a-1,b-1);
  }

  if ((x-y == a-b) && x>a){
    ans += x-a-1;
  }else{
    ans += min(n-a,m-b);
  }

  if ((x+y == a+b) && y>b){
    ans += y-b-1;
  }else{
    ans += min(a-1,m-b);
  }

  if ((x+y == a+b) && y<b){
    ans += b-y-1;
  }else{
    ans += min(n-a,b-1);
  }

  return ans;
}

int main(){
  int t;
  cin>>t;
  int arr[t][4];
  for(int i=0;i<t;i++){
    cin>>arr[i][0];
    cin>>arr[i][1];
    cin>>arr[i][2];
    cin>>arr[i][3];
  }

  int n,m,x,y,asdf,ans=0;
  for(int i=0;i<t;i++){
    ans = 0;
    n = arr[i][0];
    m = arr[i][1];
    x = arr[i][2];
    y = arr[i][3];
    asdf = (n*m)-2;
    

    for(int a=1;a<=n;a++){
      for(int b=1;b<=m;b++){
        if(a==x && b==y) continue;
        ans += asdf-givesquare(a,b,x,y,n,m);
      }
    }
    cout<<ans<<endl;
  }
}
