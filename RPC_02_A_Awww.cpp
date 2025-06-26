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
    int n,m,r; cin >> n >> m >> r;
    vector< pair<int,int> > a;
    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        int cnt=0;
        for(int j=0 ; j<m ; j++){
            if(s[j] == 'P')cnt++;
        }
        a.emplace_back(cnt,i+1);
    }

    // for(auto x : a){
    //     debug2(x.F, x.S)
    // }

    for(int i=n-1 ; i>=0 ; i--){
        if(a[i].F){
            a[i].F--;
            string s1,s2; cin >> s1 >> s2;
            int cnt=count(all(s2), 'y');
            if(cnt>3){
                cnt-=3;
                for(int j=i ; j-1>=0 && cnt ; j--){
                    swap(a[j],a[j-1]); cnt--;
                }
            } 
            i=n;
        }
    }

    for(int i=0 ; i<n ; i++){
        if(a[i].S == r){
            cout<< i+1 <<"\n"; return;
        }
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}