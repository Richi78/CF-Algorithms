#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

vector<int> fact(21);

vector<int> getPerm(int n, int k){
    vector<int> ans;
    set<int> st;
    for(int i=0 ; i<n ; i++){
        st.insert(i+1);
    }
    while(n){
        int tmp=fact[n-1];
        int cnt=1;
        for(auto x : st){
            if(tmp*cnt >= k){
                ans.push_back(x);
                st.erase(x);
                k-=(tmp*(cnt-1));
                break;
            }
            cnt++;
        }
        n--;
    }
    return ans;
}

int getKth(vector<int> &a){
    int n=a.size();
    int ans=1; // 1 because at the end there's only one posibility
               // if we put 0, the sum in the for will be 0*1, adding nothing

    set<int> st;
    for(int i=1 ; i<=n ; i++) st.insert(i);

    int N=n;
    for(int i=0 ; i<N ; i++){
        auto it=st.begin();
        int cnt=1;
        while(*it != a[i]){
            cnt++;
            it++;
        } 
        st.erase(it);
        ans+=(cnt-1)*fact[n-1];
        n--;
    }
    return ans;
}

void solve(){
    int type; cin >> type;
    if(type == 1){
        int n,k; cin >> n >> k;
        vector<int> a=getPerm(n,k);
        for(auto x : a) cout<< x <<" ";
        cout<<"\n";
    }else{
        int n; cin >> n;
        vector<int> a(n); 
        for(int i=0 ; i<n ; i++) cin >> a[i]; 
        cout<< getKth(a) <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    fact[0]=1;
    for(int i=1 ; i<=20 ; i++){
        fact[i]=fact[i-1]*i;
    }
    int tc;cin>>tc;
    while(tc--)solve();
}