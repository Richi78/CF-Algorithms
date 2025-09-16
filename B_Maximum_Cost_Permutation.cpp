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
    vector<bool> in(n+1);
    vector<int> miss;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        if(a[i]) in[a[i]]=true;
    }    
    for(int i=n ; i>=1 ; i--){
        if(!in[i]) miss.push_back(i);
    }
    // vdebug(miss)
    int j=0;
    for(int i=0 ; i<n && j<miss.size() ; i++){
        if(a[i] == 0){
            a[i]=miss[j];
            j++;
        }
    }
    // vdebug(a)
    int tmp=1 , idx1=n;
    for(int i=0 ; i<n ; i++){
        if(a[i] == tmp) tmp++;
        else{
            idx1=i;
            break;
        }
    }
    if(idx1 == n){
        cout<< 0 <<"\n"; return;
    }
    tmp=n;
    int idx2=0;
    for(int i=n-1 ; i>=0 ; i--){
        if(a[i] == tmp) tmp--;
        else{
            idx2=i;
            break;
        }
    }
    // debug2(idx1,idx2)
    cout<< idx2-idx1+1 <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}