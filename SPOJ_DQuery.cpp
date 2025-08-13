#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

struct Q{
    int l,r,idx;
};

const int N=1e6+10;
int rootN;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    rootN=sqrtl(n);
    
    int q; cin >> q;
    vector<Q> queries(q);
    for(int i=0 ; i<q ; i++){
        int l,r; cin >> l >> r;
        queries[i].l=l-1;
        queries[i].r=r-1;
        queries[i].idx=i;
    }

    sort(all(queries),[&](Q x, Q y){
        if(x.l/rootN == y.l/rootN){
            return x.r > y.r;
        }
        return x.l/rootN < y.l/rootN;
    });

    vector<int> freq(N);
    int l=0 , r=-1;
    int ans=0;
    vector<int> res(q);
    for(int i=0 ; i<q ; i++){
        int query_l=queries[i].l;
        int query_r=queries[i].r;
        while(r<query_r){
            r++;
            freq[a[r]]++;
            if(freq[a[r]] == 1) ans++;
        }
        while(r>query_r){
            freq[a[r]]--;
            if(freq[a[r]] == 0) ans--;
            r--;
        }
        while(l<query_l){
            freq[a[l]]--;
            if(freq[a[l]] == 0) ans--;
            l++;
        }
        while(query_l<l){
            l--;
            freq[a[l]]++;
            if(freq[a[l]] == 1) ans++;
        }
        res[queries[i].idx]=ans; 
    }
    for(auto x : res) cout<< x <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}