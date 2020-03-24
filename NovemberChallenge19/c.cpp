#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<pair<double,double>,double> distmet;

double euclidian(double a, double b, double c, double d){
	return sqrt(pow(a-c,2)+pow(b-d,2));
}

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
   		double x,y;
   		cin>>x>>y;

   		int n,m,k;
   		cin>>n>>m>>k;

   		vector<distmet> en;

   		distmet temp;
   		for(int i=0;i<n;i++){
   			cin>>temp.first.first>>temp.first.second;
   			temp.second=DBL_MAX;

   			en.push_back(temp);
   		}

   		vector<distmet> em;

   		for(int i=0;i<m;i++){
   			cin>>temp.first.first>>temp.first.second;
   			temp.second=DBL_MAX;

   			em.push_back(temp);
   		}

   		vector<distmet> ek;

   		for(int i=0;i<k;i++){
   			cin>>temp.first.first>>temp.first.second;
   			temp.second=DBL_MAX;

   			ek.push_back(temp);
   		}

   		for(int i=0;i<m;i++){
   			for(int j=0;j<k;j++){
   				em[i].second=min(em[i].second,euclidian(em[i].first.first,em[i].first.second,ek[j].first.first,ek[j].first.second));
   				// cout<<i<<" "<<j<<" "<<em[i].second<<endl;
   			}
   		}

   		for(int i=0;i<n;i++){
   			for(int j=0;j<k;j++){
   				en[i].second=min(en[i].second,euclidian(en[i].first.first,en[i].first.second,ek[j].first.first,ek[j].first.second));
   				// cout<<i<<" "<<j<<" "<<en[i].second<<endl;
   			}
   		}

   		vector<distmet> emc=em;
   		vector<distmet> enc=en;

   		for(int i=0;i<n;i++){
   			// cout<<en[i].first.first<<" "<<en[i].first.second<<" "<<en[i].second<<endl;
   			en[i].second=DBL_MAX;
   		}

   		for(int i=0;i<m;i++){
   			// cout<<em[i].first.first<<" "<<em[i].first.second<<" "<<em[i].second<<endl;
   			em[i].second=DBL_MAX;   			
   		}



   		for(int i=0;i<m;i++){
   			for(int j=0;j<n;j++){
   				em[i].second=min(em[i].second,euclidian(em[i].first.first,em[i].first.second,enc[j].first.first,enc[j].first.second)+enc[j].second);
   			}
   		}

   		for(int i=0;i<n;i++){
   			for(int j=0;j<m;j++){
   				en[i].second=min(en[i].second,euclidian(en[i].first.first,en[i].first.second,emc[j].first.first,emc[j].first.second)+emc[j].second);
   			}
   		}

   		// for(int i=0;i<n;i++){
   		// 	cout<<en[i].first.first<<" "<<en[i].first.second<<" "<<en[i].second<<endl;
   		// }

   		// for(int i=0;i<m;i++){
   		// 	cout<<em[i].first.first<<" "<<em[i].first.second<<" "<<em[i].second<<endl;
   		// }


   		double ans=DBL_MAX;

   		for(int i=0;i<n;i++){
   			ans=min(ans,euclidian(x,y,en[i].first.first,en[i].first.second)+en[i].second);
   		}

   		for(int i=0;i<m;i++){
   			ans=min(ans,euclidian(x,y,em[i].first.first,em[i].first.second)+em[i].second);
   		}


   		cout<<setprecision(12)<<ans<<endl;
   	}
}