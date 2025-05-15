#include <bits/stdc++.h>

using namespace std;

#define int long long int 
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define sz(a) (a).size()
#define input(x) cin >> x
#define printv(v) for(int i=0;i<sz(v);i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define F first 
#define S second
#define pii pair<int,int>
#define SIZE 100000

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
        sort(all(a[i]));
    }
    map<int,int> order;
    for(int i=1;i<=n;i++){
        order[a[i-1][0]]=i;
    }
    sort(all(a),[](vi &a, vi &b){return a[0]<b[0];});
    int pile=-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[j][i]>pile){
                pile=a[j][i];
            } else{
                cout<<"-1"<<endl;
                return;
            }
        }
    }
    
    for(auto x:order){
        cout<<x.S<<" ";
    }
    cout<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}