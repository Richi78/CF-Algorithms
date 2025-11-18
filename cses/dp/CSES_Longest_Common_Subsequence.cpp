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
    int A,B; cin >> A >> B;
    vector<int> a(A) , b(B);
    for(int i=0 ; i<A ; i++) cin >> a[i];
    for(int i=0 ; i<B ; i++) cin >> b[i];

    vector<vector<int>> dp(A+1,vector<int>(B+1));
    for(int i=0 ; i<=A ; i++){
        for(int j=0 ; j<=B ; j++){
            if(i<A && j<B && a[i] == b[j]){
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
            }else{
                if(j<B) dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
                if(i<A) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            }
        }
    }
    vector<int> lcs;
    int i=A , j=B;
    while(i>0 && j>0){
        if(a[i-1] == b[j-1] && dp[i][j] == dp[i-1][j-1]+1){
            lcs.push_back(a[i-1]);
            i--; j--;
        }else if(dp[i-1][j] == dp[i][j]){
            i--;
        }else{
            j--;
        }
    }
    reverse(all(lcs));
    cout<< dp[A][B] <<"\n";
    for(auto x : lcs) cout<< x <<" ";
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