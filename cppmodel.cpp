#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){

}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}




//------------PRIME-------------------------
// bool isPrime(int x){
//     for(int i=2;i*i<=x;i++){
//             if(x%i==0)return false;
//         }
//         return x>=2;
//     }
        
//---------GCD----------------------------

// int gcd(int a, int b){
//     if(b==0)return a;
//     return gcd(b,a%b);
// }

//---------LCM----------------------------
// int lcm (int a, int b) {
//     return a / gcd(a, b) * b;
// }

//--------UNION-FIND------------------
// const int N = 1000;
// vector<int> par(N,-1),sz(N,1);
// vector <pair<int, pair<int, int>>> edges;

// int find(int a) { return par[a] == -1 ? a : par[a] = find(par[a]); }

// void unite(int a, int b) {
//   if ((a = find(a)) == (b = find(b))) return;
//   if (sz[a] < sz[b]) swap(a, b);
//   par[b] = a; sz[a] += sz[b];
// }

//------------SIEVE---------------
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


//------------ORDERED SET---------------
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>

// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //find_by_order, order_of_key ; greater<int>, less_equal<int>
// // insert -> logn | delete -> | find kth element -> logn | find # of elements smaller than x -> logn 


