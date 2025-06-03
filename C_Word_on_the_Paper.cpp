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
    vector<string> a(8);
    for(int i=0 ; i<8 ; i++){
        cin >> a[i];
    }
    int idx=-1 , idy=-1;
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<8 ; j++){
            if(a[i][j] != '.'){
                idx=i; idy=j;
                break;
            }
        }
        if(idx!=-1)break;
    }
    string s="";
    for(int i=idx ; i<8 ; i++){
        if(a[i][idy] != '.')
            s.push_back(a[i][idy]);
    }
    cout<<s<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}