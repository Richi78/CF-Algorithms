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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

struct Node{
    int mx,team,idx,disp,lazy;
    Node(int x=0){
        mx=team=idx=disp=x;
        lazy=LLONG_MAX;
    }
};

vector<Node> st;

Node merge(Node &left, Node &right){
    Node ans;
    if(left.mx > right.mx) ans=left;
    else ans=right;
    ans.disp=left.disp+right.disp;
    return ans;
}

void push(int node, int l, int r){
    if(st[node].lazy == LLONG_MAX) return;
    if(st[node].team != 0) return;
    int team;
    if(st[node].lazy == 1) team=1;
    else team=2;
    st[node].mx=0;
    st[node].team=team;
    if(l != r){
        if(st[node*2].team == 0){
            // st[node*2].mx=0;
            st[node*2].lazy=st[node].lazy;
            // st[node*2].team=team;
        }
        if(st[node*2+1].team == 0){
            // st[node*2+1].mx=0;
            st[node*2+1].lazy=st[node].lazy;
            // st[node*2+1].team=team;
        }
    }
    st[node].lazy=LLONG_MAX;
}

void update(int node, int l, int r, int query_l, int query_r, bool team, int &k){
    push(node, l, r);
    if(query_l<=l && r<=query_r){
        st[node].lazy=team;
        push(node, l ,r);
        return;
    }
    if(r<query_l || query_r<l) return;
    int mid=l+(r-l)/2;
    if(st[node*2].disp > 0)
        update(node*2, l, mid, query_l, query_r, team, k);
    if(st[node*2+1].disp > 0)
        update(node*2+1, mid+1, r, query_l, query_r, team, k);

    st[node]=merge(st[node*2],st[node*2+1]);
}

void update(int pos, int n, int k){
    
}

void solve(){
    int n,k; cin >> n >> k;
    int tmp_n=n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    while(__builtin_popcount(n) != 1){
        a.push_back(0); n++;
    }

    st.resize(2*n);
    for(int i=0 ; i<n ; i++){
        st[n+i].mx=a[i];
        st[n+i].idx=i;
        st[n+i].disp=1;
        st[n+i].team=0;
    }
    for(int i=n-1 ; i>=1 ; i--){
        st[i]=merge(st[2*i],st[2*i+1]);
    }

    bool team=true; // true -> team1    false -> team2
    while(st[1].mx != 0){
        int idx=st[1].idx;
        debug1(idx)
        if( (idx+k)<tmp_n ) // right update
            update(1,0,n-1,idx,idx,team,k);
        else
            update(1,0,n-1,idx,idx,team,tmp_n-idx-1);

        if( (idx-k)>=0 ) // left update
            update(1,0,n-1,idx-k,idx-k,team,k);
        else    
            update(1,0,n-1,0,0,team,idx,k);
        team^=1;
    }
    for(int i=0 ; i<tmp_n ; i++){
        cout<< st[n+i].team;
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

