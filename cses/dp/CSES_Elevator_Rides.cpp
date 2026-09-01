#include <bits/stdc++.h>

using namespace std;

const int INF=1e9+100;

int main(){
    int n,x; cin >> n >> x;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<pair<int,int>> dp(1<<n);
    dp[0]={1,0};

    for(int mask=1 ; mask<(1<<n) ; mask++){
        pair<int,int> mn = make_pair(INF,INF);
        for(int i=0 ; i<n ; i++){
            if(mask & (1<<i)){
                int end = a[i];
                pair<int,int> last = dp[mask ^ (1<<i)];
                if(end+last.second <= x){
                    mn=min(mn, make_pair(last.first,last.second+end));
                }else{
                    mn=min(mn, make_pair(last.first+1,end));
                }
            }
        }
        dp[mask]=mn;
    }
    cout<< dp[(1<<n)-1].first <<"\n";
    return 0;
}