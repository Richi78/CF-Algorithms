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

// For Meeting Rooms II on leetcode

struct Event{
    int x;
    bool isEnd;
    bool operator < (Event b){
        // in case of tie for x-coordinate, process end first
        return make_pair(x,!isEnd) < make_pair(b.x,!b.isEnd);
    }
};

// [2,2]
// [1,5] [5,10]
//        ^
// S S E E

void solve(){
    int n; cin >> n;
    vector<Event> values;
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        values.push_back(Event{x,false});
        values.push_back(Event{y,true});
    }

    sort(all(values));
    int ans=0;
    int active=0;
    for(Event x : values){
        if(x.isEnd){
            active--;
        }else{
            active++;
        }
        ans=max(ans,active);
    }
    
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}