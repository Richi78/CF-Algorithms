#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

struct Event{
    int x;
    bool isEnd;
    int id;
    bool operator<(const Event &b) const {
        return make_pair(x,isEnd) < make_pair(b.x,b.isEnd);
    }
};

void solve(){
    int n; cin >> n;
    vector<Event> a;
    for(int i=0 ; i<n ; i++){
        int u,v; cin >> u >> v;
        a.push_back(Event{u,false,i});
        a.push_back(Event{v,true,i});
    }
    sort(all(a));

    int ans=0;
    int active=0;
    vector<int> roomUsed(n);
    vector<int> available;
    for(int i=0 ; i<2*n ; i++){
        if(a[i].isEnd){
            active--;
            available.push_back(roomUsed[a[i].id]);
        }else{
            active++;
            ans=max(ans,active);
            if(available.empty()){
                available.push_back(ans);
            }
            roomUsed[a[i].id]=available.back();
            available.pop_back();
        }
    }
    cout<< ans <<"\n";
    for(auto x : roomUsed) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}