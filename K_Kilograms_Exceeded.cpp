#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    map<int,int> mp={
        {2,1},{4,2},{6,3},{8,4},{1,5},{3,6},{5,7},{7,8}
    };
    vector<int> ans(n);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        ans[i] = mp[x];
    }
    for(auto &x : ans) cout << x << " "; cout<<"\n";
}