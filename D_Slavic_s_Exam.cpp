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
    string t,s; cin >> t >> s;

    int i=0 , j=0 , lent=t.size() , lens=s.size();
    while(i < lent){
        char ct=t[i] , cs=s[j];
        if(ct == '?'){
            if(j< lens){
                t[i]=cs;
                j++;
            }else t[i]='a';
            i++;
        }else{
            if(ct == cs) j++;
            i++;
        }
    }
    if(j>=lens) cout<<"YES\n"<<t<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}



