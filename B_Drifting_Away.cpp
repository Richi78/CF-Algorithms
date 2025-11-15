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
    string s; cin >> s;
    int n=s.size();
    if(n == 1){
        cout<<"1\n"; return;
    }
    for(int i=0 ; i<n ; i++){
        if(i+1<n && s[i]=='>' && s[i+1]=='<'){
            cout<<"-1\n"; return;
        }
        if(i+1<n && s[i]=='>' && s[i+1]=='*'){
            cout<<"-1\n"; return;
        }
        if(i+1<n && s[i]=='*' && s[i+1]=='<'){
            cout<<"-1\n"; return;
        }
        if(i+1<n && s[i]=='*' && s[i+1]=='*'){
            cout<<"-1\n"; return;
        }
    }

    int ans=0;
    {
        int cnt=0;
        for(int i=0 ; i<n ; i++){
            if(s[i] == '<' || s[i] == '*'){
                cnt++;
            }else break;
        }
        ans=max(ans,cnt);
    }
    {
        int cnt=0;
        for(int i=n-1 ; i>=0 ; i--){
            if(s[i] == '>' || s[i] == '*'){
                cnt++;
            }else break;
        }
        ans=max(ans,cnt);
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