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

void solve(){
    int n; cin >> n;
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];
    
    int A=0 , B=0;
    for(int i=0 ; i<n ; i++){
        if(a[i] && b[i]){
            A++; B++;
        }
    }
    for(int i=0 ; i<n ;i++){
        int x=a[i] , y=b[i];
        if(x == y) continue;
        if(i&1){ // B
            if(B%2 == 0) B++;
            else A++;
        }else{ // A
            if(A%2 == 0) A++;
            else B++;
        }
    }
    A&=1; B&=1;
    if(A == B) cout<<"Tie\n";
    else if(A>B) cout<<"Ajisai\n";
    else cout<<"Mai\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}