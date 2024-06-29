#include <iostream>
#include <vector>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

using namespace std;

// 4963

int w, h;
int result = 0;
vector<int> output;
vector<vector<int>> input;
vector<vector<bool>> visited;

bool dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= h || j >= w)
        return false;
    if (visited[i][j] == true || input[i][j] == 0)
        return false;
    visited[i][j] = true;

    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i + 1, j + 1);
    dfs(i + 1, j - 1);
    dfs(i - 1, j - 1);
    dfs(i - 1, j + 1);
    return true;
}

int main() {
    FAST;

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            for(int i : output) {
                cout << i << "\n";
            }
            return 0;
        }

        result = 0;

        input.resize(h);
        visited.resize(h);
        for (int i = 0; i < h; i++) {
            input[i].resize(w, 0);
            visited[i].resize(w, false);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> input[i][j];
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (dfs(i, j))
                    result++;
            }
        }
        output.push_back(result);
    }
    
    return 0;
}
