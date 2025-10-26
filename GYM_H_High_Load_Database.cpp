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
    vector<int> pref(n+1);
    int mx=-1;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        mx=max(mx,x);
        pref[i+1]=pref[i]+x;
    }

    int q; cin >> q;
    unordered_map<int,int> mp;
    for(int rep=0 ; rep<q ; rep++){
        int x; cin >> x;
        if(x < mx){
            cout<< "Impossible\n"; continue;
        }

        if(x == 1){
            cout<< n <<"\n"; continue;
        }

        if(mp.find(x) != mp.end()){
            cout<< mp[x] <<"\n"; continue;
        }

        int ans=0;
        int pos=0;
        while(pos < n){
            int target=pref[pos]+x;;
            int l=pos , r=n;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(pref[mid]<=target){
                    pos=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            // debug2(pos,target) 
            ans++;
        }
        mp[x]=ans;
        cout<< ans <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}