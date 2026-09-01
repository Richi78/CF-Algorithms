#include <bits/stdc++.h>

using namespace std;

#define vdebug(x) cout<<#x<<": "; for(auto e : x) cout<< e <<" "; cout<<"\n";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> dp;
    dp.push_back(0);
    for(int rep=0 ; rep<n ; rep++){
        int x; cin >> x;
        int i = lower_bound(dp.begin(),dp.end(), x) - dp.begin();
        if(i == dp.size()) dp.push_back(0);
        dp[i]=x;
        // vdebug(dp)
    }
    cout<< dp.size()-1 <<"\n";
}