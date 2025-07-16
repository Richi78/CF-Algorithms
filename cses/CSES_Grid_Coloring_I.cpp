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
    int n,m; cin >> n >> m;
    vector<string> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            set<char> st;
            if(i-1>=0) st.insert(a[i-1][j]);
            if(j-1>=0) st.insert(a[i][j-1]);
            st.insert(a[i][j]);
            for(char k='A' ; k<='D' ; k++){
                if(st.count(k) ==0 ){
                    a[i][j]=k;
                    break;
                }
            }
        }
        cout<< a[i] <<"\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}