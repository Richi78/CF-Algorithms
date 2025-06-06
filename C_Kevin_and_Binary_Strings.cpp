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
    string s; cin >> s;
    int x=s.find('0');
    if(x == -1){
        cout<<1<<" "<<1<<" "<<1<<" "<<s.size()<<endl;
    }else{
        int next1=x , cnt=1;
        while(next1+1 < s.size() && s[next1+1]=='0'){
            next1++; cnt++;
        } 
        int tmp=x-cnt , tmp2=s.size()-x;
        if(x-cnt >0){
            cout<<tmp+1<<" "<<tmp+tmp2<< " " <<1<<" "<<s.size()<<endl;
        }else{
            cout<<1<<" "<<tmp2<<" "<<1<<" "<<s.size()<<endl;
        }
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

