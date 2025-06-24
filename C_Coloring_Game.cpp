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

const int N=1e5+5;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int cnt=0;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            auto it = lower_bound( a.begin()+j+1 , a.end() , a[i]+a[j] );
            int end = it - a.begin();

            auto it2 = upper_bound( a.begin()+j+1, a.begin()+end , a[n-1]-a[i]-a[j] );
            cnt += (a.begin()+end) - it2;
        }
    }
    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}