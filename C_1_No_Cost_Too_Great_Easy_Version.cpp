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

const int N=2e5+5;
vector<int> PF[N];

void solve(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];    
    
    int ans=2;
    map<int,int> mp;
    for(int i=0 ; i<n ; i++){
        for(auto x : PF[a[i]]){
            if(mp[x] > 0) ans=0;
            mp[x]++;
        }
    }

    for(int i=0 ; i<n ; i++){
        for(auto x : PF[a[i]]){
            mp[x]--;
        }
        for(auto x : PF[a[i]+1]){
            if(mp[x] > 0){
                ans=min(ans,1LL);
            }
        }
        for(auto x : PF[a[i]]){
            mp[x]++;
        }
    }

    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    
    vector<bool> crib(N,true);
    crib[0]=crib[1]=false;
    for(int i=2 ; i<N ; i++){
        if(crib[i]){
            for(int j=i ; j<N ; j+=i){
                PF[j].push_back(i);
                crib[j]=false;
            }
        }
    }


    int tc;cin>>tc;
    while(tc--)solve();
}