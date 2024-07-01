#include <iostream>
#include <vector>
#include <queue>

#define FAST ios_base::sync_with_stdio(false); cin::tie(NULL); cout::tie(NULL)

using namespace std;

int N, M;
queue<int> q;
vector<vector<int>> arr;
vector<bool> isVisited;
int result = 0;

void bfs(int temp) {
    q.push(temp);

    while(!q.empty()) {
        int a = q.front();
        q.pop();

        if (isVisited[a] == true) {
            continue;
        }

        isVisited[a] = true;

        for(int i : arr[a]) {
            if(isVisited[i] == false)
                q.push(i);
        }
    }
    result++;
}

int main() {
    cin >> N >> M;
    arr.resize(N + 1);
    isVisited.resize(N + 1);

    int x, y;
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    for(int i = 1; i <= N; i++) {
        if (isVisited[i] == false) {
            bfs(i);
        }
    }

    cout << result << "\n";

    return 0;
}