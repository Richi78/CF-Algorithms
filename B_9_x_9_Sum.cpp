#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int size = 10;
    int cnt = 0;
    int tmp;
    for (int i = 1; i<size; i++){
        for (int j = 1; j<size; j++){
            tmp = i*j;
            if (tmp != x){
                cnt += tmp;
            }
        }
    } 

    cout << cnt << endl;
}