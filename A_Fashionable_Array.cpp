#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    sort(all(a));
    if(n == 1){
        cout<<0<<endl;
    }else{
        auto it1=a.begin() , it2=prev(a.end());
        if( (*it1 & 1) && (*it2 &1) ){
            cout<<0<<endl;
        }else if((*it1%2 == 0) && (*it2%2 == 0)){
            cout<<0<<endl;
        } else if( *it1 & 1 ){
            int cnt1=0; // siguiente par I a D
            int cnt2=0; // siguiente impar D a I
            while(*it1&1){
                cnt1++;
                ++it1;
            }
            while(*it2 % 2 == 0){
                cnt2++;
                it2--;
            }
            cout<<min(cnt1,cnt2)<<endl;
        }else if(*it2&1){
            int cnt1=0;
            int cnt2=0;
            while(*it2&1){
                cnt1++;
                --it2;
            }
            while(*it1%2 == 0){
                cnt2++;
                ++it1;
            }
            cout<<min(cnt1,cnt2)<<endl;
        }
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

