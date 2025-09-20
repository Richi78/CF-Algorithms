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

bool validate(vector<int> &a, int r){
    int cur=r;
    for(int i=0 ; i<a.size() ; i++){
        if(cur >= a[i]) return false;
        cur=a[i]+abs(a[i]-cur);
    }
    return true;
}

int getDist(int a, int b, int c, int d){
    return abs(a-c)+abs(b-d);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n-1);
    int x,y;
    cin >> x >> y;
    int last_x=x , last_y=y;
    for(int i=0 ; i<n-1 ; i++){
        cin >> x >> y;
        a[i]=getDist(last_x,last_y,x,y);
        if(i)a[i]+=a[i-1];
        last_x=x; last_y=y;
    }
    if(n == 2){
        cout<< a[0]-1 <<"\n";
        return;
    }
    int ub=max(0LL, a[0]-1);
    int last=0;
    for(int i=1 ; i<n-1 && ub ; i++){
        ub=min(ub,abs(a[i]-a[i-1])-1);
    }
    if(ub==0){
        cout<< "-1\n"; return;
    }

    // debug1(ub)
    int ans=-1e18;
    int l=1 , r=ub;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(validate(a,mid)){
            ans=max(ans,mid);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(ans == -1e18) cout<< "-1\n";
    else cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}