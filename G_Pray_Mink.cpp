#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long n){
    for(int i=2 ; i*i<=n ; i++){
        if(n%i==0) return false;
    }
    return n>=2;
}

map<long long, long long> dp;

int dfs(long long node, map<long long,vector<long long>> &adj){
    if(dp[node] != 0) return dp[node];
    int ans=0;
    for(auto adjN : adj[node]){
        int tmp = 1 + dfs(adjN, adj);
        ans=max(ans,tmp);
    }
    return dp[node]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<long long> pot10(12);
    pot10[0]=1;
    for(int i=1 ; i<12 ; i++){
        pot10[i]=pot10[i-1]*10LL;
    }

    long long n; cin >> n;
    bool f = isPrime(n);
    if(!f){
        cout<<"0\n"; return 0;
    }
    map<long long,vector<long long>> adj;
    map<long long, long long> primes; // 0 no visitado , 1 es primo , 2 no es primo
    queue<long long> q;
    q.push(n);
    primes[n]=1;
    while(!q.empty()){
        long long node = q.front();
        q.pop();
        string s = to_string(node);
        int sz=s.size();
        for(int i=0 ; i<sz ; i++){
            long long new_n = (node/pot10[sz-i])*pot10[sz-i-1] + node%pot10[sz-i-1];

            if(primes[new_n] == 1){ // es primo
                q.push(new_n);
                adj[node].push_back(new_n);
            }else if(primes[new_n] == 2){ // no es primo
                // continue;
            }else if(primes[new_n] == 0){ // aun no se sabe
                if(isPrime(new_n)){
                    primes[new_n] = 1;
                    q.push(new_n);
                    adj[node].push_back(new_n);
                }else{
                    primes[new_n]=2;
                }
            }
        }
    }

    cout<< (f + dfs(n,adj)) <<"\n";

}