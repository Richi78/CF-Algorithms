#include <bits/stdc++.h>

using namespace std;

long long f(long long a){
    string s=to_string(a);
    int n=s.size();
    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2,vector<long long>(11)));
    // dp[]    []      []
    //   pos smaller  digit
    dp[0][0][10]=1;
    for(int pos=0 ; pos<n ; pos++){
        for(int smaller : {0,1}){
            for(int digit=0 ; digit<=10 ; digit++){
                for(int nxt=0 ; nxt<10 ; nxt++){
                    if(digit == nxt) continue;
                    if(!smaller && (nxt>(s[pos]-'0'))) continue;

                    int nxt_dig=nxt;
                    if(nxt==0 && digit==10){ // number not started
                        nxt_dig=10; // set not started
                    }
                    dp[pos+1][smaller || (nxt < (s[pos]-'0'))][nxt_dig] += dp[pos][smaller][digit];
                }
            }
        }
    }
    long long ans=0;
    for(int i=0 ; i<=10 ; i++){
        ans += dp[n][1][i];
    }
    return ans;
}

int main(){
    long long a,b; cin >> a >> b;
    cout<< (f(b+1) - f(a)) <<"\n";
    return 0;
}