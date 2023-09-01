#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int main() {
    FAST;
    int n, sum = 0;
    int result = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    while (next_permutation(arr.begin(), arr.end())) {
        for (int i = 0; i < arr.size() - 1; i++) {
            sum += abs(arr[i] - arr[i + 1]);
        }
        result = max(result, sum);
        sum = 0;
    }    

    cout << result;

    return 0;
}
