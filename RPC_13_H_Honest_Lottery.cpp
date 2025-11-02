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
    int n; cin >> n;
    vector<int> freq(51);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<10 ; j++){
            for(int k=0 ; k<5 ; k++){
                int x; cin >> x;
                freq[x]++;
            }
        }
    }
    vector<int> ans;
    for(int i=1 ; i<=50 ; i++){
        if(freq[i] > 2*n) ans.push_back(i);
    }

    if(ans.size() == 0){
        cout<<"-1\n";
    }else{
        for(int i=0 ; i<ans.size() ; i++){
            cout<< ans[i];
            cout<< (i==(ans.size()-1)?"":" ");
        }
        cout<<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}