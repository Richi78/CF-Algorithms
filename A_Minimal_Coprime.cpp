#include <iostream>
using namespace std;

void solve();

int main(){
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        solve();
    }
}

void solve(){
    int a,b;
    cin >> a >> b;

    // si son distintos la resta
    if (a != b){
        cout << b-a << endl;
    } else {
        //si son iguales 1 solo si es 1 1, caso contrario 0
        if ( a == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}