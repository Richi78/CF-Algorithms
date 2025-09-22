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

int fliped(int n){
    if(n == 0) return 1;
    int mx=0 , tmp=n;
    while(tmp) mx++,tmp>>=1;
    return (~n)&((1LL<<mx)-1);
}

void solve(){
    int l,r; cin >> l >> r;
    if(r == 0){
        cout<<"0\n0\n"; return;
    }
    vector<int> ans(r+1,-1);
    queue<int> q;
    q.push(r);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        int tmp=fliped(x);
        if(tmp-1 > 0){
            q.push(tmp-1);
        }
        ans[x]=tmp;
        ans[tmp]=x;
    }
    int cur=-1;
    int sum=0;
    int x=0;
    int from=0;
    if(r%2 == 0){
        ans[0]=0;
        x=1LL;
        from=1;
    }
    for(int i=from ; i<=r ; i++){
        if(ans[i] != -1){
            cur=ans[i];
        }else if(ans[i] == -1){
            ans[i]=cur;
        }
        sum+=(x|ans[i]);
        x++;
        cur--;
    }
    cout<< sum <<"\n";
    for(auto y : ans) cout << y <<" ";
    cout<<"\n";
    // x=fliped(4);
    // debug1(x)
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}