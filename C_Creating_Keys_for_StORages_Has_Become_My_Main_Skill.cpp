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
    int n,x; cin >> n >> x;
    if(n == 1){
        cout<<x<<endl;
    } else{
        vector<int> ans;
        int tmp=0;
        for(int i=0 ; i<n ; i++){
            if((x | i) == x && i <= x){
                ans.push_back(i);
                tmp |= i;
            }
            else ans.push_back(x);
        }
        if(tmp != x){
            ans[n-1]=x;
        }
        for(int i=0 ; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    } 
}
 
signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}