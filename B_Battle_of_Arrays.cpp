#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int A,B; cin >> A >> B;
    multiset<int> a , b;
    for(int i=0 ; i<A ; i++){
        int x; cin >> x;
        a.insert(x);
    }
    for(int i=0 ; i<B ; i++){
        int x; cin >> x;
        b.insert(x);
    }
    bool turn=1; // A
    while(!a.empty() && !b.empty()){
        if(turn){
            int x=*a.rbegin();
            int y=*b.rbegin();
            b.erase(prev(b.end()));
            if(x < y) b.insert(y-x);
        }else{
            int x=*b.rbegin();
            int y=*a.rbegin();
            a.erase(prev(a.end()));
            if(x < y) a.insert(y-x);
        }
        turn=!turn;
    }
    cout<< (turn?"Bob":"Alice") <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}