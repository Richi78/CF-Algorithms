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
    int n,k;cin>>n>>k;
    vector<int> a(k+1);
    for(int i=1;i<=k;i++){cin>>a[i];}
    sort(a.begin(),a.end());
    int mise=k;
    int cat=0;
    int l=0 , r=a.back(), acc=0, accGato=0;
    while(1){
        int tmp=a.back();
        int x=n-tmp; // x es la distancia hacia el hueco
        acc++;
        a.pop_back();
        cat+=x;
        if(cat>=tmp || a.back()<=cat)break;
        // auto lb = lower_bound(all(a),cat);
        // int y;
        // // if(*lb>cat){
        // //     y=(--lb-a.begin());
        // // }
        // // else {
        // //     y=lb-a.begin();
        // // }
        // cout<<"x: "<<x<<endl;
        // cout<<"acc: "<<acc<<endl;
        // cout<<"cat: "<<cat<<endl;
        // cout<<"Y: "<<y<<endl;
        // if(acc+y>=k)break;
    }
    
    cout<<acc<<endl;
}
 
signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}