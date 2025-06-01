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

void solve(){
    int n,x; cin >> n >> x;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin>> a[i];
    sort(all(a));

    int ans=a[0];
    for(int i=1 ; i<n && x>0; i++){
        if(a[i-1] != a[i]){
            int tmp2=a[i]-a[i-1];
            if(tmp2*i <= x){
                ans+=tmp2;
                x-=tmp2*i;
            }else{
                if(x/i > 0){
                    ans+=(x/i)*i;
                    cout<<ans<<endl;
                    return;
                }
            }
            // while(tmp2){
            //     if(x-i>=0){
            //         x-=i;
            //         ans++;
            //     }else{
            //         cout<<ans<<endl;
            //         return;
            //     }
            //     tmp2--;
            // }
        }
    }
    int tmp=ans+(x/n)*n;
    cout<<tmp<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}