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
    for(int i=0 ; i<n ; i++) cin >> a[i];
    string s; cin >> s;

    vector<array<int,3>> need;
    int cnt=0;
    for(int i=0 ; i<n ; i++){
        if(s[i] == '1'){
            need.push_back({i,a[i],0});
            cnt++;
        }
    }


    vector<pair<int,int>> ans;
    int l=-1 , r=-1;
    for(auto arr : need){
        if(arr[2] == 1) continue;
        int idx=arr[0] , x=arr[1];
        for(int i=0 ; i<=idx ; i++){
            if(a[i] <= x){
                l=i; break;
            }
        }
        for(int i=n-1 ; i>=idx ; i--){
            if(a[i] >= x){
                r=i; break;
            }
        }
        int mn=min(a[l],a[r]) , mx=max(a[l],a[r]);
        bool ok=false;
        for(auto &tmp : need){
            if(tmp[2] == 1) continue;
            if(mn < tmp[1] && tmp[1] < mx){
                tmp[2]=1;
                ok=true;
                cnt--;
            }
        }
        if(ok){
            ans.emplace_back(l+1,r+1);
        }
        debug1(ans.size())
        if(ans.size() > 5){
            cout<< "-1\n"; return;
        }
    }
    
    for(auto x : need){
        debug2(x[1],x[2]);
    }
    if(cnt > 0){
        cout<< "-1\n"; return;
    }

    cout<< ans.size() <<"\n";
    for(auto [x,y] : ans){
        cout<< x <<" "<< y <<"\n";
    }

}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}