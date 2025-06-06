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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int f(vector<int> &a, int s, vector<int> &ans, int meta, int cnt){
    if(a[s] == meta) return ans[meta]=cnt+1;

    int x=f(a , a[s] , ans , meta , cnt+1);

    return ans[s]=x;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++) cin >> a[i];

    vector<int> ans(n+1);
    for(int i=1 ; i<=n ; i++){
        if(ans[i] == 0){
            f(a,i,ans,i,0);            
        }
    }
    
    for(int i=1 ; i<=n ; i++){
        cout<< ans[i] << " ";
    }
    cout<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}