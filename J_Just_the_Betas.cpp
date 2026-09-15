#include <bits/stdc++.h>

using namespace std;

const int N=1e6+100;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    vector<int> xd(N);
    for(auto &x : a) cin >> x , xd[x]++;

    int ans=0 , mx=0;
    for(int i=2 ; i<N ; i++){
        int cur=0;
        for(int j=i ; j<N ; j+=i){
            if(xd[j]){
                cur+=xd[j];
            }
        }
        if(cur > mx){
            mx=cur; ans=i;
        }
    }
    cout<< ans <<"\n";

    return 0;
}