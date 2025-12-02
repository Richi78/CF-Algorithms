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
    int n; cin >> n;
    vector<int> d(n) , e(n);
    for(int i=0 ; i<n ; i++) cin >> d[i];
    for(int i=0 ; i<n ; i++) cin >> e[i];

    stack<pair<int,int>> st;
    vector<int> ans;
    for(int i=n-1 ; i>=0 ; i--){
        auto u=make_pair(d[i],e[i]);
        while(!st.empty() && st.top().first>=d[i]) st.pop();
        if(st.empty()){
            ans.push_back(i);
        }else if(st.top().second < e[i]){
            ans.push_back(i); 
        }
        st.push(u);
    }
    reverse(all(ans));
    cout<< ans.size() <<"\n";
    
    for(int i=0 ; i<ans.size() ; i++) cout<< ans[i]+1 << ((i+1)==ans.size()?"":" ");
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