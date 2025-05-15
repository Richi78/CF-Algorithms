#include <iostream>
#include <unordered_map>

using namespace std;

void solve() {
    string input;
    cin >> input;
    int str_size = input.size();
    int temp = 0;
    for (int i = 0; i < str_size; i++) {
        if(input[i] == '1') 
            temp += 1;
    }
    cout << temp << endl;
}

int main() {
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        solve();
    }
}