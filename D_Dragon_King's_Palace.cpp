#include <bits/stdc++.h>

using namespace std;


void solve(){
    int x1,y1,r1; cin >> x1 >> y1 >> r1;
    int x2,y2,r2; cin >> x2 >> y2 >> r2;
    int k; cin >> k;

    long long dx = x1-x2;
    long long dy = y1-y2;
    long long d = dx*dx + dy*dy;
    if(d > 1LL*(r1+r2)*(r1+r2)){ // no se intersectan
        int mx = max(r1,r2);
        cout<< (mx*2>=k ? "YES" : "NO") <<"\n";
    }else if(d == 1LL*(r1+r2)*(r1+r2)){ //tangentes
        cout<< (2*r1+2*r2>=k ? "YES" : "NO") <<"\n";
    }else{
        long long mx = max(r1,r2);
        long long mn = min(r1,r2);
        if(d < 1LL*(mx-mn)*(mx-mn)){ //uno dentro de otro
            cout<< (2*max(r1,r2)>=k ? "YES" : "NO") <<"\n";
        }else if(d == 1LL*(mx-mn)*(mx-mn)){ // tangencia interna
            cout<< (2*max(r1,r2)>=k ? "YES" : "NO") <<"\n";            
        }else{ // existe interseccion en 2 pungos
            double dd = sqrt(d);
            cout<< (dd+r1+r2>=k ? "YES" : "NO") <<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}