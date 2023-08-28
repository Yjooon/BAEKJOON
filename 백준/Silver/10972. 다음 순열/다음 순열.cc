#include <iostream>
#include <algorithm>
#include <vector>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL) 

using namespace std;

int main() {
    FAST;
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (next_permutation(arr.begin(), arr.end())) {
        for (int i : arr)
            cout << i << " ";
    } else {
        cout << -1;
    }

    return 0;
}
