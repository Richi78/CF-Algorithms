#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%MOD;
        a=1LL*a*a%MOD;
        b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> a(n);
        map<int,int> mp;
        for(int &x : a) cin >> x , mp[x]++;
        sort(a.begin() , a.end());
        long long ans=1;
        for(int i=n-1 ; i>=0 ; i--){
            if(mp[a[i]] == 1){
                ans = (ans + binexp(a[i]-1, n-i))%MOD;
            }else break;
        }

        cout<< ans <<"\n";
    }
}