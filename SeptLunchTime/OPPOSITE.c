#include <stdio.h>
typedef long long ll;

int main(){
  ll t;
  scanf("%lld",&t);
  ll n,edge1,edge2,opp;
  int flag = 0;
  
  for(ll i =0;i<t;i++){
    scanf("%lld",&n);
    ll arr[n];
    ll newarr[n];
    for(ll j=0;j<n;j++){
      scanf("%lld",&arr[j]);
//      getchar();
    }
//    putchar('\n');

    for(ll j=0;j<n/2;j++){
      opp = j+n/2;
      edge1 = arr[j];
      edge2 = arr[opp];
      //printf("%lld %lld %lld %lld\n",j,edge1,opp,edge2);

      if (edge1!=-1){
        if (edge2!=-1){
          if(edge1==edge2){
            newarr[j] = newarr[opp] = edge1;
          }
          else{
            flag = 1;
            break;
          }
        }
        else{
          newarr[opp] = newarr[j] = edge1;
        }
      }
      else{
        if (edge2==-1){
          newarr[j] = newarr[opp] = 1;
        }
        else{
          newarr[j] = newarr[opp] = edge2;
        }
      }
    }

    if (flag){
      flag = 0;
      printf("NO\n");
      continue;
    }
    
    printf("YES\n");
    for(ll j=0;j<n;j++){
      printf("%lld ",newarr[j]);
    }
    putchar('\n');
  }
}
