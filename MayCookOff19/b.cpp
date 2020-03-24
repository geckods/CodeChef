#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



  
/* function for exchanging two rows of 
   a matrix */
void swap(int** mat, int row1, int row2, 
          int col, int k) 
{ 
    for (int i = 0; i < col; i++) 
    { 
        int temp = mat[row1][i]; 
        mat[row1][i] = mat[row2][i]; 
        mat[row2][i] = temp; 
    } 
} 
  
// Function to display a matrix 
//void display(int mat[R][C], int row, int col); 
  
/* function for finding rank of matrix */
int rankOfMatrix(int** mat,int k) 
{ 
	int R,C;
	R=C=k;
    int rank = C; 
  
    for (int row = 0; row < rank; row++) 
    { 
        // Before we visit current row 'row', we make 
        // sure that mat[row][0],....mat[row][row-1] 
        // are 0. 
  
        // Diagonal element is not zero 
        if (mat[row][row]) 
        { 
           for (int col = 0; col < R; col++) 
           { 
               if (col != row) 
               { 
                 // This makes all entries of current 
                 // column as 0 except entry 'mat[row][row]' 
                 double mult = (double)mat[col][row] / 
                                       mat[row][row]; 
                 for (int i = 0; i < rank; i++) 
                   mat[col][i] -= mult * mat[row][i]; 
              } 
           } 
        } 
  
        // Diagonal element is already zero. Two cases 
        // arise: 
        // 1) If there is a row below it with non-zero 
        //    entry, then swap this row with that row 
        //    and process that row 
        // 2) If all elements in current column below 
        //    mat[r][row] are 0, then remvoe this column 
        //    by swapping it with last column and 
        //    reducing number of columns by 1. 
        else
        { 
            bool reduce = true; 
  
            /* Find the non-zero element in current 
                column  */
            for (int i = row + 1; i < R;  i++) 
            { 
                // Swap the row with non-zero element 
                // with this row. 
                if (mat[i][row]) 
                { 
                    swap(mat, row, i, rank,k); 
                    reduce = false; 
                    break ; 
                } 
            } 
  
            // If we did not find any row with non-zero 
            // element in current columnm, then all 
            // values in this column are 0. 
            if (reduce) 
            { 
                // Reduce number of columns 
                rank--; 
  
                // Copy the last column here 
                for (int i = 0; i < R; i ++) 
                    mat[i][row] = mat[i][rank]; 
            } 
  
            // Process this row again 
            row--; 
        } 
  
       // Uncomment these lines to see intermediate results 
       // display(mat, R, C); 
       // printf("\n"); 
    } 
    return rank; 
} 

void convertto(int arr[], ll num, int k){
	for(int i=0;i<k;i++){
		arr[i]=num%2;
		num/=2;
	}
}

// void display(int mat[R][C], int row, int col) 
// { 
//     for (int i = 0; i < row; i++) 
//     { 
//         for (int j = 0; j < col; j++) 
//             printf("  %d", mat[i][j]); 
//         printf("\n"); 
//     } 
// }


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll k,m;
    	cin>>k>>m;

    	ll arr[m];
    	set<ll> mySet;
    	for(int i=0;i<m;i++){
    		cin>>arr[i];
    		mySet.insert(arr[i]);
    	}

    	int kcop=k;

    	set<ll> newSet;
    	int asd=0;
    	newSet.insert(0);
		set<ll>::iterator iter;

//		fprintf(stderr, "AAA\n");
		int **myarr=(int**)malloc(sizeof(int*)*k);
		for(int i=0;i<k;i++){
			myarr[i]=(int*)malloc(sizeof(int)*k);
			for(int j=0;j<k;j++){
				myarr[i][j]=0;
			}
		}

		int myarrind=0;

		for(iter=mySet.begin();iter!=mySet.end();iter++)
		{
			bool done=false;

			convertto(myarr[myarrind],*iter,k);
			if(rankOfMatrix(myarr,k)<myarrind+1){
				done=true;
			}

			if(done){
			}
			else{
//				newSet.insert(*iter);
				kcop--;
				convertto(myarr[myarrind++],*iter,k);
			}
		}
		cout<<pow(2,kcop)<<endl;

/*
    	int bits[30] = {0};
    	int asd;

		set<int>::iterator iter;
		for(iter=mySet.begin();iter!=mySet.end();iter++)
		{
			asd = *iter;
			for(int i=0;i<30;i++){
				if(asd%2==1) bits[i]=1;
				asd/=2;				
			}
		}

		int bitcount=0;
		for(int i=0;i<30;i++) bitcount+=bits[i];

		kcop-=min(bitcount,(int)mySet.size());
		cout<<pow(2,kcop)<<endl;
*/
    	
    }
}