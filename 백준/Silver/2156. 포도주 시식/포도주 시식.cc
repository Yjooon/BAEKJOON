#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N;
int arr[10001];
vector<int> dp;

int main() {
    FAST;
    
    cin >> N;
    dp.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            dp[0] = arr[0];
            continue;
        }
        if (i == 1) {
            dp[1] = arr[0] + arr[1];
            continue;
        }
        if (i == 2) {
            dp[2] = max(max(arr[0] + arr[2], arr[1] + arr[2]), dp[1]);
            continue;
        }
        if (i == 3) {
            dp[3] = max(max(arr[0] + arr[2] + arr[3], dp[1] + arr[3]), arr[1] + arr[2]);
            continue;
        }

        dp[i] = max(max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]), dp[i - 1]);
    }
    if (N >= 3)
        cout << max(dp[N - 1], max(dp[N - 2], dp[N - 3]));
    else
        cout << max(dp[0], dp[1]);

    return 0;
}
