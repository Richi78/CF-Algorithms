#include <bits/stdc++.h>

using namespace std;

#define vdebug(x) cout<<#x<<": "; for(auto e : x) cout<<e<<" "; cout<<"\n";

const int INF=1e9+100;
vector<int> dp;

vector<int> getPrevGreater(vector<int> &a){
    stack<pair<int,int>> st;
    st.push(make_pair(INF,-1));
    int n=a.size();
    vector<int> ans(n);
    for(int i=0 ; i<n ; i++){
        while(st.top().first <= a[i]) st.pop();
        ans[i]=st.top().second;
        st.push(make_pair(a[i],i));
    }
    return ans;
}

vector<int> getNextGreater(vector<int> &a){
    int n=a.size();
    stack<pair<int,int>> st;
    st.push(make_pair(INF,n));
    vector<int> ans(n);
    for(int i=n-1 ; i>=0 ; i--){
        while(st.top().first <= a[i]) st.pop();
        ans[i]=st.top().second;
        st.push(make_pair(a[i],i));
    }
    return ans;
}

int f(int i, vector<int> &prv, vector<int> &nxt){
    if(dp[i] != 0) return dp[i];
    int n=prv.size();
    dp[i]=1;
    if(prv[i] != -1) dp[i] = max(dp[i], 1+f(prv[i],prv,nxt));
    if(nxt[i] != n) dp[i] = max(dp[i], 1+f(nxt[i],prv,nxt));
    return dp[i];
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> nxt=getNextGreater(a);
    vector<int> prv= getPrevGreater(a);

    // vdebug(prv)
    // vdebug(nxt)
    dp.resize(n);
    int mx=0;
    for(int i=0 ; i<n ; i++){
        mx=max(mx, f(i,prv,nxt));
    }
    cout<< mx <<"\n";
}