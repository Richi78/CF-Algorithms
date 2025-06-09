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

int f(int exp, string &s){
    int x=exp;
    for(int i=0 ; i<s.size() ; i++){
        char c=s[i];
        if(c == 'O'){
            if( (x-1)%3 == 0 ) x=(x-1)/3;
            else return -1;
        } else{ // 'E'
            x*=2;
        }
    }
    return x;
}

int valid(int num, string &s){
    int x=num;
    for(int i=s.size()-1 ; i>=0 ; i--){
        if(s[i]=='O'){
            x=x*3+1;
        } else if(s[i]=='E' && x%2==0){
            if(__builtin_popcountll(x) == 1) return -1;
            else x>>=1;
        } else return -1;
    }
    return x;
}

void solve(){
    string s; cin >> s;
    int n=s.size();
    if(n==1){
        if(s[0]=='O')cout<<1<<endl;
        else cout<<"INVALID"<<endl;
        return;
    }
    for(int i=1 ; i<n ; i++)
        if(s[i] == s[i-1] && s[i]=='O'){
            cout<<"INVALID"<<endl; return;
        }

    reverse(all(s));
    int x=1e17;
    for(int i=1 ; i<50 ; i++){
        int exp = 1LL<<i;
        int tmp = f(exp,s);
        if(tmp == -1) continue;
        if(valid(tmp,s) == exp){
            x=min(x,tmp);
        }
    }

    int limit = 1LL<<47;
    if(x <= limit) cout<< x <<endl;
    else cout<<"INVALID"<<endl;
    
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}