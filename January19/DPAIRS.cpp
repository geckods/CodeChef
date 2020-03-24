#include <bits/stdc++.h>
using namespace std;

int compare ( const void *pa, const void *pb ) 
{
    const int *a = (const int *)pa;
    const int *b = (const int *)pb;
    if(a[0] == b[0])
        return a[1] - b[1];
    else
        return a[0] - b[0];
}  

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

	int n,m;
	cin>>n;
	cin>>m;

	int narr[n][2];
	int marr[m][2];

	for(int i=0;i<n;i++){
		cin>>narr[i][0];
		narr[i][1] = i;
	}

	for(int i=0;i<m;i++){
		cin>>marr[i][0];
		marr[i][1] = i;
	}

	qsort(narr, n, sizeof narr[0], compare);
	qsort(marr, m, sizeof marr[0], compare);

	//take the largest element in the first pile, and with all elements in the second pile (except the smallest)

	//then take the smallest element in the second pile and with all elements in the first pile except the largest

	for(int i=1;i<m;i++){
		cout<<narr[n-1][1]<<" "<<marr[i][1]<<endl;
	}

	for(int i=0;i<n-1;i++){
		cout<<narr[i][1]<<" "<<marr[0][1]<<endl;
	}

	cout<<narr[n-1][1]<<" "<<marr[0][1]<<endl;
}