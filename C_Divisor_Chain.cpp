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
#define ilz(x) 64-__builtin_clzll(x)   //usar -1 para shifts, solo index quitar -1

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n;cin>>n;
    vi a;
    int idx= ilz(n);
    stack<int> s;
    s.push(n);
    forn(i,idx)a.pb(1<<i);
    int len=a.size(),tmp=a.back();a.pop_back();
    for(int i=len-1;i>=0;i--){
        if(n==tmp)break;
        if(n%a[i]==0){
            n-=a[i];
            s.push(n);
            i=len;
        }
    }
    while(!s.empty()){a.pb(s.top());s.pop();}
    cout<<a.size()<<endl;
    for(int i=a.size()-1;i>=0;i--)cout<<a[i]<<" ";
    cout<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}