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
    int n,k; cin >> n >> k;
    vector<string> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> adj[26] , indegree(26);
    for(int i=1 ; i<n ; i++){
        int l=a[i-1].size() , r=a[i].size();
        for(int j=0 ; j<min(l,r) ; j++){
            if(a[i-1][j] != a[i][j]){
                adj[a[i-1][j]-'a'].push_back(a[i][j]-'a');
                indegree[a[i][j]-'a']++;
                break;
            }
        }
    }

    queue<int> q;
    for(int i=0 ; i<k ; i++){
        if(indegree[i] == 0) q.push(i);
    }

    string ans="";
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node+'a');
        for(auto adjN : adj[node]){
            if(--indegree[adjN] == 0){
                q.push(adjN);
            }
        }
    }

    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}