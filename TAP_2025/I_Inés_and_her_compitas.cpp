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
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    vector<int> dec(n);
    for(int rep=0 ; rep<m ; rep++){
        int x,y; cin >> x >> y;
        int one=0 , two=0;
        for(int i=0 ; i<n ; i++){
            cin >> dec[i];
            if(dec[i] == 1) one++;
            else two++;
        }
        int with_I=x/(one+1);
        bool flag=true; // true-> Ines play 1    false-> plays 2
        if(y > with_I){
            flag=false;
            if(one == 0) with_I=0;
            else with_I=x/one;
        }
        for(int k=0 ; k<n ; k++){
            if(dec[k] == 1){
                a[k]+=with_I;
            }else{
                a[k]+=y;
            }
        }
        if(flag) a[n]+=with_I;
        else a[n]+=y;
    } 
    for(auto x : a) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}