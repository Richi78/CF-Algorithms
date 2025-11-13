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

const int INF=1e18;

string to_str(__int128 x){
    string ans="";
    while(x){
        ans+= x%10+'0';
        x/=10;
    }
    reverse(all(ans));
    return ans;
}

__int128 getArea(int mnX, int mnY, int mxX, int mxY){
    __int128 l1=(__int128)(mxY-mnY+1);
    __int128 l2=(__int128)(mxX-mnX+1);
    __int128 ans=l1 * l2;
    if(ans<0) return -ans;
    return ans;
}

void solve(){
    int n,k; cin >> n >> k;
    int mnX=INF , mnY=INF , mxX=-INF , mxY=-INF;
    map<int, vector<pair<int,int>> > mp;
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        uax(mxX,x);
        uax(mxY,y);
        uin(mnX,x);
        uin(mnY,y);
        mp[x].emplace_back(x,y);
    }
    if(n == 1){
        cout<< "1\n"; return;
    }
    __int128 ans=getArea(mnX,mnY,mxX,mxY);
    __int128 ini=ans;
    for(auto [v,w] : mp){

        for(auto [x,y] : w){
            // UL
            // if(x == mnX || y == mnY)
            {
                int n_mnX=min(mnX,x-k);
                int n_mnY=min(mnY,y-k);
                __int128 tmp=getArea(n_mnX,n_mnY,mxX,mxY);
                ans=max(ans,tmp);
            }
            // UR
            // if(x == mnX || y == mxY)
            {
                int n_mnX=min(mnX,x-k);
                int n_mxY=max(mxY,y+k);
                __int128 tmp=getArea(n_mnX,mnY,mxX,n_mxY);
                ans=max(ans,tmp);
            }
            // DL
            // if(y == mnY || x == mxX)
            {
                int n_mxX=max(mxX,x+k);
                int n_mnY=min(mnY,y-k);
                __int128 tmp=getArea(mnX,n_mnY,n_mxX,mxY);
                ans=max(ans,tmp);
            }
            // DR
            // if(x == mxX || y == mxY)
            {
                int n_mxX=max(mxX,x+k);
                int n_mxY=max(mxY,y+k);
                __int128 tmp=getArea(mnX,mnY,n_mxX,n_mxY);
                ans=max(ans,tmp);
            }
        }
    }

    for(int i=0 ; i<=k ; i++){
        __int128 tmp=getArea(mnX,mnY,mxX+i,mxY+k-i);
        ans=max(ans,tmp);
    }
    cout<< to_str(ans) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}