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

struct H{
    vector<pair<int,int>> h,p;
    const int MOD1=998244353;
    const int MOD2=1e9+7;
    const int A=31;
    string s;
    H(string &a){
        s=a;
        int n=s.size();
        h.resize(n+1); p.resize(n+1,{1,1});
        for(int i=1 ; i<=n ; i++){
            h[i].F=((h[i-1].F*A)%MOD1 + s[i-1])%MOD1;
            h[i].S=((h[i-1].S*A)%MOD2 + s[i-1])%MOD2;
            p[i].F=(p[i-1].F*A)%MOD1;
            p[i].S=(p[i-1].S*A)%MOD2;
        }
    }
    int getHash(int l, int r){
        pair<int,int> ans;
        ans.F=(h[r].F-(h[l-1].F*p[r-l+1].F)%MOD1)%MOD1;
        ans.S=(h[r].S-(h[l-1].S*p[r-l+1].S)%MOD2)%MOD2;
        ans.F=(ans.F+MOD1)%MOD1;
        ans.S=(ans.S+MOD2)%MOD2;
        return (ans.F<<32)^ans.S;
    }
};

void solve(){
    string s,s2; cin >> s >> s2;
    int k; cin >> k;
    int n=s.size();
    vector<bool> bad(26);
    for(int i=0 ; i<26 ; i++){
        if(s2[i] == '0') bad[i]=true;
    } 

    H h(s);

    unordered_set<int> st;
    for(int i=0 ; i<n ; i++){
        int tmp=0;
        for(int j=i ; j<n ; j++){
            tmp+=bad[s[j]-'a'];
            if(tmp>k) break;
            st.insert(h.getHash(i+1,j+1));
        }
    }
    cout<< st.size() <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

