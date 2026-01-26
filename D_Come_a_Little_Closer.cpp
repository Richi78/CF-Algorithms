#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
// #define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int INF=1e9+5;
long long f(vector<pair<int,int>> &a, int target, int type){
    int n=a.size();
    int mxX2=-INF, mnX2=INF , mxY2=-INF , mnY2=INF;
    for(int i=0 ; i<n ; i++){
        int x=a[i].first , y=a[i].second;
        if((type==1?x:y) == target) continue;
        mxX2=max(mxX2,x); mnX2=min(mnX2,x);
        mxY2=max(mxY2,y); mnY2=min(mnY2,y);
    }
    long long h=mxY2-mnY2+1 , w=mxX2-mnX2+1;
    if(h*w>=n) return h*w;
    else return min((h+1)*w,h*(w+1));
}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> a;
    map<int,int> mpX,mpY;
    int mxX=-INF, mnX=INF , mxY=-INF , mnY=INF;
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        a.emplace_back(x,y);
        mxX=max(mxX,x); mnX=min(mnX,x);
        mxY=max(mxY,y); mnY=min(mnY,y);
        mpX[x]++; mpY[y]++;
    }    
    long long ans=1LL*(mxX-mnX+1LL)*(mxY-mnY+1LL);
    if(mpX[mnX]==1){
        ans=min(ans,f(a,mnX,1));
    } 
    if(mpX[mxX]==1){
        ans=min(ans,f(a,mxX,1));
    }
    if(mpY[mnY]==1){
        ans=min(ans,f(a,mnY,0));
    }
    if(mpY[mxY]==1){
        ans=min(ans,f(a,mxY,0));
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