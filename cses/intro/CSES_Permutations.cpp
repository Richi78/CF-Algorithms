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
    int n; cin >> n;
    
    stack<int> st;
    for(int i=n&1?n:n-1 ; i>=1 ; i-=2) st.push(i);
    int x=-1;
    for(int i=n&1?n-1:n ; i>=1 ; i-=2){
        if(abs(st.top()-i) == 1){
            cout<<"NO SOLUTION\n"; return;
        }else 
            st.push(i);
    }
    while(!st.empty()){
        cout<< st.top() <<" ";
        st.pop();
    }
    cout<<"\n";
    
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}