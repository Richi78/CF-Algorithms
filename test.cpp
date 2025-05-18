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

void f(int n, int idx, int to, vector<int> ls, vector<int> &ranges, vector<int> &ans){
    
    // valid constraint
    if(to >= n){
        ans.push_back(ls.size());
    }
    // idx iqual to end
    if(idx == ranges.size()){
        return;
    }
    //take
    int tmp1=idx-ranges[idx] , tmp2=idx+ranges[idx];
    int tmp3;
    if(tmp1 <= to && tmp2 >= to) tmp3=tmp2;
    else tmp3=to;
    ls.push_back(ranges[idx]);
    f(n , idx+1, tmp3, ls,ranges,ans);

    //notake
    ls.pop_back();
    f(n , idx+1 , to, ls , ranges  , ans);

    return;
}

int minTaps(int n, vector<int> &ranges) {
    vector<int> ans;
    vector< pair<int,int> > a(n+1);
    f(n , 0, 0, vector<int>(), ranges, ans);
    return *min_element(all(ans));
}


signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    int n=5;
    vector<int> a={3,4,1,1,0,0};
    int ans=minTaps(n,a);
    cout<<ans<<endl;
}



