/*
I think an O(n^2) should be possible
For every starting index, build an array of size 1, evaluate condition(check if the array is "beautiful").
Then add the next number. Adding the next number should be a constant time operation if correctly implemented.

Looks like this isn't going to work
I need to use the fact that there are only 2000 Ai
The current pointed to can be specified by a number in the A range, and whichth of that number it points to i.e. a pair of ints

*/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int t,n,k;
    cin>>t;


    for(int test=0;test<t;test++){
    	cin>>n>>k;
    	int arr[n];
    	for(int i=0;i<n;i++){

    	}
	    for(int start=0;start<)
	}