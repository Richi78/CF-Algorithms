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
    int n; char c; cin >> n >> c;
    string s; cin >> s;

    if(c == 'g'){
        cout<< "0\n"; return;
    }

    vector<int> g;
    bool search=false;
    int ini=-1;
    int ans=0;
    for(int i=0 ; i<n ; i++){
        if(!search){
            if(s[i] == c){
                search=true;
                ini=i;
            }
        }else{
            if(s[i] =='g'){
                search=false;
                ans=max(ans,i-ini);
            }
        }
    }
    if(search){
        int tmp=n-ini;
        // debug1(tmp)
        for(int i=0 ; i<n ; i++){
            if(s[i] == 'g'){
                ans=max(ans,tmp+i);
                break;
            }
        }
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