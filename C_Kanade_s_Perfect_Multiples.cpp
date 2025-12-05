#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

vector<int> p;

void solve(){
    int n,k; cin >> n >> k;
    map<int,int> freq;
    set<int> st;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        freq[x]++;
        st.insert(x);
    }
    
    vector<int> ans;
    while(!st.empty()){
        int node=*st.begin();
        st.erase(st.begin());
        ans.push_back(node);
        int tmp=2;
        while(tmp*node<=k){
            if(freq[tmp*node] == 0){
                cout<< -1 <<"\n"; return;
            }
            st.erase(tmp*node);
            tmp++;
        }
    }
    cout<< ans.size() <<"\n";
    for(auto x : ans) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}