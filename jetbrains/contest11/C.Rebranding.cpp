#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,m; cin >> n >> m;
    string s; cin >> s;
    map<char,vector<int>> mp;
    for(int i=0 ; i<n ; i++){
        mp[s[i]].push_back(i);
    }
    for(int rep=0 ; rep<m ; rep++){
        char a,b; cin >> a >> b;
        if(a == b) continue;
        auto it1=mp.find(a) , it2=mp.find(b);
        if(it1!=mp.end() && it2!=mp.end()){
            vector<int> tmp1=move(it1->second) , tmp2=move(it2->second);
            it1->second=move(tmp2); it2->second=move(tmp1);
        }else if(it1!=mp.end()){
            vector<int> tmp1=move(it1->second);
            mp[b]=move(tmp1);
            mp.erase(it1);
        }else if(it2!=mp.end()){
            vector<int> tmp2=move(it2->second);
            mp[a]=move(tmp2);
            mp.erase(it2);
        }
    }
    string ans(n,' ');
    for(auto [c,v] : mp){
        for(auto idx : v) ans[idx]=c;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}