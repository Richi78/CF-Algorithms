#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n) , posx;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x; a[i]=x;
        while(x){
            posx.push_back(x);
            x>>=1;
        }
    } 
    
    int ans=1e6;
    for(auto x : posx){
        vector<int> cnt;
        for(int i=0 ; i<n ; i++){
            int y=a[i] , cur=0;
            while(y > x){
                y>>=1; cur++;
            }
            if(y == x) cnt.push_back(cur);
        }
        if(cnt.size() < k) continue;
        sort(all(cnt));
        ans = min(ans , accumulate(cnt.begin(),cnt.begin()+k,0LL) );
    }
    cout<<ans<<endl;
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    solve();
}

