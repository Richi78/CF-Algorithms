#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){

}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}




//------------prime-------------------------
// bool isprime(int x){
//     for(int i=2;i*i<=x;i++){
//             if(x%i==0)return false;
//         }
//         return x>=2;
//     }
        
//---------gcd----------------------------

// int gcd(int a, int b){
//     if(b==0)return a;
//     return gcd(b,a%b);
// }

//---------lcm----------------------------
// int lcm (int a, int b) {
//     return a / gcd(a, b) * b;
// }

//--------union-find------------------
// const int n = 1000;
// vector<int> par(n,-1),sz(n,1);
// vector <pair<int, pair<int, int>>> edges;

// int find(int a) { return par[a] == -1 ? a : par[a] = find(par[a]); }

// void unite(int a, int b) {
//   if ((a = find(a)) == (b = find(b))) return;
//   if (sz[a] < sz[b]) swap(a, b);
//   par[b] = a; sz[a] += sz[b];
// }

// class disjointset{
//     vector<int> rank,parent,size;
// public:
//     disjointset(int n){
//         rank.resize(n+1, 0);
//         parent.resize(n+1);
//         size.resize(n+1);
//         for(int i=0 ; i<=n ; i++){
//             parent[i]=i;
//             size[i]=1;
//         }
//     }

//     int findupar(int node){
//         if(node == parent[node]) return node;
//         return parent[node] = findupar(parent[node]);
//     }

//     void unionbyrank(int u, int v){
//         int ulp_u = findupar(u);
//         int ulp_v = findupar(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u] < rank[ulp_v]){
//             parent[ulp_u] = ulp_v;
//         }
//         else if(rank[ulp_v] < rank[ulp_u]){
//             parent[ulp_v] = ulp_u;
//         }
//         else{
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++;
//         }
//     }

//     void unionbysize(int u, int v){
//         int ulp_u = findupar(u);
//         int ulp_v = findupar(v);
//         if(ulp_u == ulp_v) return;
//         if(size[ulp_u] < size[ulp_v]){
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }else{
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };

//------------kruskal---------------
// w,u,v
// sort(all(edges), [](auto &x, auto &y){return x[0] < y[0];});
// disjointset dsu(n);
// vector< vector<int> > mst;
// int mn=0;
// for(auto edge : edges){
    // int w=edge[0] , u=edge[1] , v=edge[2];
    // if(dsu.findupar(u) != dsu.findupar(v)){
        // dsu.unionbysize(u,v);
        // mn+=w;
        // mst.push_back(edge);
    // }
// }

//------------prims---------------
// int prims(int n, map<int, vector<pair<int,int>> > &adj){
//     vector< array<int,3> > mst;
//     int mn=0;
//     vector<int> vis(n+1);

//     priority_queue<
//         array<int,3>, 
//         vector< array<int,3> >,
//         greater< array<int,3> >
//     > pq; // {w,u,v}

//     pq.push({0, adj.begin()->f ,adj.begin()->f}); // el primer nodo no cuesta nada
//             //w,n,p
//     while( !pq.empty() ){
//         auto a=pq.top();
//         pq.pop();
//         int node=a[1] , parent=a[2] , w=a[0];

//         if(vis[node]) continue;
//         vis[node]=1;
//         mst.push_back(a);
//         mn+=w;
//         for(auto it : adj[node]){
//             int adjn=it.f , adjw=it.s;
//             if(!vis[adjn]) pq.push({adjw, adjn, node});
//         }
//     }
//     return mn;
// }

//------------sieve---------------
// vector<int> sieve(int x){
//     vector<int> ans(x+1,1);
//     // for(int i=2;i<=x;i++)ans[i]=1;
//     ans[0]=0;ans[1]=0;
//     for(int i=2;i*i<=x;i++)
//         if(ans[i])
//             for(int j=i*i;j<=x;j+=i)
//                 ans[j]=0;
//     return ans;
// }


//------------ordered set---------------
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>

// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //find_by_order, order_of_key ; greater<int>, less_equal<int>
// // insert -> logn | delete -> | find kth element -> logn | find # of elements smaller than x -> logn 
// // up and lb work opposite
// // to erase in a multiset s.erase(s.upperbound(x))


//------------binexp---------------
// int binexp(int a, int b){
//     int ans=1;
//     while(b){
//         if(b&1) ans*=a;
//         a = (a*a); //% mod; // si hay un mod
//         b >>= 1;
//     }
//     return ans;
// }


//------------multinv---------------
// int inv(int a, int m){ // m primo
//     int x=binexp(a, m-2);
//     return (x+m)%m;
// }


//------------lps---------------
// vector<int> create_lps(string &needle){
//     int n=(int)needle.size();
//     vector<int> lps(n);

//     int prevlps=0 , i=1;
//     while(i<n){
//         if(needle[i] == needle[prevlps]){
//             lps[i]=prevlps+1;
//             prevlps++; i++;
//         }else if(prevlps == 0){
//             lps[i]=0; i++;
//         }else{
//             prevlps=lps[prevlps-1];
//         }
//     }
//     return lps;
// }