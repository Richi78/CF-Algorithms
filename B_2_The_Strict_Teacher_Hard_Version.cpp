#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m,q; cin >> n >> m >> q;
    vector<int> b(m+1);
    for(int i=1 ; i<=m ; i++){
        cin >> b[i];
    }

    sort(all(b));
    
    for(int i=0 ; i<q ; i++){
        int x; cin >> x;
        auto it=lower_bound(all(b),x);
        if(it == b.end()){
            cout<<n - *(--b.end())<<endl;
        }else if(*prev(it) == 0){
            cout<<*it-1<<endl;
        }else{
            cout<<(*it - *prev(it))/2<<endl;
        }
    }

}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

