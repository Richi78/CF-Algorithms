#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1) , b(m);
    for(int i=1 ; i<=n ; i++) cin >> a[i];
    for(int i=0 ; i<m ; i++) cin >> b[i];
    a[0]=-1e10;
    sort(all(b));

    for(int i=1 ; i<=n ; i++){
        int bmn=1e10;
        int l=0 , r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            int x=b[mid]-a[i]; 
            if( x >= a[i-1]){
                bmn=min(bmn, x);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        int x=a[i];
        if(bmn < x){
            if(bmn >= a[i-1] && bmn != 1e10){
                a[i]=bmn;
            }else if(x >= a[i-1]){
                a[i]=x;
            }else{
                cout<<"NO"<<endl;
                return;
            }
        }else{
            if(x >= a[i-1]){
                a[i]=x;
            }else if(bmn >= a[i-1] && bmn != 1e10){
                a[i]=bmn;
            }else {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}