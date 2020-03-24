#include <bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;

  for(int test=0;test<t;test++){
    int n,m;
    char val;
    int d1,d2,d3,d4;
    cin>>n;
    cin>>m;
 
    vector< vector< char > > matrix;

    getchar();
    for(int i=0;i<n;i++){
      vector<char> row;
      for(int j=0;j<m;j++){
        scanf("%c",&val);
        val = val-'0';
        row.push_back(val);
      }
      getchar();
      matrix.push_back(row);
    }

    int starti = n+m-1;
    int startj = n+m-1;
    int ilimit = 3*n+2*m-2;
    int jlimit = 3*m+2*n-2;
    int asd;

    int tlbr[ilimit][jlimit] = {0};
    for(int i=0;i<ilimit;i++){
      for(int j=0;j<jlimit;j++){
        tlbr[i][j] = 0;
      }
    }

    for(int i=0;i<n;i++) tlbr[starti+i][startj] = matrix[i][0];
    for(int j=0;j<m;j++) tlbr[starti][startj+j] = matrix[0][j];

    for(int i=1;i<ilimit-starti;i++){
      for(int j=1;j<jlimit-startj;j++){
        if(i>=n || j>=m) asd = 0;
        else asd=matrix[i][j];
        tlbr[starti+i][startj+j] = asd+tlbr[starti+i-1][startj+j-1];
      }
    }
//    return 0;

    int trbl[ilimit][jlimit] = {0};
    for(int i=0;i<ilimit;i++){
      for(int j=0;j<jlimit;j++){
        trbl[i][j] = 0;
      }
    }

    for(int i=0;i<n;i++) trbl[starti+i][startj] = matrix[i][0];
    for(int j=0;j<m;j++) trbl[starti+n-1][startj+j] = matrix[n-1][j];

    for(int i=starti+n-2;i>=0;i--){
      for(int j=startj;j<jlimit;j++){
        if(i-starti>=n|| i-starti<0 || j-startj>=m || j-startj<0) asd = 0;
        else asd=matrix[i-starti][j-starti];
        trbl[i][j] = asd+trbl[i+1][j-1];
      }
    }

//FOR DEBUGGING
/*
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        printf("%c ",matrix[i][j]+'0');
      }
      putchar('\n');
    }
    putchar('\n');
    putchar('\n');

    for(int i=0;i<ilimit;i++){
      for(int j=0;j<jlimit;j++){
        printf("%d ",(int)tlbr[i][j]);
      }
      putchar('\n');
    }
    putchar('\n');

    for(int i=0;i<ilimit;i++){
      for(int j=0;j<jlimit;j++){
        printf("%d ",(int)trbl[i][j]);
      }
      putchar('\n');
    }
    putchar('\n');
*/
//ENDFORDEBUGGING


    int ansarr[n+m-2] = {0};
//FOR DEBUGGING
/*
    for(int i=0;i<n+m-2;i++){
      printf("%d ",ansarr[i]);
    }
*/
//ENDFORDEBUGGING
//    putchar('\n');
    int newi,newj,thesum;
 
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(matrix[i][j]==1){
//          putchar('\n');
          for(int d=1;d<=n+m-2;d++){
            newi = i+starti;
            newj = j+startj; 
            thesum = (trbl[newi-d][newj] - trbl[newi+1][newj-d-1])+
                          (trbl[newi][newj+d] - trbl[newi+d+1][newj-1])+
                          (tlbr[newi-1][newj+d-1] - tlbr[newi-d][newj])+
                          (tlbr[newi+d-1][newj-1] - tlbr[newi][newj-d]);
//            cout<<"i:"<<i<<"\nj:"<<j<<"\nd:"<<d<<"\nthesum:"<<thesum<<endl;
            ansarr[d-1]+=thesum;
          }
//value of the four diagonals;
//finish this bit tomorrow
        }
      }
    }
    
    for(int i=0;i<n+m-2;i++){
      printf("%d ",ansarr[i]/2);
    }
    putchar('\n');

  }
}
//This is a nice program, thought of the idea myself, formulated the code, and it all went surprisingly smooth
