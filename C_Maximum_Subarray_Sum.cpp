#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const long long INF=1e18;

void solve(){
    long long n,k; cin >> n >> k;
    string s; cin >> s;
    vector<long long> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    long long ans=-INF;
    for(int i=0 ; i<n ; ){
        if(s[i] == '0'){
            a[i]=-INF;
            i++; 
            continue;
        }
        int j=i+1;
        while(j<n && s[j]=='1') j++;
        long long mn=0;
        long long cur=0;
        for(int k=i ; k<j ; k++){
            cur+=a[k];
            mn=min(mn,cur);
            ans=max(ans,cur-mn);
        }
        i=j;
    }
    if(ans > k){
        cout<<"NO\n"; return;
    }
    if(ans < k){
        int idx=0;
        while(idx<n && s[idx]=='1')idx++;
        if(idx == n){
            cout<<"NO\n"; return;
        }
        long long L=0 , R=0;
        { //L
            long long cur=0;
            for(int i=idx-1 ; i>=0 && s[i]=='1' ; i--){
                cur+=a[i];
                L=max(L,cur);
            }
        }
        { //R
            long long cur=0;
            for(int i=idx+1 ; i<n && s[i]=='1' ; i++){
                cur+=a[i];
                R=max(R,cur);
            }
        }
        a[idx]=k-L-R;
    }
    cout<<"YES\n";
    for(auto x : a) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}