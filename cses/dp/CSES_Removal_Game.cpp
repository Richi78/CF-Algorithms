#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    long long sum=0;
    for(int &x : a) cin >> x , sum+=x;

    vector<vector<long long>> dp(n,vector<long long>(n));
    // dp[i][j] point difference for current player
    for(int L=n-1 ; L>=0 ; L--){
        for(int R=L ; R<n ; R++){
            if(L == R) 
                dp[L][R]=a[L];
            else 
                dp[L][R] = max(a[L]-dp[L+1][R],a[R]-dp[L][R-1]);
        }
    }
    cout<< (sum+dp[0][n-1])/2 <<"\n";
}