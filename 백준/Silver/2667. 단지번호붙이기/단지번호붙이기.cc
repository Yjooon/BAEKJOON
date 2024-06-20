#include <iostream>
#include <vector>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

using namespace std;

// 2667

int N;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int temp = 0;
vector<int> result;

int dfs(int i, int j) {
    if (i < 1 || i > N || j < 1 || j > N || graph[i][j] == 0 || visited[i][j])
        return 2;
    visited[i][j] = true;

    temp += 1;
    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i, j-1);
    return 0;
}

int main() {
    FAST;

    cin >> N;

    graph.resize(N + 1, vector<int>(N + 1));
    visited.resize(N + 1, vector<bool>(N + 1, false));

    for(int i = 1; i <= N; i++) {
        graph[i].resize(N);
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            char c;
            cin >> c;
            graph[i][j] = c - '0';
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            temp = 0;
            if (dfs(i, j) != 2) {
                result.push_back(temp);
            }
        }
    }
    
    cout << result.size() << "\n";

    sort(result.begin(), result.end());
    for(int a : result) {
        cout << a << "\n";
    }
    
    return 0;
}
