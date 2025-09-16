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
    vector<int> a(n+1) , pref(n+1);
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
        pref[i]+=a[i]+pref[i-1];
    }
    int sum1=0 , sum2=0 , sum3=0;

    for(int i=1 ; i<=n-2 ; i++){
        sum1=(pref[i]-pref[0]);
        for(int j=i+1 ; j<=n-1 ; j++){
            sum2=(pref[j]-pref[i]);
            sum3=(pref[n]-pref[j]);
            sum1%=3;
            sum2%=3;
            sum3%=3;
            if( (sum1 == sum2 && sum2 == sum3) || (sum1!=sum2 && sum2!=sum3 && sum1!=sum3) ){
                cout<< i <<" "<< j <<"\n"; 
                return;
            }
        }
    }    
    cout<< "0 0\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}