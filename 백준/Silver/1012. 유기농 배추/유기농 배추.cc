#include <iostream>
#include <vector>
#include <queue>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

//1012

int T;
int M, N, K;
int x, y;
vector<pair<int, int>> input;

vector<vector<int>> arr;
vector<vector<bool>> isVisited;
queue<pair<int, int>> q;

bool flag = false;

int result = 0;

void init() {
    cin >> M >> N >> K;
    arr.assign(M, vector<int>(N, 0));
    isVisited.assign(M, vector<bool>(N, false));
    result = 0;
    for(int i = 0; i < K; i++) {
        cin >> x >> y;
        input.push_back({x, y});
        arr[x][y] = 1;
    }
}

bool bfs(int x, int y) {
    q.push({x, y});

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if (a >= 0 && b >= 0 && a < M && b < N && isVisited[a][b] == false) {
            isVisited[a][b] = true;
            if (arr[a][b] == 1) {
                flag = true;
            }   
            else if (arr[a][b] == 0) {
                continue;
            }
        }
        else {
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            q.push({a + dx[i], b + dy[i]});
        }
    }

    return flag;
}

int main(void) {
    cin >> T;
    for(int i = 0; i < T; i++) {
        init();
        for(int j = 0; j < input.size(); j++) {
            flag = false;
            if (bfs(input[j].first, input[j].second) == true) {
                result++;
            }
        }
        cout << result << "\n";
    }
    
    
    return 0;
}