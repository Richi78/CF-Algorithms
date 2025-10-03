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

int f(string &s, int pos, vector<int> adj[], bool flag){ //0->a 1->b
    int n=s.size();
    char c=flag?'b':'a';
    // debug2(c,pos)
    int ans=0;
    //check left
    int cur=pos;
    for(int i=pos-1 ; i>=0 ; i--){
        if(s[i]==c){
            ans+=cur-i-1;
            cur--;
        } 
    }
    //check right
    cur=pos;
    for(int i=pos+1 ; i<n ; i++){
        if(s[i]==c){
            ans+=i-cur-1;
            cur++;
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n; 
    string s; cin >> s;
    vector<int> adj[2];
    for(int i=0 ; i<n ; i++){
        if(s[i]=='a') adj[0].push_back(i);
        else adj[1].push_back(i);
    }
    if(adj[0].size() == 0 || adj[1].size() == 0){
        cout<<"0\n"; return;
    }
    int cnt_a=f(s,adj[0][adj[0].size()/2],adj,false);
    int cnt_b=f(s,adj[1][adj[1].size()/2],adj,true);
    cout<< min(cnt_a,cnt_b) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}