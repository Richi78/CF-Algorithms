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
    vector<int> a(n+1) , pref0(n+1) , pref1(n+1);
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
        int x=a[i];
        pref0[i]=pref0[i-1];
        pref1[i]=pref1[i-1];
        if(x == 0) pref0[i]++;
        if(x == 1) pref1[i]++;
    }    
    vector<int> left(n+1);
    for(int i=1 ; i<=n ; i++){
        if(i+1<=n){
            if(a[i]==0 && a[i+1]==0 || a[i]==1 && a[i+1]==1) left[i]=1;
            else left[i]=0;
        }else left[i]=1;
        left[i]+=left[i-1];
    }
    for(int rep=0 ; rep<q ; rep++){
        int l,r; cin >> l >> r;
        int cnt0=pref0[r]-pref0[l-1]; 
        int cnt1=pref1[r]-pref1[l-1];
        if(cnt0%3!=0 || cnt1%3!=0){
            cout<<"-1\n"; continue;
        }
        int tmp=left[r-1]-left[l-1];
        int ans=cnt0/3 + cnt1/3;
        if(tmp == 0) ans++;
        cout<< ans <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}