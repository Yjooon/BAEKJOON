#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, m;
int arr[4][4];
int temp[4][4];

int main() {
    FAST;
    int sum, result = 0;
    string str;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j] - '0';
        }
    }    

    // 가로 = 1, 세로 = 0
    for (int mask = 0; mask < (1 << n * m); mask++) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            copy(begin(arr[i]), end(arr[i]), begin(temp[i]));
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((j != m - 1) && (((mask >> j + i * m) & 1) == 1) && (((mask >> j + 1 + i * m) & 1) == 1)) { //가로 두개 이어져있으면
                    temp[i][j + 1] += temp[i][j] * 10;
                }
                else if ((i != n - 1) && (((mask >> j + i * m) & 1) == 0) && (((mask >> j + m + i * m) & 1) == 0)) { //세로 두개 이어져있으면
                    temp[i + 1][j] += temp[i][j] * 10;
                }
                else
                    sum += temp[i][j];
            }
        }
        result = max(result, sum);
    }

    cout << result;

    return 0;
}
