#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout<<#x<<": "<<x<<"\n";
#define debug2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<"\n";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long long sumA=0 , sumB=0 , maxK=0;

    for(int i=0 ; i<n ; i++){
        int a,b; cin >> a >> b;
        sumA+=a; sumB+=b;
        maxK=max(maxK , 1LL*a+b);
    }
    cout<< max( abs(sumA-sumB), max(0LL,2*maxK -(sumA+sumB)) ) <<"\n";

    return 0;
}