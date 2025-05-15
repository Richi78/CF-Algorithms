#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define input(x) cin >> x
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ilz(x) 64-__builtin__clzll(x)-1   //usar -1 para shifts, solo index quitar -1


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){

}
// const int N=1e5+5;
// vector<int> g[N];
// vector<int> visited(N);
// vector<int> cat(N);
void dfs(int source,vector<vi> &g,vi &visited,vi &cat,int concat,int maxCat,int &ans){
    // if(visited[source])return;
    visited[source]=1;
    if(cat[source]==0)concat=0;
    else{
        if(concat+cat[source]>maxCat)return;
        else concat+=cat[source];
    }
    if(g[source].size()==1 && source!=1){ans++;return;}
    for(auto e:g[source]){
        if(visited[e]==0){
            // int tmp=concat;
            dfs(e,g,visited,cat,concat,maxCat,ans);
            // concat=tmp;
        }
    }
}

signed main(){
    FIO;
    int n,m;cin>>n>>m;
    vi cat(n+1);
    forn(i,n)cin>>cat[i+1];
    vector<vector<int>> g(n+1);
    // vector<int> g[n+1];
    vi visited(n+1,0);
    forn(i,n-1){
        int s,d;cin>>s>>d;
        g[s].pb(d);
        g[d].pb(s);
    }
    int ans=0;
    int concat=0;
    dfs(1,g,visited,cat,concat,m,ans);
    cout<<ans<<endl;
}