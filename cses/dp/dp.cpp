#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int MOD=1e9+7;

void add_self(int &a, int b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

vector<int> st;
int BASE=1;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n); 
    for(auto &x : a) cin >> x;

    vector<int> copy_a(a.begin(),a.end());
    sort(copy_a.begin() , copy_a.end());
    copy_a.erase( unique(copy_a.begin(), copy_a.end()), copy_a.end());

    for(auto &x : a){
        x = lower_bound(copy_a.begin() , copy_a.end(), x) - copy_a.begin();
    }

    while(BASE < n) BASE<<=1;
    st.resize(2*BASE);

    int ans=0;
    for(auto &x : a){
        int sum=1;
        for(int i=x+BASE ; i>=1 ; i>>=1){
            if(i&1) add_self(sum, st[i-1]);
        } 
        for(int i=x+BASE ; i>=1 ; i>>=1){
            add_self(st[i],sum);
        }
        add_self(ans,sum);
    }
    cout<< ans <<"\n"; 
}