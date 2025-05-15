#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int cantDigits(int n){
    if (n == 0) return 1;

    int count = 0;

    while (n > 0) {
        count++;
        n /= 10;
    }
    return --count;
}

void solve(vector<int> &a){
    int n; cin >> n;
    cout<<"a"<<endl;
    // auto it=lower_bound(all(a),n);
    // int tmp=*it - *prev(it);
    // int tmp2=*it - n;
    
    // int ans = tmp - tmp2;
    // cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;

    vector<int> a;
    for(int i=1 ; i<=1e9 ; i++){
        // if(i>1){
        //     a.push_back(i+a[i-2]+cantDigits(i));
        // }else{
        //     a.push_back(i);
        // }
        a.push_back(i);
    }    

    while(tc--)solve(a);
}