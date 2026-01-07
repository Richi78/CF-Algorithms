#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,q; cin >> n >> q;
    string s; cin >> s;
    set<int> st;
    map<int,int> mp;
    for(int i=0 ; i<q ; i++){
        int x; cin >> x; st.insert(x);
        mp[x]++;
    }    
    int pos=1;
    for(auto c : s){
        if(c == 'A'){
            pos++;
            st.insert(pos);
            mp[pos]++;
        }else{ // B
            while(mp[pos+1] == 1) pos++;
            st.insert(pos+1);
            mp[pos+1]++;
            pos++;
            while(mp[pos] == 1) pos++;
        }
    }
    cout<< st.size() <<"\n";
    for(auto x : st) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}