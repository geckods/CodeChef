#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif


	int t,n,m;
	cin>>t;
	for(int test=0;test<t;test++){
		cin>>n;
		cin>>m;

		if(n==1 && m == 1){
			cout<<1<<endl;
			cout<<1<<endl;
		}
		else if (n==1 && m==2){
			cout<<1<<endl;
			cout<<1<<" "<<1<<endl;
		}
		else if (n==2 && m==1){
			cout<<1<<endl;
			cout<<1<<endl<<1<<endl;
		}
		else if (n==1 || m==1){
			cout<<2<<endl;
			int count = 0;
			int curr = 1;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout<<curr<<" ";
					count++;
					if(count==2){
						count = 0;
						curr = 3-curr;
					}
				}
				cout<<endl;
			}
		}
		else if (n==2 && m==2) {
			cout<<2<<endl;
			cout<<"1 1\n2 2"<<endl;
		}
		else if (n==2 || m==2){
			cout<<3<<endl;
			if(n==2){
				int curr = 1;
				int count = 0;
				for(int j=0;j<m;j++){
					cout<<curr<<" ";
					count++;
					if(count==2){
						count = 0;
						curr = (curr%3)+1;
					}
				}
				cout<<endl;
				curr = 2;
				count = 1;
				for(int j=0;j<m;j++){
					cout<<curr<<" ";
					count++;
					if(count==2){
						count = 0;
						curr = (curr%3)+1;
					}
				}
				cout<<endl;
			}
			else if (m==2){
				int a,acount,b,bcount;
				a = 1;
				b = 2;
				acount = 0;
				bcount = 1;
				for(int i=0;i<n;i++){
					cout<<a<<" "<<b<<endl;
					acount++;
					bcount++;
					if(acount==2){
						acount=0;
						a=(a%3)+1;
					}
					if(bcount==2){
						bcount=0;
						b=(b%3)+1;
					}
				}
			}
		}
		else{
			cout<<4<<endl;
			/*
			aabbaabb
			cddccddc
			bbaabbaa
			dccddccd
			*/
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(i%2==0){//aabb line
						if(i%4==0)//starts at a
							if((j/2)%2==0){
								cout<<1<<" ";
							}
							else{
								cout<<2<<" ";
							}
						else{
							if((j/2)%2==0){
								cout<<2<<" ";
							}
							else{
								cout<<1<<" ";
							}
						}
					}
					else{//ccdd line
						if(i%4==1)//starts at c
							if(((j+1)/2)%2==0){
								cout<<3<<" ";
							}
							else{
								cout<<4<<" ";
							}
						else{
							if(((j+1)/2)%2==0){
								cout<<4<<" ";
							}
							else{
								cout<<3<<" ";
							}
						}
					}
				}
				cout<<endl;
			}
		}
	}
}