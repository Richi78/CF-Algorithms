#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<string>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != "*") {
        return;
    }
    
    grid[i][j] = ".";
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    int islands = 0;
    int plus_shape_number = 0;
    vector<vector<string>> picture(h, vector<string>(w)); 

    if (h < 3 || w < 3) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < h; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < w; j++) {
            picture[i][j] = row.substr(j, 1);
        }
    }

    vector<vector<string>> picture_copy(h, vector<string>(w));
    picture_copy = picture;

    // Here I plan to use DFS to identify if there are multiple "islands". After watching the lecture on 9/1, I realized now that this is overkill. Regardless, I think it should still work.
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (picture_copy[i][j] == "*") {
                islands++;
                if (islands > 1) {
                    cout << "NO\n";
                    return 0;
                }
                dfs(picture_copy, i, j);
            }
        }
    }


    for (int i = 1; i < h-1; i++) {
        for (int j = 1; j < w-1; j++) {
            string node = picture[i][j];
            if (node == "*") {
                if (picture[i+1][j] == "*" && 
                    picture[i-1][j] == "*" && 
                    picture[i][j+1] == "*" && 
                    picture[i][j-1] == "*" &&
                    picture[i+1][j+1] == "." &&
                    picture[i-1][j+1] == "." &&
                    picture[i+1][j-1] == "." &&
                    picture[i-1][j-1] == ".") {
                        plus_shape_number++;
                } 
            }
        }
    }

    if (plus_shape_number == 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }


    return 0;
}