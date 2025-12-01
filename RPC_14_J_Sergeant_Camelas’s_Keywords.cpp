#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int MOD1=998244353;
const int MOD2=1e9+7;
const int A=31;

pair<int,int> getHash(vector<pair<int,int>> &h, vector<pair<int,int>> &p,int l, int r){
    pair<int,int> ans;
    ans.first=(h[r].first-(h[l-1].first*p[r-l+1].first)%MOD1)%MOD1;
    ans.second=(h[r].second-(h[l-1].second*p[r-l+1].second)%MOD2)%MOD2;
    ans.first=(ans.first+MOD1)%MOD1;
    ans.second=(ans.second+MOD2)%MOD2;
    return ans;
}

void solve(){
    string s; cin >> s;
    vector<string> a(5);
    for(int i=0 ; i<5 ; i++) cin >> a[i];
    sort(all(a));
    vector<pair<int,int>> val;
    int sz_pattern;
    do{
        string tmp="";
        for(auto x : a){
            tmp+=x;
        }
        sz_pattern=tmp.size();
        int hsh1=0 , hsh2=0;
        int p=1;
        for(auto c : tmp){
            hsh1 = ((hsh1*A)%MOD1 + c)%MOD1;
            hsh2 = ((hsh2*A)%MOD2 + c)%MOD2;
        }
        val.emplace_back(hsh1,hsh2);
    }while( next_permutation(all(a)) );

    vector<pair<int,int>> h(s.size()+1);
    vector<pair<int,int>> p(s.size()+1,{1,1});
    for(int i=1 ; i<=s.size() ; i++){
        h[i].first=((h[i-1].first*A)%MOD1 + s[i-1])%MOD1;
        h[i].second=((h[i-1].second*A)%MOD2 + s[i-1])%MOD2;
        p[i].first=(p[i-1].first*A)%MOD1;
        p[i].second=(p[i-1].second*A)%MOD2;
    }
    const string poli="Nooo, la polizzia";
    const string fino="Sargento Camelas, Gracias!";
    for(int i=sz_pattern ; i<=s.size() ; i++){
        pair<int,int> cur=getHash(h,p,i-sz_pattern+1,i);
        for(auto x : val){
            if(cur == x){
                cout<< poli <<"\n"; return;
            }
        }
    }
    cout<< fino <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}