#include <stdio.h>
typedef long long int ll;

void printboard(char* board, int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%c",*(board+i*m+j));
		}
		putchar('\n');
	}
}


int main(){	

	unsigned char narr[1000000] = {0};
	unsigned char marr[1000000] = {0};
	char ch;

	ll t=0,n=0,m=0,q=0,j=0;
	unsigned char ans=0;
	
	scanf("%lld",&t);
	getchar();


	for(ll test=0;test<t;test++){
//	printf("%d\n",t);
		n = 0;
		m = 0;

		while ((ch=getchar())!='\n'){
			marr[m]=ch-'0';
			m++;
		}

		while ((ch=getchar())!='\n'){
			narr[n]=ch-'0';
			n++;
		}
		unsigned char board[n+1][m+1];

		// for(int i=0;i<m;i++){
		// 	printf("%d--",marr[i]);
		// }


		board[0][0]=0;

		for(ll i=1;i<=n;i++){
			board[i][0] = narr[i-1];
		}

		for(ll j=1;j<=m;j++){
			board[0][j] = marr[j-1];
		}

		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				board[i][j]=0;
			}
		}


		for(ll sum=2;sum<=(n+m);sum++){
			for(ll i=1;i<=sum;i++){
				j = sum-i;
				if ((i>n)||(j>m)) continue;
				board[i][j]=~(board[i-1][j]|board[i][j-1]);
				board[i][j]%=2;
			}
		}

		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				printf("%d",board[i][j]);
			}
			putchar('\n');
		}

		q=0;
		scanf("%lld",&q);

		unsigned char ansstr[q+1];

		ll a,b;
		for(ll i=0;i<q;i++){
			scanf("%lld",&a);
			getchar();
			scanf("%lld",&b);
			getchar();
			ans = (~board[a][b]);
			ans = ans%2;
			ansstr[i] = ans+'0';
		}
		ansstr[q] = '\0';
		printf("%s\n",ansstr);
//	printboard((char*)board, n, m);
	}
}