#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
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

void solve(){
    int k;cin>>k;
    vi a(k);
    forn(i,k)cin>>a[i];
    sort(all(a));
    int l=0,r=k-1;
    while(l<r){
        int tmp=a[l]*a[r];
        if(tmp==k-2){
            cout<<a[l]<<" "<<a[r]<<endl;
            return;
        }
        if(tmp>k-2)r--;
        if(tmp<k-2)l++;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}