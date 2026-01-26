#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    vector<pair<int,int>> LR;
    for(int i=0 ; i<n ; i++){
        int l,r; cin >> l >> r;
        LR.emplace_back(l,r);
    }
    int h=0;
    set<int> st;
    for(int i=0 ; i<n ; i++){
        if(a[i] == -1) st.insert(i);
        else h+=a[i];
        if(h<LR[i].first){
            while(!st.empty() && h<LR[i].first){
                int idx=*st.rbegin();
                a[idx]=1; h++;
                st.erase(prev(st.end()));
            }
            if(h < LR[i].first){
                cout<<"-1\n"; return;
            }
        }
    }
    h=0;
    for(int i=0 ; i<n; i ++){
        h+=max(0,a[i]);
        if(LR[i].first<=h && h<=LR[i].second) continue;
        else{
            cout<<"-1\n"; return;
        }
    }
    for(auto x : a) cout<< max(0,x) <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}