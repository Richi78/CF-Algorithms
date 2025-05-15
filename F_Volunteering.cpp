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

const int N=4e5;
int dp[N]={0};

signed main(){
    FIO;
    int n; cin>>n;
    int l,r; cin>>l>>r;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        cout<<x<<y<<endl;
        for(int i=x;i<=y;i++){
            dp[i]++;
        }
    }
    for(int i=0;i<21;i++){
        cout<<dp[i]<< " ";
    }
}