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
    int n,k; cin >> n >> k;
    multiset<int> a;
    vector<int> b(n);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a.insert(x);
    }    
    for(int i=0 ; i<n ; i++){
        cin >> b[i];
    }    
    sort(all(b));
    int ans=0;
    for(int i=0 ; i<n && a.size()>0 ; i++){
        int y=b[i]+1;
        if((k-b[i]) < 0) continue;
        int l=0 , r= ((k-b[i])/y)+10;
        while(r-l>1){
            int mid=l+(r-l)/2;
            int x=mid*y+b[i];
            if(x < y) l=mid;
            else if(x > k) r=mid;
            else l=mid;
        }
        int x=l*y+b[i];
        if(x > k || x <= y) continue;
        auto it=a.lower_bound(l);
        if(it == a.end()){
            it--;
            ans++;
        }else if(*it != l){
            if(it == a.begin()) continue;
            else it--;
            ans++;
        }else{
            ans++;
        }
        a.erase(it);
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