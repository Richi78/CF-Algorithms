#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define sz(a) (a).size()
#define input(x) cin >> x
#define printv(v) for(int i=0;i<sz(v);i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n;cin>>n;
    int sum=1,cnt=1;
    while(sum<n){
        sum+=sum+2;
        cnt++;
    }
    cout<<cnt<<endl;
}
signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}


// void solve(){
//     double n;cin>>n;
//     // vi a(n,0);
//     // a[0]=1;
//     int ans=2,l=1,r=n,sum=2;
//     if(n==1)ans=1;
//     else if(n>1 && n<6)ans=2;
//     else{
//         int x=ceil(log2(n/10));
//         ans=x+3;
//     }
//     cout<<ans<<endl;
// } 

// void solve(){
//     int n;cin>>n;
//     int ans=2,l=1,r=n,sum=2;
//     if(n==1)ans=1;
//     else if(n>1 && n<6)ans=2;
//     else{
//         while(l<=r){
//             int tmp=(r-l+1)/2;
//             if(sum==tmp){
//                 sum=r;
//                 if(sum!=n){
//                     ans++,l=1,r=n;
//                 } else break;
//             }else if(sum>tmp)r+=(n-r)/2;
//             else if(sum<tmp)r=(r+l)/2; 
//         }
//     }
//     cout<<ans<<endl;
// } 
