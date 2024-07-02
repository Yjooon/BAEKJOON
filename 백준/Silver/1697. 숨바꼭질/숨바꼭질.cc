#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

#define FAST ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL):

using namespace std;

//1697

int N, K;
queue<pair<int, int>> q;
vector<bool> isVisited(100001, false);
int result = 100001;

int bfs() {
    q.push({N, 0});

    while(!q.empty()) {
        int a = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(a < 0 || a > 100000 || isVisited[a])
            continue;

        isVisited[a] = true;

        if (a == K) {
            result = min(dist, result);
            return result;
        }
        if (dist > result)
            continue;
        
        if (a * 2 <= 100000 && !isVisited[a * 2])
            q.push({a * 2, dist + 1});
        if (a + 1 <= 100000 && !isVisited[a + 1])
            q.push({a + 1, dist + 1});
        if (a - 1 >= 0 && !isVisited[a - 1])
            q.push({a - 1, dist + 1});
    }

    return result;
}

int main() {
    cin >> N >> K;
    
    cout << bfs() << "\n";

    return 0;
}