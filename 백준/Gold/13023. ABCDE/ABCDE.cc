#include <iostream>
#include <vector>

//13023

using namespace std;

int N, M;

vector<vector<int>> a;
vector<bool> isVisited;
bool found = false;

void dfs(int node, int depth) {
    if (depth == 4) {
        found = true;
        return;
    }

    isVisited[node] = true;
    for (int i : a[node]) {
        if (isVisited[i] == false)
            dfs(i, depth + 1);
    }
    isVisited[node] = false;
}

int main() {
    cin >> N >> M;

    a.resize(N);
    isVisited.resize(N, false);

    for(int i = 0; i < M; i++) {
        int tempX, tempY;
        cin >> tempX >> tempY;

        a[tempX].push_back(tempY);
        a[tempY].push_back(tempX);
    }

    for (int i = 0; i < N; i++) {
        dfs(i, 0);
        if (found) break;
        fill(isVisited.begin(), isVisited.end(), false);
    }

    cout << (found ? 1 : 0);

    return 0;
}