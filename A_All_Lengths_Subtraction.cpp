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
    
    vector<bool> vis(n);
    int idx=max_element(all(a)) - a.begin();
    vis[idx]=true;

    vector<int> moves={1,-1};
    queue<int> q;
    q.push(idx);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int x=-1 ; x<=1 ; x+=2){
            int nxt=node+x;
            if(x==-1) while(vis[nxt])nxt--;
            else if(x==1) while(vis[nxt])nxt++;
            if(nxt>=0 && nxt<n){
                if( abs(a[node]-a[nxt]) == 1){
                    vis[nxt]=true;
                    q.push(nxt);
                }
            }
        }
    }
    
    bool ok=true;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            ok=false; break;
        }
    }
    cout<< (ok?"YES\n":"NO\n");
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}