#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //find_by_order, order_of_key ; greater<int>, less_equal<int>

void solve(){

}

signed main(){
    // FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    pbds A;
    A.insert(1);
    A.insert(5);
    A.insert(10);
    A.insert(29);
    A.insert(29);

    for(auto x:A){
        cout<<x<<" ";
    }
    cout<<endl;

    int x=*A.find_by_order(0);
    cout<<x<<endl;

    int y = A.order_of_key(10);
    cout<<y<<endl;
}