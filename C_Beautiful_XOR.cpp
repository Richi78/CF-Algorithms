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

void solve(){
    int a,b; cin >> a >> b;

    int tmp_a=a , tmp_b=b;
    string bin_a , bin_b;
    while(tmp_a){
        bin_a.push_back(tmp_a%2+'0'); tmp_a>>=1;
    }
    while(tmp_b){
        bin_b.push_back(tmp_b%2+'0'); tmp_b>>=1;
    }
    // reverse(all(bin_a)); reverse(all(bin_b));

    if(bin_b.size() > bin_a.size()){
        cout<< "-1\n"; return;
    }

    // debug2(bin_a, bin_b)

    vector<int> ans;
    int limit=min(bin_a.size() , bin_b.size());
    for(int i=0 ; i<limit ; i++){
        if(bin_b[i]=='1' && bin_a[i]=='0') ans.push_back(1LL<<i);
        else if(bin_b[i]=='0' && bin_a[i]=='1') ans.push_back(1LL<<i);
    }

    int limit2=max(bin_a.size() , bin_b.size());
    for(int i=limit ; i<limit2 ; i++){
        if(bin_a[i]=='1') ans.push_back(1LL<<i);
    }

    cout<< ans.size() <<"\n";
    if(ans.size() == 0) return;
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