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
    vector<int> a(n);
    vector<int> mp[n+1];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        mp[a[i]].push_back(i);
    }    
    // for(auto x : mp){
        // vdebug(x)
    // }

    int x=1;
    vector<int> ans(n);
    for(int i=1 ; i<=n ; i++){
        if(mp[i].size() == 0) continue;
        if(mp[i].size()%i != 0){
            cout<<"-1\n"; return;
        }else{
            int sz=mp[i].size();
            int cnt=0;
            for(int j=0 ; j<sz ; j++){
                ans[mp[i][j]]=x; 
                cnt++;
                if(cnt%i == 0) x++;
            }
        }
    }
    for(auto x : ans) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}

