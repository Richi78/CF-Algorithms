#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> numbers;
    for (int i = 0, a; i < n - 2; i++)
    {
        cin >> a;
        numbers.push_back(a);
    }

    for (int i = 0; i+2 < numbers.size(); i++){
        if (numbers[i] == 1 && numbers[i+1] == 0 && numbers[i+2] == 1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solve();
    }
}