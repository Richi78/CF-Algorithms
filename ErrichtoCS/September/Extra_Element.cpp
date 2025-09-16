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
    vector<pair<int,int>> a(n);
    for(int i=1 ; i<=n ; i++){
        int x; cin >> x;
        a[i-1]={x,i};
    } 
    sort(all(a));

    map<int,int> mp;
    for(int i=0 ; i+1<n ; i++){
        int x=a[i+1].first-a[i].first;
        mp[x]++;
    }

    // not done yet

    // int r=a[1].first-a[0].first;
    int r=mp.begin()->first;
    for(auto [x,y] : mp){
        debug2(x,y)
        if(y > mp[r]) r=x;
    }
    debug1(r)

    
    int j=0 , ans=-1;
    int cnt=0;
    int banned=-1;
    int from=1;
    if(a[1].first - a[0].first != r){
        from=2;
        j=1;
        cnt++;
        ans=1;
    }
    for(int i=from ; i<n ; i++){
        if(a[i].first - a[j].first != r){
            cnt++;
            if(cnt == 1){
                banned=i;
                ans=a[i].second;
                debug1(ans)
                continue;
            }
        }
        if(cnt >= 2){
            cout<< "-1\n"; return;
        }
        if(++j == banned) j++;
    }
    if(ans == -1){
        cout<< "1\n";
    }else{
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