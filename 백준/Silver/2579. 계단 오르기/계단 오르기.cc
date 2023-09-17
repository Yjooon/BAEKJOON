#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, result = 0;
vector<int> arr;
vector<int> dp;


int main() {
    FAST;    
    cin >> n;    
    arr.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int stack = 0;
    dp[0] = arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[i] = arr[i];
            stack++;
            continue;
        }
        if (i == 2) {
            dp[i] = arr[1] + arr[i];
            stack++;
            continue;
        }
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
    }
    
    
    cout << dp[n];

    return 0;
}
