#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void solve(){
    int n; cin >> n; 
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    if(n == 1 && a[0] == 1){
        cout<<"*\n"; return;
    }

    sort(all(a));
    int l=a[0];
    for(int i=1 ; i<n ; i++){
        int g=gcd(l,a[i]);
        l=(l/g)*a[i];
    }

    for(int i=0 ; i<n ; i++){
        if(mp[l/a[i]] == 0){
            cout<< l <<" "<< l/a[i] <<"\n"; return;
        }
    }
    
    // debug1(l)
    
    int tmp=sqrtl(l);
    if(tmp*tmp==l && mp[tmp] == 0){
        cout<< l <<" "<< tmp <<"\n";
    }else{
        int x=l*a[1];
        cout<< x <<" "<< x <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}