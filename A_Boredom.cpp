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
const int N=1e5+7;
int dp[N], a[N] , cnt[N];

void solve(){
    int n;cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];cnt[a[i]]++;
    }
    dp[1]=cnt[1];
    for(int i=2;i<N;i++){
        dp[i]=max( dp[i-1] , (cnt[i] * i) + dp[i-2] );
    }
    cout<<dp[100000]<<endl;
}

signed main(){
    FIO;
    solve();
}
