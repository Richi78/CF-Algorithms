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
    int n; cin >> n;
    map<int,int> mp;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        mp[x]++;
    }
    for(auto [x,y] : mp){
        if((y & 1) && y > 1){
            mp[x+1]++;
            mp[x]--;    
        }
        int k=mp[x]-2 , tmp=1;
        while(k>0){
            mp[x+tmp]+=2;
            k-=2; tmp++;
            mp[x]-=2;
        } 
    }
    for(auto [x,y] : mp){
        if(y & 1){
            cout<<"NO"<<endl; return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}