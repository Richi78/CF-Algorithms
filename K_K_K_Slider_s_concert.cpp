#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    vector<int> left(n) , right(n);
    for(auto &x : left) cin >> x;
    for(auto &x : right) cin >> x;

    sort(left.begin() , left.end());
    sort(right.begin() , right.end());

    int ans=0;
    for(int i=0 ; i<n ; i++){
        if(left[i]+right[i] <= k){
            ans++; k-=(left[i]+right[i]);
        }
    }
    cout<< ans <<"\n";
}