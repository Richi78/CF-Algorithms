#include <bits/stdc++.h>

using namespace std;

#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define debug1(x) cout << #x << " = " << x << "\n";
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define int long long

struct Block{
    vector<bool> cur , want;
    void add(){
        cur.push_back(false);
        want.push_back(false);
    }
    void mark_cur(int x){
        cur[x-1]=true;
    }
    void mark_want(int x){
        want[x-1]=true;
    }
    int calc(){
        int ans=1e18;
        {
            // forced
            int cnt=0;
            for(int i=0 ; i<cur.size() ; i++){
                if(cur[i] && want[i]) continue;
                else if(cur[i] && !want[i]) cnt++;
                else if(!cur[i] && want[i]) cnt++;
                else if(!cur[i] && !want[i]) continue;
            }
            ans=min(ans,cnt);
        }
        {
            // select all button
            int cnt=1 + count(all(want), 0LL);
            ans=min(ans,cnt);
        }
        {
            // deselect all button
            int cnt=1 + count(all(want), 1LL);
            ans=min(ans,cnt);
        }
        return ans;
    }
};

void solve(){
    int n,perpage,s,pre,q; cin >> n >> perpage >> s >> pre >> q;
    int pages=(n+perpage-1)/perpage;
    vector<Block> a(pages);
    for(int i=0 ; i<n ; i++) a[i/perpage].add();
    
    for(int i=0 ; i<pre ; i++){
        int x; cin >> x;
        int factor=(x-1)/perpage;
        a[(x-1)/perpage].mark_cur(x-factor*perpage);
    }
    for(int i=0 ; i<q ; i++){
        int x; cin >> x;
        int factor=(x-1)/perpage;
        a[(x-1)/perpage].mark_want(x-factor*perpage);
    }
    // for(auto x : a){
        // vdebug(x.cur)
        // vdebug(x.want)
    // }

    int ans=0;
    vector<int> val;
    for(int i=0 ; i<a.size() ; i++){
        int x=a[i].calc();
        val.push_back(x);
        ans+=x;
    }

    int from=0;
    while(from<val.size() && val[from]==0) from++;
    int to=a.size()-1;
    while(to>0 && val[to]==0) to--;

    if(from == val.size()){
        cout<<"0\n"; return;
    }
    // vdebug(val)
    // debug2(from,to)
    // debug1(ans)
    int cur=s-1;
    if(cur < from){
        ans+=to-cur;
    }else if(cur > to){
        ans+=cur-from;
    }else{
        int tmp=to-from;
        ans=min(ans+tmp+cur-from, ans+tmp+to-cur);
    }

    cout<< ans <<"\n";
}

signed main(){
    solve();
}