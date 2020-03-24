#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    char names[n+1][101];

    for(int i=0;i<=n;i++){
    	cin>>names[i];
    }

    char* lastname = names[n];

    int minnumbef=0;
    int maxnumbef=0;

    bool hasast;
    char ch;
    int j;
    int compare;
    for(int i=0;i<n;i++){
    	hasast = false;
    	j = 0;
    	ch=1;
    	while(ch!=0){
    		ch = names[i][j];
    		if(ch=='*'){
    			hasast = true;
    			break;
    		}
    		j++;
    	}

    	if(!hasast){
    		compare = strcmp(lastname, names[i]);
//    		cout<<compare<<endl;
    		if(compare>0){
    			minnumbef++;
    			maxnumbef++;
    		}
    		else if(compare==0){
    			maxnumbef++;
    		}
    		else{
    		}
    	}
    	else{
    		j=0;
    		while(names[i][j]){
    			if(names[i][j]=='*'){
        //             if(lastname[j]=='z'){
        //                 minnumbef++;
        //                 maxnumbef++;
        //             }
        //             else if (lastname[j]=='a'){
                        
        //             }
    				// maxnumbef++;
    				// break;
    			}
    			else if(names[i][j]<lastname[i]){
    				minnumbef++;
    				maxnumbef++;
    				break;
    			}
    			else if(names[i][j]>lastname[i]){
    				break;
    			}
    			j++;
    		}
            if(names[i][j]) continue;

    		if(strlen(names[i])<strlen(lastname)){
    			minnumbef++;
    			maxnumbef++;
    		}
    		else if (strlen(names[i])==strlen(lastname)){
    			maxnumbef++;
    		}
    		else{
    		}
    	}
    }

    // int minnumbef = n-numaft;
    // int maxnumbef = numbef;

    for(int i=minnumbef;i<=maxnumbef;i++){
    	cout<<i+1<<" ";
    }
    cout<<endl;
}
