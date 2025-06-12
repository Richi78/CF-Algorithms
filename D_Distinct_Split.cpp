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
    string s; cin >> s;
    vector<int> suff(n) , preff(n);
    preff[0]=1; suff[n-1]=1;

    set<int> st={s[0]-'a'};
    for(int i=1 ; i<n ; i++){
        if(count(all(st), s[i]-'a') == 0){
            preff[i]=preff[i-1]+1;
            st.insert(s[i]-'a');
        }
        else preff[i]=preff[i-1];
    }
    st.clear();
    st.insert(s[n-1]-'a'); 
    for(int i=n-2 ; i>=0 ; i--){
        if(count(all(st), s[i]-'a') == 0){
            suff[i]=suff[i+1]+1;
            st.insert(s[i]-'a');
        }
        else suff[i]=suff[i+1];
    }
    // vdebug(preff)
    // vdebug(suff)
    int ans=0;
    for(int i=0 ; i+1<n ; i++){
        ans=max(ans,preff[i]+suff[i+1]);
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}



