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
    string s; cin >> s;
    int ans=0;
    int i=0;
    for(int j=0 ; j<n ; j++){
        if(s[j] == '1'){
            i=j;
            break;
        } 
    }
    int idx=i;
    i=(i+1)%n;
    while(i!=idx){
        if(i == idx) break;
        if(s[i] == '0'){
            int tmp=1;
            while(i!=idx && s[(i+1)%n]=='0'){
                i=(i+1)%n,
                tmp++;
            }
            ans=max(ans,tmp);
        }
        i=(i+1)%n;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}