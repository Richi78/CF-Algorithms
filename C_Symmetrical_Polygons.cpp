#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n; cin >> n;
    map<int,int> mp;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        mp[x]++;
    }    
    int sides=0 , cnt_sides=0;
    auto it=mp.begin();
    while(it!=mp.end()){
        sides+= it->first * (it->second -(it->second & 1));
        cnt_sides+= it->second - (it->second & 1);
        if(it->second % 2 == 0) it=mp.erase(it);
        else it->second=1 , it++;
    }
    int ans=sides;
    for(auto [x,y] : mp){
        if(sides > x) ans=max(ans, sides+x);
    }
    for(auto it=mp.begin() ; it!=mp.end()&&next(it)!=mp.end() ; it++){
        int x=it->first , y=next(it)->first;
        if(sides > y-x) ans=max(ans,sides+x+y);
    }
    if(ans > sides || cnt_sides > 2) cout<< ans <<"\n";
    else cout<<"0\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}