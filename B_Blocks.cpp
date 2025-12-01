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

vector<int> f(vector<int> &posX){
    vector<int> ans;
    for(int i=0 ; i<posX.size() ; i+=2){
        int ini=posX[i] , fin=posX[i+1];
        while(fin-ini > 1){
            ans.push_back(fin-1);
            fin--;
        }
        ans.push_back(ini);
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int B=0 , W=0;
    vector<int> posB, posW;
    for(int i=0 ; i<n ; i++){
        if(s[i] == 'W'){
            posW.push_back(i);
            W++;
        }else{
            posB.push_back(i);
            B++;
        } 
    }

    if(B&1 && W&1){
        cout<< "-1\n"; return;
    }

    if(B==0 || W==0){
        cout<< "0\n"; return;
    }

    vector<int> ans;
    if(B&1) ans=f(posW);
    else ans=f(posB);
    
    cout<< ans.size() <<"\n";
    for(auto x : ans) cout<< x+1 <<" ";
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