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

struct HopcroftKarp {
    int n, m; 
    vector<vector<int>> adj; 
    vector<int> dist, matchU, matchV;

    HopcroftKarp(int n, int m): n(n), m(m) {
        adj.assign(n + 1, {});
        matchU.assign(n + 1, 0);
        matchV.assign(m + 1, 0);
        dist.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (matchU[u] == 0) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = -1;
            }
        }
        bool found = false;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (matchV[v] != 0 && dist[matchV[v]] == -1) {
                    dist[matchV[v]] = dist[u] + 1;
                    q.push(matchV[v]);
                }
                if (matchV[v] == 0) {
                    found = true;
                }
            }
        }
        return found;
    }

    bool dfs(int u) {
        for (int v : adj[u]) {
            if (matchV[v] == 0 || (dist[matchV[v]] == dist[u] + 1 && dfs(matchV[v]))) {
                matchU[u] = v;
                matchV[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int maxMatching() {
        int matching = 0;
        while (bfs()) {
            for (int u = 1; u <= n; u++) {
                if (matchU[u] == 0 && dfs(u)) {
                    matching++;
                }
            }
        }
        return matching;
    }
};

int sqroot(int n){
    int l=0 , r=n;
    int ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(mid*mid <= n){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++) cin >> a[i];

    HopcroftKarp hk(n, n);

    // vector<vector<int>> roots(n);
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            int tmp=a[i]+j;
            int x=sqroot(tmp);
            if(x*x == tmp){
                hk.addEdge(i, j);
            }
        }
    }
    
    int maxMatch = hk.maxMatching();
    if (maxMatch == n) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

