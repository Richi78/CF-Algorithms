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
    int ans=1;
    set<int> s={a[0]};
    set<int> s2;    
    int i=1;
    while(i<n){
        for(auto x : s){
            if(s2.count(x) == 0){
                while(i<n){
                    if(a[i] != x){
                        s2.insert(a[i]);
                        i++;
                    }
                    else {
                        s2.insert(a[i]);
                        i++;
                        break;
                    }
                }
            }
            if(i>=n)break;
        }
        bool ok=true;
        for(auto x:s){
            if(s2.count(x)==0){
                ok=false; break;
            }
        }
        if(ok){
            s=s2;
            s2.clear();
            ans++;
        }
    }
    cout<< ans <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}