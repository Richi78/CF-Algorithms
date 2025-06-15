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

__int128 read(){
    string s; cin >> s;
    __int128 x=0;
    for(auto &c : s){
        x = x * 10 + (c-'0');
    }
    return x;
}

void print(__int128 x){
    if(x==0){cout<<0<<endl; return;}
    string s;
    while(x>0){
        s += '0' + (x%10);
        x/=10;
    }
    reverse(all(s));
    cout<<s<<endl;
}

void solve(){
    int n; cin >> n;
    vector<__int128> a;
    for(int i=0 ; i<n ; i++){
        __int128 x = read();
        a.push_back(x);
    }
    stack<__int128> st;
    __int128 mx=-1;
    
    for(int i=0 ; i<n ; i++){
        __int128 tmp=a[i];
        while(!st.empty()){
            if(tmp == st.top()){
                tmp+=st.top();
                st.pop();
            }else if(tmp > st.top()){
                st.pop();
            }else if(tmp < st.top()){
                break;
            }
        }
        mx=max(mx,tmp);
        st.push(tmp);
    }
    print(mx);
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}