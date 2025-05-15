#include <iostream>
 
using namespace std;
 
void solve() {
    int x,y;
    cin >> x >> y;
    if (x+1 == y){
        cout << "Yes" << endl;
        return;
    }
    if (x > y) {
        if ( (x+1-y)%9 == 0){
            cout << "Yes" << endl;
            return;
        }
        if (x-y == 8){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
 
}
 
int main(){
    int cases;
    cin >> cases;
    for (int i = 0; i<cases; i++){
        solve();
    }
}