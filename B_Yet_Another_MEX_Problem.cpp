#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    map<int,vector<int>> pos;
    for(int i=0 ; i<n ; i++) cin >> a[i], pos[a[i]].push_back(i);  

    vector<int> freq(n+1);
    set<int> st;
    for(int i=0 ; i<=n+4 ; i++){
        st.insert(i);
    }
    multiset<int> cur;
    for(int i=0 ; i<k ; i++){
        freq[a[i]]++;
        cur.insert(a[i]);
        if(freq[a[i]] == 1) st.erase(a[i]);
    }
    int mex=*st.begin() , idx=0;
    for(int i=k ; i<n ; i++){
        freq[a[i]]++;
        cur.insert(a[i]);
        freq[a[i-k]]--; 
        cur.erase(cur.find(a[i-k]));
        if(freq[a[i]] == 1) st.erase(a[i]);
        if(freq[a[i-k]] == 0) st.insert(a[i-k]);
        int tmp=*st.begin();
        if(tmp > mex){
            mex=tmp;
            idx=i-k+1;
        }
    }

    if(n == k){
        cout<< *prev(cur.end())+1 <<"\n"; return;
    }

    set<int> new_cur;
    for(int i=idx ; i<idx+k ; i++){
        if(a[i]<k){
            new_cur.insert(a[i]);
        }
    }
    int ini=idx , fin=idx+k-1;
        int tmp=k-new_cur.size();
        while(tmp>0){
            int tmp2=1e10;
            if(pos[mex].size() > 0){
                int a1=-1e12 , a2=1e12;
                for(auto x : pos[mex]){
                    if(x < ini){
                        a1=x;
                    }
                    if(x>fin){
                        a2=x;
                        break;
                    }
                } 
                if(a1!=-1 || a2!=-1){
                    if(ini-a1 < a2-fin) tmp2=a1;
                    else tmp2=a2;
                }
            }
            if(tmp2 != 1e10){
                mex++;
                tmp--;
                if(tmp2<ini) ini=tmp2;
                if(tmp2>fin) fin=tmp2;
            }else{
                break;
            }
        }
        cout<< mex-1 <<"\n";
    // }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}