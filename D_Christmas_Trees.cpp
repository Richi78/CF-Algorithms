#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> h;
    int cnt=0;
    map<int,int> mp;
    queue< pair<int,int> > q;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        q.push({0,x});
    }
    while(!q.empty()){
        auto [dist,pos]=q.front();
        q.pop();
        if(mp[pos]) continue;
        if(dist!=0) h.push_back(pos);
        mp[pos]=1;
        cnt+=dist;
        if(!mp[pos+1]){
            q.push({dist+1,pos+1});
        }
        if(!mp[pos-1]){
            q.push({dist+1,pos-1});
        }
        if(h.size() >= m) break;
    }
    cout<< cnt <<"\n";
    for(auto x : h){
        cout<< x <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}