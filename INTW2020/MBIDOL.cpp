#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    // =

    while(t--){
        ll n,m,c,k;
        cin>>n>>m>>c>>k;
        ll arr[n][m];
        ll rowpref[n][m];
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='#'){
                    arr[i][j]=1;
                }
                else{
                    arr[i][j]=0;
                }

                if(j==0)rowpref[i][j]=arr[i][j];
                else{
                    rowpref[i][j]=rowpref[i][j-1]+arr[i][j];
                }

            }
        }

        ll fullpref[n][m];
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(i==0){
                    fullpref[i][j]=rowpref[i][j];
                }
                else{
                    fullpref[i][j]=fullpref[i-1][j]+rowpref[i][j];
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cerr<<i<<" "<<j<<" "<<fullpref[i][j]<<" "<<rowpref[i][j]<<" "<<arr[i][j]<<endl;
        //     }
        // }


        ll ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll bmax=max(n,m)+2;
                // cerr<<bmax<<endl;
                ll bmin=1;
                while(bmin<bmax){
                    ll bmid=(bmin+bmax)/2;
                    ll x1,y1,x2,y2;
                    x1=max(0ll,i-bmid+1);
                    y1=max(0ll,j-bmid+1);
                    x2=min(n-1,i+bmid-1);
                    y2=min(m-1,j+bmid-1);
                    ll currval=fullpref[x2][y2];
                    if(x1>0)currval-=fullpref[x1-1][y2];
                    if(y1>0)currval-=fullpref[x2][y1-1];
                    if(x1>0&&y1>0)currval+=fullpref[x1-1][y1-1];

                    // cerr<<i<<" "<<j<<" "<<bmid<<" "<<currval<<endl;
                    if(currval>=k){
                        bmax=bmid;
                    }
                    else{
                        bmin=bmid+1;
                    }
                }

                // cerr<<i<<" "<<j<<" "<<bmin<<endl;

                if(bmin<max(n,m)+2){
                    ans=min(ans,bmin);
                }
            }
        }
        // cerr<<ans<<endl;

        if(ans==INT_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<ans*c<<endl;
        }

    }
}