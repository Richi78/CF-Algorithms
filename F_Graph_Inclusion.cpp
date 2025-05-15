#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> x;
    int num;
    int target;
    while (cin >> num) {
        x.push_back(num);
    }
    target = x.back();
    x.pop_back();

    for (int i = 0; i < x.size() - 1; i++){
        for (int j = i+1; j < x.size(); j++) {
            if (x[i] + x[j] == target){
                cout << i << " " << j;
                break;
            }
        }
    }
}