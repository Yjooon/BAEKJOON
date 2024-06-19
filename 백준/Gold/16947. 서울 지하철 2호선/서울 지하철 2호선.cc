#include <iostream>
#include <vector>
#include <queue>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

using namespace std;

// 16947

vector<bool> visited;
vector<int> result;
vector<vector<int>> graph;
vector<int> parent;

int startCycle = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node)) {
                if (result[node] == -1) {
                    result[node] = 0;
                    if (node == startCycle) 
                        return false;
                    return true;
                }
            }
        } else if (neighbor != par && result[node] == -1) {
            result[node] = 0;
            startCycle = neighbor;
            return true;
        }
    }

    return false;
}

int main() {
    FAST;

    int N;
    cin >> N;

    graph.resize(N + 1);
    visited.resize(N + 1, false);
    result.resize(N + 1, -1);
     parent.resize(N + 1, -1);

    vector<int> cycleNodes;

    for(int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1);

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (result[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (result[neighbor] == -1) { // 방문하지 않은 경우
                result[neighbor] = result[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
