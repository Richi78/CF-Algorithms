#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout<<#x<<": "<<x<<"\n";
#define debug2(x,y) cout<<#x<<": " << x <<" , "<<#y<<": "<<y<<"\n";

const double PI = acos(-1);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<< setprecision(10) << fixed;

    int n; cin >> n;
    while(n--){
        double r,R,h; cin >> r >> R >> h;
    
        const double pi_3 = (double)PI/3; 
        double c=(R*R + r*r + R*r);
        const double V = (double)pi_3 * h * c;
    
        const double ep=0.000000001;
        double new_V=(double)V;
        double new_R=(double)R;
        double new_h=(double)h;
        double l=0.0 , rr=(double)h;
        for(int i=0 ; i<100 ; i++){
            double mid = l+(double)(rr-l)/2;
    
            new_R = R - (double)(mid*(R-r))/(h);
            new_h = h-mid;
            c=(new_R*new_R + r*r + new_R*r);
            
            new_V=(double)pi_3 * new_h * c;
    
            if(new_V > V/2.0) l=mid;
            else rr=mid;
        }
        cout<< h-l <<"\n";
    }
}