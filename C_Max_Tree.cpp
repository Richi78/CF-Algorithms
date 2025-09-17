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
    vector<array<int,4>> a;
    for(int i=0 ; i<n-1 ; i++){
        int u,v,x,y; cin >> u >> v >> x >> y;
        a.push_back({u,v,x,y});
    }    

    sort(all(a), [&](array<int,4> x, array<int,4> y){
        return (x[2]+x[3]) > (y[2]+y[3]);
    });

    // for(auto x : a){
        // vdebug(x)
    // }

    vector<int> adj[n+1];
    vector<int> indegree(n+1);
    for(auto x : a){
        if(x[3] >= x[2]){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }else{
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
    }

    queue<int> q;
    vector<int> ans(n+1);
    int tmp=n;
    for(int i=1 ; i<=n ; i++){
        if(indegree[i] == 0){
            q.push(i);
            ans[i]=tmp;
            tmp--;
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto adjN : adj[node]){
            indegree[adjN]--;
            if(indegree[adjN] == 0){
                q.push(adjN);
                ans[adjN]=tmp;
                tmp--;
            }
        }
    }

    for(int i=1 ; i<=n ; i++){
        cout<< ans[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}