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

bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return x>=2;
}

void solve(){
    int x,k;cin>>x>>k;
    if(k==1){
        if(isPrime(x))yes;
        else no;
    }else{
        if(x==1 && k==2)yes;
        else no;
    } 
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}