#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+100;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,m; cin >> n >> m;
    vector<int> a(m);
    for(int &x : a) cin >> x;

    vector<bool> dp(N);
    dp[0]=true;

    for(auto x : a){
        for(int i=0 ; i<N ; i++){
            if(dp[i] && i+x<N) dp[i+x]=true;
        }
    }

    vector<int> nxt(N);
    int last = INF;
    for (int i = N-1; i >= 0; i--) {
        if (dp[i])
            last = i;
        nxt[i] = last;
    }

    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        cout<< (nxt[x] - x) <<"\n";
    }

    return 0;
}