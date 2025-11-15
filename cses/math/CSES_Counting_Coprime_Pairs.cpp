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

const int N=1e6+5;

void solve(){
    int n; cin >> n;
    vector<int> freq(N);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        freq[x]++;
    }
    for(int i=1 ; i<N ; i++){
        for(int j=2*i ; j<N ; j+=i){
            freq[i]+=freq[j];
        }
    }
    for(int i=1 ; i<N ; i++){
        freq[i]=(freq[i]-1)*freq[i]/2;
    }
    for(int i=N-1 ; i>=1 ; i--){
        for(int j=2*i ; j<N ; j+=i){
            freq[i]-=freq[j];
        }
    }
    cout<< freq[1] <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}