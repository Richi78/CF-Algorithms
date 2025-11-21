#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int INF=1e18;
struct Node{
    int val,idx;
    Node(int v=0, int i=-1){
        val=v; idx=i;
    }
};
vector<int> st;

void update(int idx, int N){
    st[idx-1+N]=INF;
    for(int i=(idx-1+N)/2 ; i>=1 ; i>>=1){
        st[i]=min(st[2*i],st[2*i+1]);
    }
}

void solve(){
    int n; cin >> n;

    if(n<=4){
        for(int i=1 ; i<=n ; i++) cout<< i <<" ";
        cout<<"\n"; return;
    }

    int N=n;
    while(__builtin_popcountll(N) != 1) N++;

    st.clear();
    st.resize(2*N);
    int tmp=2;
    st[N]=INF;
    for(int i=1 ; i<N ; i++){
        st[i+N]=tmp++;
    }
    for(int i=N-1 ; i>=1 ; i--){
        st[i]=min(st[2*i],st[2*i+1]);
    }

    // vdebug(st)
    // update(2,N);
    // vdebug(st)

    vector<int> ans(n+2);

    int i=0;
    while(i<n-1){
        int num=st[1];
        ans[i]=num;
        i++;
        if(i<=n && 2*num<=n){
            ans[i]=2*num;
            update(2*num,N);
            i++;
        }
        update(num,N);
    }
    ans[n-1]=1;
    for(int i=0 ; i<n ; i++) cout<< ans[i] <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}