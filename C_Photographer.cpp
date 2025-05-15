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

signed main(){
    FIO;
    int n,d;cin>>n>>d;
    int a,b;cin>>a>>b; 

    multimap<int,int> mp2;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        mp2.insert({x*a+y*b,i+1});
    }
    vi ans_pos;
    for(auto [mb, pos]:mp2){
        if(d-mb>=0){
            ans_pos.pb(pos);
            d-=mb;
        } else break;
    }
    cout<<ans_pos.size()<<endl;
    for(int i=0;i<ans_pos.size();i++){
        cout<<ans_pos[i]<<" ";
    }
    cout<<endl;
}
