#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

#define vdebug(x) cout<<#x<<": "; for(auto e:x)cout<<e<<" "; cout<<"\n";

long long binexp(long long a, long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

int main(){
    int n; cin >> n;

    int sum=n*(n+1)/2;
    if(sum & 1){
        cout<< "0\n"; return 0;
    }

    vector<int> dp(1);
    dp[0]=1;
    for(int i=1 ; i<=n ; i++){
        vector<int> new_dp(i*(i+1)/2 + 1);
        for(int sum=0 ; sum<dp.size() ; sum++){
            new_dp[sum] += dp[sum];
            new_dp[sum+i] += dp[sum];

            if(new_dp[sum] >= MOD) new_dp[sum] -= MOD;
            if(new_dp[sum+i] >= MOD) new_dp[sum] -= MOD;
        }
        // vdebug(new_dp)
        dp=new_dp;
    }

    int ans=( dp[sum/2] * binexp(2LL,1LL*(MOD-2)) )%MOD;
    cout<< ans <<"\n"; 
    return 0;
}