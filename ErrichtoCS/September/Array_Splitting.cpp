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
    int n,k; cin >> n >> k;
    vector<pair<int,bool>> a;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a.emplace_back(x,false);
    }

    if(k == 1){
        int ans=0;
        for(int i=0 ; i<n ; i++){
            ans+=a[i].first;
        }
        cout<< ans <<"\n"; return;
    }

    vector<pair<int,int>> suf(n);
    suf[n-1].first=a[n-1].first;
    suf[n-1].second=n-1;
    for(int i=n-2 ; i>=0 ; i--){
        suf[i].first=a[i].first+suf[i+1].first;
        suf[i].second=i;
    }
    sort(all(suf));
    reverse(all(suf));

    int j=0;
    int cnt_k=0;
    while(cnt_k<k-1){
        if(suf[j].second != 0){
            a[suf[j].second].second=true;
            cnt_k++;
        }
        j++;
    }

    int cnt=1 , ans=0;
    for(int i=0 ; i<n ; i++){
        ans+=cnt*a[i].first;
        if(i+1<n && a[i+1].second==true) cnt++;
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