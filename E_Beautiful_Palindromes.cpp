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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    vector<int> freq(n+1);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        freq[a[i]]++;
    }    
    vector<int> b;
    for(int i=1 ; i<=n ; i++){
        if(freq[i] == 0) b.push_back(i);
    }

    // upsolve

    if(b.empty()){ 
        int i=0;
        while(k){
            cout << a[i] <<" ";
            i=(i+1)%3;
            k--;
        }
    }else{
        vector<int> tmp={b[0],0,a.back()};
        for(int i=1 ; i<=n ; i++){
            if(i!=tmp[0] && i!=tmp[2]){
                tmp[1]=i; break;
            }
        }
        int i=0;
        while(k){
            cout<< tmp[i] <<" ";
            i=(i+1)%3;
            k--;
        }
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}