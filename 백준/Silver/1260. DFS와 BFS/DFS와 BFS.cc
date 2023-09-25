#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int N, M, V;
vector<int> graph[1001];
int visited[1001];

void DFS(int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 0; i < graph[v].size(); i++) {
        int next = graph[v][i];
        if (!visited[next]) {
            DFS(next);
        }
    }
}

void BFS(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true; // 방문했다고 표시
            }
        }
    }
}

int main() {
    FAST;
    cin >> N >> M >> V;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    DFS(V);
    cout << "\n";

    fill(visited, visited + N + 1, false);

    BFS(V);
    
    return 0;
}
