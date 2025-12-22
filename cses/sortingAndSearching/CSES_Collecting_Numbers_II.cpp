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
    int n,q; cin >> n >> q;
    vector<int> b(n+1);
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++){
        int x; cin >> x;
        b[i]=x;
        a[x]=i;
    }
    int ans=1;
    for(int i=1 ; i+1<=n ; i++){
        if(a[i] > a[i+1]) ans++;
    }
    for(int i=0 ; i<q ; i++){
        int u,v; cin >> u >> v;
        int x=min(b[u],b[v]) , y=max(b[u],b[v]);
        swap(b[u],b[v]);
            int b4_x1=0,b4_x2=0,b4_y1=0,b4_y2=0,cur_x1=0,cur_x2=0,cur_y1=0,cur_y2=0;
            if(x-1 >= 1) b4_x1=a[x]>a[x-1];
            if(y-1 >= 1) b4_y1=a[y]>a[y-1];
            if(x+1 <= n) b4_x2=a[x+1]>a[x];
            if(y+1 <= n) b4_y2=a[y+1]>a[y];
            
            swap(a[x],a[y]);
            
            if(x-1 >= 1) cur_x1=a[x]>a[x-1];
            if(y-1 >= 1) cur_y1=a[y]>a[y-1];
            if(x+1 <= n) cur_x2=a[x+1]>a[x];
            if(y+1 <= n) cur_y2=a[y+1]>a[y];

            if(x-1 >= 1){
                if(b4_x1 == 0 && cur_x1 == 1) ans--;
                else if( b4_x1 == 1 && cur_x1 == 0) ans++;
            }
            if(y-1 >= 1){
                if(b4_y1 == 0 && cur_y1 == 1) ans--;
                else if(b4_y1 == 1 && cur_y1 == 0) ans++;
            }
            // y-x>1 to not overcount when y-1 == x
            if(x+1 <= n && y-x>1){
                if(b4_x2 == 0 && cur_x2 == 1) ans--;
                else if(b4_x2 == 1 && cur_x2 == 0) ans++;
            }
            if(y+1 <= n){
                if(b4_y2 == 0 && cur_y2 == 1) ans--;
                else if(b4_y2 == 1 && cur_y2 == 0) ans++;
            }

        cout<< ans <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}