#include <bits/stdc++.h>

using namespace std;

#define vdebug(x) cout<<#x<<": "; for(auto e : x) cout<<e<<" "; cout<<"\n";
#define debug1(x) cout<<#x<<": "<<x<<"\n";
#define debug2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<"\n";

const int MOD=1e9+7;
const int N=1e6+10;
const int INF=1e9+100;

void add_self(long long &a, long long b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1,s2; cin >> s1 >> s2;
    int row=s2.size() , col=s1.size();
    vector<vector<int>> dp(row+1,vector<int>(col+1, INF));
    for(int i=0 ; i<=col ; i++) dp[0][i]=i;
    for(int i=0 ; i<=row ; i++) dp[i][0]=i;


    for(int i=1 ; i<=row ; i++){
        for(int j=1 ; j<=col ; j++){
            dp[i][j]=min({dp[i-1][j]+1 , dp[i][j-1]+1 , dp[i-1][j-1]+1});
            if(s2[i-1] == s1[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
        }
    }
    cout<< dp[row][col] <<"\n";
}