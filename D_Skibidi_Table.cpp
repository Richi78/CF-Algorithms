#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define sz(a) (a).size()
#define input(x) cin >> x
#define printv(v) for(int i=0;i<sz(v);i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}


void solve(){
    int n,q; cin>>n>>q;
    for(int i=0;i<q;i++){
        string s; cin>>s;
        if(s == "->"){
            int x,y; cin>>x>>y;
            x--; y--;
            int ans=1;
            // we start i in 30 because the 31th bit is for the sign +/-
            for(int i=30;i>=0;i--){
                int a = x>>i & 1 , b= y>>i & 1;
                if(a&b) ans+= 1 * (1LL << 2*i);
                if(!a&b) ans+= 3 * (1LL << 2*i);
                if (a&!b) ans+= 2* (1LL << 2*i);
            }
            cout<<ans<<endl;
        }else{
            int x; cin>>x;
            x--;
            int a=0 , b=0 , shift=0;
            while(x){
                int k=x%4;
                x>>=2;
                if(k==1){a+= 1<<shift; b+= 1<<shift;}
                if(k==2){a+= 1<<shift;}
                if(k==3){b+= 1<<shift;}
                shift++;
            }
            cout<<++a<<" "<<++b<<endl;
        }
    }
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}