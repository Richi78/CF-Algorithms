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
    int ini;
    int fin;
    int id;
    bool operator <(const Event &b) const {
        return make_pair(ini,fin) < make_pair(b.ini,b.fin);
    }
};

void solve(){
    int n; cin >> n;
    vector<Event> a;
    for(int i=0 ; i<n ; i++){
        int u,v; cin >> u >> v;
        a.push_back(Event{u,v,i});
    }
    sort(all(a), [&](Event x, Event y){
        if(x.ini == y.ini){
            return x.fin > y.fin;
        }
        return x.ini < y.ini;
    });
 
    vector<bool> contain(n);
    vector<bool> isContained(n);
    
    int mx=a[0].fin;
    for(int i=1 ; i<n ; i++){
        if(a[i].fin <= mx){
            isContained[a[i].id]=true;
        }
        mx=max(mx,a[i].fin);
    }

    int mn=a[n-1].fin;
    for(int i=n-2 ; i>=0 ; i--){
        if(a[i].fin >= mn){
            contain[a[i].id]=true;
        }
        mn=min(mn,a[i].fin);
    }

    for(auto x : contain) cout<< x <<" ";
    cout<<"\n";
    for(auto x : isContained) cout << x <<" ";
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