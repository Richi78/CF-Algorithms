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

map<int,vector<string>> mp;

void solve(){
    int n,A,B; cin >> n >> A >> B;
    string a=mp[n][A-1] , b=mp[n][B-1];
    int x=0 , y=0;
    vector<bool> vis(a.size());
    for(int i=0 ; i<a.size() ; i++){
        if(a[i] == b[i]){
            x++;
            vis[i]=true;
        }
    }
    cout<< x <<"A"<< a.size()-x <<"B\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);

    for(auto x : {"12","123","1234"}){
        int n=stoll(x);
        string s=x;
        do{
            mp[n].push_back(s);
        }while(next_permutation(all(s)));
    }

    int tc;cin>>tc;
    while(tc--)solve();
}