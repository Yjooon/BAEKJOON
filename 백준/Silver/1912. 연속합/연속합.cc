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
    arr.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    result = dp[0];
    int sum = arr[0];

    for (int i = 1; i < n; i++) {
        sum += arr[i];
        if (arr[i] > 0) {
            dp[i] = sum;
        }
        else {
            if (sum < 0) {
                sum = 0;
            }
            dp[i] = max(dp[i - 1], arr[i]);
        }

    }
    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }

    
    
    cout << result;

    return 0;
}
