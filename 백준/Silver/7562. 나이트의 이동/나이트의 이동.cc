#include <iostream>
#include <vector>
#include <queue>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

using namespace std;

// 7562
int n;
int x, y;
int destX, destY;
int result;

queue<pair<int, int>> q;
vector<vector<bool>> visited;

void init() {
    cin >> n;
    cin >> x >> y;
    cin >> destX >> destY;

    result = 0;
    visited = vector<vector<bool>>(n, vector<bool>(n, false));
    while (!q.empty()) {
        q.pop();
    }
}

void bfs(int x, int y) {
    visited[x][y] = true;
    q.push({x, y});

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int tempX = q.front().first;
            int tempY = q.front().second;
            q.pop();

            if(tempX == destX && tempY == destY)
                return;

            if (tempX + 2 < n && tempY + 1 < n && !visited[tempX + 2][tempY + 1]) {
                q.push({tempX + 2, tempY + 1});
                visited[tempX + 2][tempY + 1] = true;
            }
            if (tempX + 2 < n && tempY - 1 >= 0 && !visited[tempX + 2][tempY - 1]) {
                q.push({tempX + 2, tempY - 1});
                visited[tempX + 2][tempY - 1] = true;
            }
            if (tempX - 2 >= 0 && tempY + 1 < n && !visited[tempX - 2][tempY + 1]) {
                q.push({tempX - 2, tempY + 1});
                visited[tempX - 2][tempY + 1] = true;
            }
            if (tempX - 2 >= 0 && tempY - 1 >= 0 && !visited[tempX - 2][tempY - 1]) {
                q.push({tempX - 2, tempY - 1});
                visited[tempX - 2][tempY - 1] = true;
            }
            if (tempX + 1 < n && tempY + 2 < n && !visited[tempX + 1][tempY + 2]) {
                q.push({tempX + 1, tempY + 2});
                visited[tempX + 1][tempY + 2] = true;
            }
            if (tempX + 1 < n && tempY - 2 >= 0 && !visited[tempX + 1][tempY - 2]) {
                q.push({tempX + 1, tempY - 2});
                visited[tempX + 1][tempY - 2] = true;
            }
            if (tempX - 1 >= 0 && tempY + 2 < n && !visited[tempX - 1][tempY + 2]) {
                q.push({tempX - 1, tempY + 2});
                visited[tempX - 1][tempY + 2] = true;
            }
            if (tempX - 1 >= 0 && tempY - 2 >= 0 && !visited[tempX - 1][tempY - 2]) {
                q.push({tempX - 1, tempY - 2});
                visited[tempX - 1][tempY - 2] = true;
            }
        }
        result++;
    }
}

int main() {
    FAST;

    int a;
    cin >> a;

    for(int i = 0; i < a; i++) {
        init();
        bfs(x, y);
        cout << result << "\n";
    }
    
    return 0;
}
