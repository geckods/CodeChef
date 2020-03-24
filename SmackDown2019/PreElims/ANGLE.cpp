#include <bits/stdc++.h>
using namespace std;
#include <cmath>

int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        // If the element is present at the middle  
        // itself 
        if (arr[mid] == x)   
            return mid; 
  
        // If element is smaller than mid, then  
        // it can only be present in left subarray 
        if (arr[mid] > x)  
          return binarySearch(arr, mid+1, r, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, l, mid-1, x); 
   } 
  
   // We reach here when element is not  
   // present in array 
   return -1; 
} 


int main(){
  int t;
  cin>>t;

  for(int test=0;test<t;test++){
    int n,p,q;
    cin>>n;
    cin>>p;
    cin>>q;

    double ratio = double(p)/double(q);
    double otherside;
    int tofind;
    int location;

    int arr[n];
    for(int i=0;i<n;i++){
       cin>>arr[n-i-1];
    }

    for(int i=0;i<n;i++){
      int j;
      for(j=i+1;j<n;j++){
        if( ((double)arr[j]/(double)arr[i]) < ratio ) break;
      }
      
      for(int a=i+1;a<j;a++){
	otherside = pow(arr[i],2)+pow(arr[a],2)-2*arr[a]*arr[i]*
        otherside = arr[i]*sin(acos((double)arr[a]/(double)arr[i]));
        tofind = round(otherside);
        cout<<(acos((double)arr[a]/(double)arr[i]))<<endl;
        cout<<arr[i]<<" "<<arr[a]<<" "<<tofind<<endl;
        location = binarySearch(arr,0,n-1,tofind);
        if(location == -1) continue;
        cout<<i<<" "<<a<<" "<<location<<endl;
        return 0;
      }
    }
  }
}
