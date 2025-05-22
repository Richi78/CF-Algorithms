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
    int h,n; cin >> h >> n;
    vector<int> a(n);
    int sum=0;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        sum+=a[i];
    } 

    map<int,int> s;
    int sum2=0;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        s[x]+=a[i];
    }

    int cnt=1 , mxcd=(--s.end())->F;
    h-=sum;
    if(h<=0) {cout<<cnt<<endl; return;}
    while(1){
        if(h - sum > 0){
            h-=sum;
            cnt+=mxcd;
            continue;
        }
        auto it= s.begin();
        while(1){
            int cd=it->F , dmg=it->S;
            
            if(h - dmg <= 0){
                cnt+=cd;
                
                cout<< cnt << endl; return;
            }else{
                h-=dmg;
                ++it;
            }
        }
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

