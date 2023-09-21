#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N;
int arr[501][501] = { 0, };
int dp[501][501] = { 0, };

int main() {
    FAST;
    
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++)
            cin >> arr[i][j];
    }
    dp[1][1] = arr[1][1];
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
                continue;
            }
            if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
        }
    }    
    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = max(result, dp[N][i]);
    }

    cout << result;

    return 0;
}
