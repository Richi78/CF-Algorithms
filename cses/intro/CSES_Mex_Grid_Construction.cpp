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
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            set<int> st;
            for(int k=0 ; k<j ; k++){
                st.insert(a[i][k]);
            }
            for(int k=0 ; k<i ; k++){
                st.insert(a[k][j]);
            }
            int mex=0;
            while(st.count(mex)) mex++;
            a[i][j]=mex;
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}