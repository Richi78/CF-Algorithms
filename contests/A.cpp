#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(vector<int> &a, int p){
    int ans=0;
    for(auto &x: a){
        ans+=labs(p-x);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int n,l,r; cin >> n >> l >> r;
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        while(r-l >= 3){
            int mid1=l+(r-l)/3;
            int mid2=r-(r-l)/3;
            if(f(a,mid1) > f(a,mid2)){
                l=mid1;
            }else{
                r=mid2;
            }
        }
        int ans=1e18;
        for(int i=l ; i<=r ; i++){
            ans = min(ans,f(a,i));
        }
        cout<< ans <<"\n";
    }
}