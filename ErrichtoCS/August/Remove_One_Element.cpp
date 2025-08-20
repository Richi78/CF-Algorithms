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
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    vector<array<int,2>> ranges;
    int start=-1 , cnt=-1 , cur=-1;
    for(int i=0 ; i<n ; i++){
        if(start == -1){
            start=i;
            cnt++;
        }else if(a[i] <= cur){
            ranges.push_back({start,start+cnt});
            start=i;
            cnt=0;
        }else{
            cnt++;
        }
        cur=a[i];
    }
    ranges.push_back({start,start+cnt});
    // for(auto x : ranges){
        // debug2(x[0],x[1])
    // }
    if(ranges.size() == 1){
        cout<< n <<"\n"; return;
    }
    int ans=1;
    for(int i=1 ; i<ranges.size() ; i++){
        int last=ranges[i-1][1]-ranges[i-1][0]+1;
        int cur=ranges[i][1]-ranges[i][0]+1;
        ans=max(ans,last);
        ans=max(ans,cur);
        if(cur == 1){
            ans=max(ans,last);
        }else if(last == 1){
            ans=max(ans,cur);
        }else{
            if(a[ranges[i][0]] > a[ranges[i-1][1]-1]){
                ans=max(ans,last+cur-1);
            }
            if(a[ranges[i][0]+1] > a[ranges[i-1][1]]){
                ans=max(ans, last+cur-1);
            }
        }
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