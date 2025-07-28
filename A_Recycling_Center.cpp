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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,c; cin >> n >> c;
    vector<int> a;
    int cnt=0;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        if(x>c) cnt++;
        else a.push_back(x);
    }
    sort(all(a));
    n=(int)a.size();
    while((int)a.size() != 0){
        a[(int)a.size()-1]=0;
        for(int i=(int)a.size()-2 ; i>=0 ; i--){
            if(a[i]*2 > c){
                cnt++; 
                a[i]=0;
            }else{
                a[i]*=2;
            }
        }
        vector<int> tmp;
        for(int i=0 ; i<(int)a.size() ; i++){
            if(a[i] != 0) tmp.push_back(a[i]);
        }
        a=tmp;
    }
    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}