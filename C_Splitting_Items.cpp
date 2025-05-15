#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    sort(all(a));
    int mx=a.back() , cnt=0;
    bool turn=1; // alice -> 1 
    int ans=0;
    for(int i=n-1 ; i>=0 ; i--){
        if(cnt % 2 == 0){
            mx=a[i]; cnt=1;
        }else{
            int tmp=mx-a[i];
            if(k > tmp){
                a[i]=mx;
                k-=tmp;
                cnt++;
            }else{
                a[i]+=k;
                k=0;
            }
        }

        if(turn) ans+=a[i];
        else ans-=a[i];
        turn=!turn;
    }
    cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}
