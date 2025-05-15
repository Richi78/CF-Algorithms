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


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vi a(m),q(k);
    forn(i,m)cin>>a[i];
    forn(i,k)cin>>q[i];
    

    if(n-k>1){
        cout<<string(m,'0')<<endl;
        return;
    }else if(k>=n){
        cout<<string(m,'1')<<endl;
        return;
    }else{
        int x=n;
        forn(i,k){
            if(q[i]!=i+1){
                x=i+1;
                break;
            }
        }
        string ans(m,'0');
        forn(i,m){
            if(a[i]==x)ans[i]='1';
        }
        cout<<ans<<endl;
    }
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}


// solucion con time limit e
// string ans(m,'0');
//         forn(i,m){
//             auto it=q.begin();
//             int f=1;
//             for(int j=1;j<=n;j++){
//                 if(a[i]==j)continue;
//                 if(j==*it){
//                     it++;
//                 } else{
//                     f=0;
//                     break;
//                 }
//             }
//             if(f)ans[i]='1';
//         }
//         cout<<ans<<endl;