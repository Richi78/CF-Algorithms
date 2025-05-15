#include <iostream>
using namespace std;

int main()
{
    string x;
    cin >> x;
    int cnt = 0;
    int str_size = x.size();
    for (int i = 0; i < str_size; i++)
    {
        if (x[i] == 'A')
        {
            for (int j = i + 1; j < str_size; j++)
            {
                if (x[j] == 'B')
                {
                    int dist = j - i;
                    if (x[j + dist] == 'C'){
                        cnt += 1;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}