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

int n,k; 
map<tuple<char,int,int,int,int,int>, int> dp;

int f(char cur, int aa,int ab, int ba, int bb, int kk, char fi){
    if(kk == k) return (cur == fi ? 1 : 0);

    auto state = make_tuple(cur,aa,ab,ba,bb,kk);
    if(dp.count(state)) return dp[state];

    int ans=0;
    if(cur == 'A'){
        if(aa-1>=0){
            ans+=f('A', aa-1, ab, ba, bb, kk+1,fi);
        }
        if(ba-1>=0){
            ans+=f('B', aa, ab, ba-1, bb,kk+1,fi);
        }
    }else{
        if(ab-1>=0){
            ans+=f('A', aa, ab-1, ba, bb,kk+1,fi);
        }
        if(bb-1>=0){
            ans+=f('B', aa, ab, ba, bb-1,kk+1,fi);
        }
    }
    return dp[state]=ans;
}

void solve(){
    cin >> n >> k;
    string loc; cin >> loc;
    int aa=0 , ab=0 , ba=0 , bb=0;
    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        if(s=="AA") aa++;
        else if(s=="AB") ab++;
        else if(s=="BA") ba++;
        else bb++;
    }
    
    int ans=0;
    dp.clear();
    ans+=f(loc[0],aa,ab,ba,bb,0,loc[0]);
    // if(loc[0]!=loc[1]){
        dp.clear();
        ans+=f(loc[1],aa,ab,ba,bb,0,loc[1]);
    // }

    if(ans == 0){
        cout<<"NO\n";
    }else{
        cout<<"YES\n"<< ans <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}