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
    int n,m; cin>>n>>m;
    int sum10=0;
    for(int i=1; i<=10 ; i++){
        sum10+=((m*i)%10);
    }   
    int tmp=n/m;
    int k=tmp/10;
    int sum=k*sum10;
    n-=k*10*m;
    // cout<<"n: "<< n<<endl;
    for(int i=m;i<=n;i+=m){
        if(i%m==0){
            sum+=i%10;
        }
    }
    cout<<sum<<endl;
}
signed main(){
    FIO;
    int q; cin>>q;
    for(int i=0;i<q;i++){
        solve();
    }
}