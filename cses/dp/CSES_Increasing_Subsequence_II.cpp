#include <bits/stdc++.h>

using namespace std;

#define vdebug(x) cout<<#x<<": ";for(auto e : x)cout<<e<<" "; cout<<"\n";

const int MOD=1e9+7;

void add_self(int &a, int b){
    a+=b;
    if(a > MOD) a-=MOD;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> compressed(a.begin(),a.end());
    sort(compressed.begin(),compressed.end());
    compressed.resize( unique(compressed.begin(),compressed.end()) - compressed.begin());
    for(auto &x : a){
        x = lower_bound(compressed.begin(),compressed.end() , x) - compressed.begin();
    }

    int BASE=1;
    while(BASE < n) BASE*=2;
    vector<int> st(BASE*2);
    int ans=0;
    for(int idx=0 ; idx<n ; idx++){
        int sum=1;
        for(int i=BASE+a[idx] ; i>=1 ; i/=2){
            if(i&1)
                add_self(sum,st[i-1]);
        }
        add_self(ans,sum);
        for(int i=BASE+a[idx] ; i>=1 ; i/=2){
            add_self(st[i],sum);
        }
    }
    cout<< ans <<"\n";
    return 0;
}