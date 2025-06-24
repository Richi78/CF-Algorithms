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

void solve(){
    int n; cin >> n;
    vector<int> a(n); 
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int i=0;
    while(i<n){
        int mn=min_element(a.begin()+i , a.end()) - a.begin();
        // debug1(i)
        if(mn == i){
            i++; continue;
        }
        for(int j=mn-1 ; j>=i ; j--){
            swap(a[j],a[j+1]);
        }
        i+=(mn-i);
    }
    
    // vdebug(vis)
    for(int j=0 ; j<n ; j++){
        cout<<a[j]<<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}