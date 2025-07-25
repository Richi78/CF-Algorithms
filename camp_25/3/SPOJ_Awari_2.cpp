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

void solve(int n){
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }

    for(int i=n ; i>=1 ; i--){
        if(a[i]==0) a.pop_back();
        else if(a[i]<i || a[i]>i){
            cout<<"N\n"; return;
        }else{
            break;
        }
    }

    int i=1;
    while(i<=n){
        if(a[i] == i){
            a[i]=0;
            for(int j=1 ; j<i ; j++){
                a[j]++;
            }
            i=0;
        }
        i++;
    }
    cout<< (accumulate(all(a),0LL)==0?"S\n":"N\n");
}

signed main(){
    FIO;
    int n;
    while(cin >> n){
        if(n == -1) break;
        solve(n);
    }
}