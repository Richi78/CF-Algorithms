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
    vector<int> prv(n+2) , nxt(n+2) , mx(n+1); 
    for(int i=1 ; i<=n ; i++){
        int x; cin >> x;
        mx[x]=i;
        prv[i]=i-1;
        nxt[i]=i+1;
    }

    vector<int> vis(n+1);
    bool t=true; 
    while(true){
        int turn= t==true?1:2;
        int idx=-1;
        while(mx.size() != 1){
            if(vis[mx.back()] == 0){
                idx=mx.back();
                mx.pop_back();
                break;
            }else{
                mx.pop_back();
            }
        }
        if(idx == -1) break;

        vis[idx]=turn;
        int tmp_nxt=nxt[idx];
        int tmp_prv=prv[idx];
        nxt[prv[idx]]=nxt[idx];
        prv[nxt[idx]]=prv[idx];
        for(int i=0 ; i<k ; i++){
            if(tmp_nxt == n+1) break;
            vis[tmp_nxt]=turn;
            nxt[prv[tmp_nxt]]=nxt[tmp_nxt];
            prv[nxt[tmp_nxt]]=prv[tmp_nxt];
            tmp_nxt= nxt[tmp_nxt];
        }
        for(int i=0 ; i<k ; i++){
            if(tmp_prv == 0) break;
            vis[tmp_prv]=turn;
            nxt[prv[tmp_prv]]=nxt[tmp_prv];
            prv[nxt[tmp_prv]]=prv[tmp_prv];
            tmp_prv=prv[tmp_prv];
        }
        t=!t;
    }
    for(int i=1 ; i<=n ; i++) cout<< vis[i];
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