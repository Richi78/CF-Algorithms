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
    int e=0;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        int tmp=a[i];
        while(tmp%2 == 0){
            e++;
            tmp>>=1; 
        }
    }
    
    int pos_e=n/2;

    int x=n;
    x-=e;
    if(x<=0){
        cout<< "0\n"; return;
    }

    int ans=0;

    vector<pair<int,int>> valid;
    {
        for(int i=2 ; i<=n ; i+=2){
            int cnt=0 , tmp=i;
            while(tmp%2 == 0){
                cnt++;
                tmp>>=1;
            }
            valid.emplace_back(cnt,i);
        }
    }
    sort(all(valid));
    reverse(all(valid));
    for(auto [w,z] : valid){
        if(x-w <= 0){
            cout<< ans+1 <<"\n"; return;
        }else{
            x-=w;
            ans++;
        }
    }
    
    cout<<"-1\n"; return;
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}