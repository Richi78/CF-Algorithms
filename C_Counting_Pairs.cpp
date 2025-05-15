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
    int n,x,y,sum=0;cin>>n>>x>>y;
    vi a(n);
    forn(i,n){cin>>a[i];sum+=a[i];}
    sort(all(a));
    int ans=0;
    for(int i=0;i<n;i++){
        sum-=a[i];
        int l=i+1 , r=n-1 , lowestIdx=0 , highestIdx=0;
        while(l<=r){ // para encontrar el minimo
            int mid=(l+r)/2;
            if(sum-a[mid]>=x && sum-a[mid]<=y){
                lowestIdx=mid;
                r=mid-1;
            } else if(sum-a[mid]<x)r=mid-1;
            else if(sum-a[mid]>y)l=mid+1;
        }
        l=i+1 , r=n-1;
        while(l<=r){ // para encontrar el maximo
            int mid=(l+r)/2;
            if(sum-a[mid]>=x && sum-a[mid]<=y){
                highestIdx=mid;
                l=mid+1;
            } else if(sum-a[mid]<x)r=mid-1;
            else if(sum-a[mid]>y)l=mid+1;
        }
        if(lowestIdx!=0)ans+=(highestIdx-lowestIdx+1);
        sum+=a[i];
    }
    cout<<ans<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}

// void solve(){
//     int n,x,y;cin>>n>>x>>y;
//     vi a(n);
//     int sum=0,ans=0;
//     forn(i,n)cin>>a[i],sum+=a[i];
//     sort(all(a));
//     int low = sum - y;
//     int high = sum - x;
 
//     for (int j = 0; j < n; j++)
//     {
//         int target_min = low - a[j];
//         int target_max = high - a[j];
 
//         int l = lower_bound(a.begin() + j + 1, a.end(), target_min) - a.begin();
//         int r = upper_bound(a.begin() + j + 1, a.end(), target_max) - a.begin();
 
//         ans += r - l;
//     }
 
//     cout << ans << "\n";
// }