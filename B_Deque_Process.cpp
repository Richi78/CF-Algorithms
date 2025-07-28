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
    int n; cin >> n; 
    deque<int> a;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a.push_back(x);
    }

    string ans="L";
    a.pop_front();
    bool turn=1; // 1-> max , 0-> min
    while((int)ans.size() != n){
        int l=a.front() , r=a.back();
        if(turn){
            //max
            if(l >= r){
                ans.push_back('L');
                a.pop_front();
            }else{
                ans.push_back('R');
                a.pop_back();
            }
            turn=!turn;
        }else{
            //min
            if(l<r){
                ans.push_back('L');
                a.pop_front();
            }else{
                ans.push_back('R');
                a.pop_back();
            }
            turn=!turn;
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

