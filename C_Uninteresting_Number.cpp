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
    string s; cin >> s;
    int tw=0 , th=0 , sum=0;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i] == '2') tw++;
        else if(s[i] == '3') th++;
        sum+=s[i]-'0';
    }

    if(sum%9 == 0){
        cout<<"YES"<<endl; return;
    }
    
    int r=sum%9;
    r=9-r;
    if(r&1) r+=9;
    while(th){
        if( r-6 > 0 ) {
            r-=6;
            th--;
        } else if(r-6 == 0){
            cout<<"YES"<<endl; return;
        }else {
            break;
        }
    }
    while(tw){
        if(r-2 > 0){
            r-=2;
            tw--;
        }else if(r-2 == 0){
            cout<<"YES"<<endl; return;
        }else{
            break;
        }
    }
    cout<<"NO"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}