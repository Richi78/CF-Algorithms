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
#define INF 1e6
#define TOL 1e-7

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int res[205][205], f,mf,s,t,m,orig[205][205];
vector<vector<int>> adj;
vector<int> p;
vector<pair<double,double>> point;

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a;
        a = (a*a); 
        b >>= 1;
    }
    return ans;
}

void augment(int v, int minEdge){
    if(v==s){
        f = minEdge;
        return;
    }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void maxflow(){
    mf = 0;
    while(true){
        f = 0;
        vector<int> dist(205, INF); dist[s] = 0; 
        queue<int> q; 
        q.push(s);
        p.assign(205, -1);
        while(!q.empty()){
            int u = q.front(); 
            q.pop();
            if(u == t) break;
            for(int i = 0; i < adj[u].size(); i++){
                int v = adj[u][i];
                if(res[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(v), p[v] = u;
            }
        }
        augment(t, INF);
        if(f==0) break;
        mf += f;
    }
}

double dist(pair<double,double> a, pair<double,double> b){
    double x1 = a.F, x2 = b.F, y1 = a.S, y2 = b.S;
    return sqrt( pow(x2-x1,2) + pow(y2-y1,2) );
}

void connectEdge(int a, int b){
    adj[a].push_back(b);
}

void solve(){
    int n; double d; cin >> n >> d;
    int tp=0;
    int offset = n;
    s = offset*2;
    memset(res, 0, sizeof res);
    point.clear();
    adj.assign(205, vector<int>());
    for(int i = 0; i < n; i++){
        int x,y,n_pen,jmp; cin >> x >> y >> n_pen >> jmp;
        point.emplace_back(x,y);
        tp += n_pen;
        
        if(n_pen){
            connectEdge(s, i+offset);
            connectEdge(i, s);
            res[s][i+offset] = n_pen;
        }
        connectEdge(i+offset, i);
        connectEdge(i, i+offset);
        res[i+offset][i] = jmp;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(i==j) continue;
            if( dist(point[i], point[j]) - d <= TOL ){
                res[i][j+offset] = INF;
                res[j][i+offset] = INF;
                connectEdge(i, j+offset);
                connectEdge(j+offset, i);
                connectEdge(j, i+offset);
                connectEdge(i+offset, j);
            }
        }
    }
    vector<int> res_p;
    
    for(int a = 0; a < 205; a++){
        for(int b = 0; b < 205; b++){
            orig[a][b] = res[a][b];
        } 
    } 
    for(int i = 0; i < n; i++){
        t = i + offset;
        maxflow();
        for(int a = 0; a < 205; a++){
            for(int b = 0; b < 205; b++){
                res[a][b] = orig[a][b];
            } 
        } 
        if(mf == tp) res_p.push_back(i);
    }
    if(res_p.size()){
        for(int i = 0; i < res_p.size(); i++){
            cout<<res_p[i];
            if(i != res_p.size() - 1) cout<<" ";
        }
        cout << endl;
    }
    else
        cout << "-1" << endl;
}

signed main(){
    int tc; cin >> tc;
    while(tc--)solve();
}
