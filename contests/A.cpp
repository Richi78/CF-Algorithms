#include <bits/stdc++.h>

using namespace std;


const long long INF=1e18;
int n;
vector<vector<int>> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n,vector<int>(n));
    for(int i=0 ; i<n ; i++) for(int j=0 ; j<n ; j++) cin >> a[i][j];

    vector<vector<long long>> adj(n,vector<long long>(n,INF));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i%2==0 && j&1){
                adj[i][j]=a[i][j];
            }
            if(i&1 && j%2==0){
                adj[i][j]=a[i][j];
            }
        }
    }

    for(int i=0 ; i<n ; i++) adj[i][i]=0;
    
    for(auto row : adj){
        for(auto col : row) cout<< (col==INF ? -1 : col) <<" ";
        cout<<"\n";
    }
    for(int via=0 ; via<n ; via++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                adj[i][j] = min(adj[i][j], adj[i][via]+adj[via][j]);
            }
        }
    }

    cout<<"-----------\n";
    for(auto row : adj){
        for(auto col : row) cout<< col <<" ";
        cout<<"\n";
    }
    long long ans=INF;
    int nd = (n&1 ? n-1 : n);
    nd--;
    cout<<"ND: "<<nd<<"\n";
    // for(int via=0 ; via<n ; via++){
        for(int i=0 ; i<n ; i+=2){
            cout<< "I: "<<i <<" , ADJ: "<<adj[i][nd] <<"\n";
            ans=min(ans, adj[i][nd]);
        }
    // }
    cout<< ans <<"\n";
}