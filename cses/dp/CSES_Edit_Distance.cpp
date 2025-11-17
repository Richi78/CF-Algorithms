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

const int INF=1e18;

void solve(){
    string s1,s2; cin >> s1 >> s2;
    int A=s1.size() , B=s2.size();
    vector<vector<int>> dp(A+1, vector<int>(B+1,INF));
    dp[0][0]=0;
    for(int i=0 ; i<=A ; i++){
        for(int j=0 ; j<=B ; j++){
            // prefA[0..i] -> prefB[0..j+1]
            // A -> B
            if(j+1<=B)
                dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
            
            // prefA[0..i+1] -> prefB[0..j]
            // B -> A
            if(i+1<=A)
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);

            // change letter s1[i] into s2[j]
            if(i<A && j<B){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                }else{
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
                }
            }
        }
    }
    cout<< dp[A][B] <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}