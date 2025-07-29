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

bool bfs(int src, vector<int> adj[], vector<int> &vis){
	queue<int> q;
	q.push(src);
	vis[src]=0;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto adjN : adj[node]){
			if(vis[adjN] == -1){
				vis[adjN]=!vis[node];
				q.push(adjN);
			}
			if(vis[adjN] != -1 && vis[adjN]==vis[node]){
				return false;
			}
		}
	}
	return true;
}

void solve(){
    int n; cin >> n;
    vector<vector<bool>> edges(n,vector<bool>(n));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            int x; cin >> x;
            edges[i][j]=1==x;
        }
    }

	vector<int> adj[n];
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			if(edges[i][j]){
				adj[i].push_back(j);
			}
		}
	}

	bool ok=true;
	vector<int> vis(n,-1);
	for(int i=0 ; i<n && ok ; i++){
		if(vis[i] == -1){
			ok&=bfs(i,adj,vis);
		}
	}

    cout<< ok <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}