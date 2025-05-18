#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m,a,b; cin >> n >> m >> a >> b;
    int cnt=0;
    while(1){
        // debug2(n,m)
        if(n*m==2){
            cnt+=2;
            break;
        } else if(n*m==1){
            cnt+=1;
            break;
        }
        int r=max(0+a-1,n-a);
        int c=max(0+b-1,m-b);
        // debug2(r,c)
        if(r > c){
            n-=r;
            a=(n+1)/2;
        }else{
            m-=c;
            b=(m+1)/2;
        }
        // a=(n+1)/2;
        // b=(m+1)/2;
        cnt++;
            // if(n==1 && m==1) break;
        // debug2(n,m)
        // debug2(a,b)
        // debug1(cnt)
        // cout<<"----"<<endl;
    }
    cout<<cnt<<endl;
}

signed main(){
    // FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}


