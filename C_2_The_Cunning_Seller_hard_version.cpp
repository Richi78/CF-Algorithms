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

vector<int> p(25);

int binexp(int a, int b){
    if(b<0) return 0;
    int ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a;
    int sum=0;
    while(n){
        a.push_back(n%3);
        n/=3;
        sum+=a.back();
    }
    if(sum > k){
        cout<<"-1\n"; return;
    }
    reverse(all(a));
    int left=k-sum;
    left/=2;
    for(int i=0 ; i<a.size()-1 && left>0 ; i++){
        if(a[i] <= left) a[i+1]+=3*a[i] , left-=a[i], a[i]=0;
        else a[i+1]+=3*left , a[i]-=left , left=0;
    }
    int ans=0 , sz=a.size();
    for(int i=0 ; i<a.size() ; i++){
        ans += a[i] * p[sz-1-i];
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    for(int i=0 ; i<p.size() ; i++){
        p[i]=binexp(3,i+1)+i*binexp(3,i-1);
    }
    int tc;cin>>tc;
    while(tc--)solve();
}