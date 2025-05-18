#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    vector<int> b;
    if(n==2){
        int x=a[0]+a[1];
        if(x == 0 || x == 2) {
            cout<<"YES"<<endl;
            return;
        }
    }
    if(accumulate(all(a),0) == n){
        cout<<"YES"<<endl; return;
    }
    bool f=1;
    for(int i=0 ; i<n ; i++){
        int x=a[i];
        if(f){
            if(x==0){
                f=0;
            }
        }else{
            if(x != 1){
                cout<<"YES"<<endl; return;
            }else{
                f=1;
            }
        }
    }
    cout<<"NO"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}


