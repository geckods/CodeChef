#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        ll q = a / m; 
        ll t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 

ll power(ll x, ll y){
    ll res = 1;      // Initialize result     

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x); 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x);   
    } 
    return res; 
}

ll power(ll x, ll y, ll p) { 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int lcm(int a, int b)  
{  
    return (a*b)/gcd(a, b);  
}  

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ll p,q,qinv;
    ll n,k,m;
    ll t;
    ll mainguesses;
    ll nraisedtok;
    ll newp,newq,thegcd,nnp,nnq;
    cin>>t;
    for(ll test=0;test<t;test++){
        cin>>n>>k>>m;
        if(m==1){
            p = 1;
            q = n;
            qinv = modInverse(q,MOD);
            cout<<(p*qinv)%MOD<<endl;
            continue;
        }


        if(n>k){
            m--;
            n%=k;
            if (n==0) n=k;
        }


        mainguesses = (m+1)/2;
        //compute mainguesses formula
        nraisedtok = power(n,mainguesses,MOD);
        p = nraisedtok-power(n-1,mainguesses,MOD);//n raised to k minus (n-1) raised to k
        q = nraisedtok;//n raised to k
//        cout<<p<<" "<<q<<endl;
        if(m%2==0){
            //there is an extra guess to be addded here
            newp = (q-p);
            newq = q*(n+k);

            nnq = lcm(q,newq);
            nnp = newp*(nnq/newq)+p*(nnq/q);
            thegcd = gcd(nnp,nnq);
            p = nnp/thegcd;
            q = nnq/thegcd;

//            cout<<p<<" "<<q<<endl;
        }
        else
        {
            thegcd = gcd(p,q);
            p = p/thegcd;
            q = q/thegcd;
        }


        p%=MOD;
        q%=MOD;
        
        qinv = modInverse(q,MOD);
//        cout<<p<<" "<<q<<endl;
        cout<<(p*qinv)%MOD<<endl; 
    }
}