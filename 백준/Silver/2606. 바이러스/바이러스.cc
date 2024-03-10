#include <iostream>
#include <vector>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int w, h;
vector<vector<int>> graph;
vector<bool> isVisited;

void dfs(int num) {
    isVisited[num] = true;

    for(int i = 0; i < graph[num].size(); i++){
        int next = graph[num][i];
        if (!isVisited[next]) {
            dfs(next);
        }
    }

}

int main() {
    FAST; 
    int n, m;
    cin >> n;
    cin >> m;
    graph.assign(n + 1, vector<int>(0, 0));
    isVisited.assign(n + 1, false);

    for(int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    dfs(1);

    int count = 0;
    for (int result : isVisited) {
        if (result)
            count++;
    }
    cout << count - 1;

    return 0;
}
