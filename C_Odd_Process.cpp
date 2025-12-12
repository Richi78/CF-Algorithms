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
    int n; cin >> n;
    vector<int> e , o;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        if(x&1) o.push_back(x);
        else e.push_back(x);
    }
    sort(all(e));
    sort(all(o));
    if(o.size() == 0){
        for(int i=0 ; i<n ; i++){
            cout<< 0 <<" ";
        }
        cout<<"\n";
        return;
    }
    if(e.size() == 0){
        for(int i=1 ; i<=n ; i++){
            if(i&1) cout<< o.back() <<" ";
            else cout<< "0 ";
        }
        cout<<"\n"; return;
    }

    int i=o.size()-1; // ptr o
    int j=e.size()-1; // ptr e
    vector<int> ans(n);
    ans[0]=o[i];
    int sum=ans[0];
    int k=n-1;
    while(k && j>=0){
        ans[n-k]=sum+e[j];
        sum=ans[n-k];
        j--;
        k--;
    }

    vector<int> pref(e.size()+1);
    for(int i=0 ; i<e.size() ; i++){
        pref[i+1]=pref[i]+e[i];
    }

    int cur=0;
    int sz=e.size();
    while(k){
        int tmp=n-k+1;
        if( (tmp - (sz+1) )%2 == 0 ){
            if(o.size() - cur >= 1){
                int num_e=tmp-cur-1;
                int l=sz-num_e;
                if(l>=0){
                    ans[n-k]=o.back()+pref[sz]-pref[l];
                }
            }
        }else{
            // take cur odds
            cur+=2;
            if(o.size() - cur >= 1){
                int num_e=tmp-cur-1;
                int l=sz-num_e;
                if(l>=0){
                    ans[n-k]=o.back()+pref[sz]-pref[l];    
                }
            }
        }
        k--;
    }
    for(auto y : ans) cout<< y <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}