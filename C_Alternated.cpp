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
    int n; cin >> n;
    string s; cin >> s;
    string orig_s=s;
    n*=2;
    int cnt=1e17;
     
    vector<int> p[2];
    for(int i=0 ; i<n ; i++){
        if(s[i] == 'B') p[1].push_back(i); 
        else p[0].push_back(i);  
    }
    bool turn=true; // true -> A    false -> B
    for(int rep=0 ; rep<2 ; rep++){
        s=orig_s;
        int ans=0;
        int i=0; //ptr B
        int j=0; //ptr A
        for(int idx=0 ; idx<n ; idx++){
            char cur=s[idx];
            if( (turn && cur=='A') || (!turn && cur=='B') ){
                turn=!turn; continue;
            }
            if(turn){ // s[idx] == 'B'
                while(idx>=p[0][j]) j++;
                swap(s[idx],s[p[0][j]]);
                ans+=p[0][j]-idx;
                j++;
            }else {
                while(idx>=p[1][i]) i++;
                swap(s[idx],s[p[1][i]]);
                ans+=p[1][i]-idx;
                i++;
            }
            turn=!turn;
        }
        cnt=min(cnt,ans);
        turn=false;
    }
    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}