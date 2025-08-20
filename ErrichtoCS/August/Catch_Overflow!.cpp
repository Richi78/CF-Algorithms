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

#define F first 
#define S second
const int N=1e5+10;
const int LIMIT=1LL<<32;

void solve(){
    int n; cin >> n;
    int cnt=-1 , ans=0;
    vector<pair<int,int>> f(N);

    queue<pair<string,int>> q;
    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        if(s[0] == 'a') q.push({"a",0});
        else if(s[0] == 'f'){
            int x; cin >> x;
            q.push({"f",x});
        }else{
            q.push({"e",0});
        }
    }

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(it.F[0] == 'a'){
            if(cnt != -1){
                f[cnt].S++;
            }else{
                ans++;
            }
        }else if(it.F[0] == 'f'){
            int a=it.S;
            cnt++;
            f[cnt].F=a;
        }else{ // end
            int tmp=f[cnt].S*f[cnt].F;
            f[cnt].F=f[cnt].S=0;
            cnt--;
            if(cnt == -1){
                ans+=tmp;
            }else{
                f[cnt].S+=tmp;
            }
        }
        if(ans>=LIMIT || (cnt!=-1 && f[cnt].S>=LIMIT)){
            cout<<"OVERFLOW!!!\n"; return;
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}