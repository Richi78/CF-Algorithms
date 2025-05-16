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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++)cin >> a[i];
    deque<int> b;
    set<int> in;
    for(int i=0 ; i<n ; i++){
        if(b.size() < k){
            if(in.count(a[i]) == 0){
                b.push_front(a[i]);
                in.insert(a[i]);
            }
        }else{ // es igual a k
            if(in.count(a[i]) == 0){
                int tmp=b.back();
                b.pop_back();
                in.erase(tmp);
                b.push_front(a[i]);
                in.insert(a[i]);
            }
        }
    }
    cout<<b.size()<<endl;
    while(!b.empty()){
        cout<<b.front()<<" ";
        b.pop_front();
    }
    cout<<endl;
    
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}