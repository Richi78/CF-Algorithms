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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int N=2e4+100;

void solve(vector<int> &a){
    int n; cin >> n;

    cout<< a[n-1] <<"\n";

}

signed main(){
    FIO;
    vector<int> ans(N,1);
    ans[0]=0;ans[1]=0;
    for(int i=2 ; i*i<=N ; i++){
        if(ans[i]){
            for(int j=i*i;j<=N;j+=i) ans[j]=0;
        }
    }
    
    vector<int> x;
    for(int i=2 ; i<=N ; i++){
        if(ans[i]){
            x.push_back(i);
            if(x.size()%5 == 0 && x.size()>0){
                int sz=x.size()-1;
                swap(x[sz],x[sz-3]);
                swap(x[sz-3],x[sz-1]);
            }
        }
    }
    int tc;cin>>tc;
    while(tc--)solve(x);
}