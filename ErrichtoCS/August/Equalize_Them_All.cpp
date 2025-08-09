#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int N=2e5+10;
int freq[N]={};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int mx=0 , idx=-1;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a[i]=x;
        freq[x]++;
        if(uax(mx,freq[x])) idx=i;
    } 

    vector<array<int,3>> ans;
    for(int i=idx-1 ; i>=0 ; i--){
        if(a[i] > a[i+1]){
            ans.push_back({2,i,i+1});
        }else if(a[i] < a[i+1]){
            ans.push_back({1,i,i+1});
        }
        a[i]=a[i+1];
    }
    for(int i=idx+1 ; i<n ; i++){
        if(a[i] > a[i-1]){
            ans.push_back({2,i,i-1});
        }else if(a[i] < a[i-1]){
            ans.push_back({1,i,i-1});
        }
        a[i]=a[i-1];
    }

    int k=ans.size();
    cout<< k <<"\n";
    for(int i=0 ; i<k ; i++){
        cout<< ans[i][0] <<" "<< ans[i][1]+1 <<" "<< ans[i][2]+1 <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}