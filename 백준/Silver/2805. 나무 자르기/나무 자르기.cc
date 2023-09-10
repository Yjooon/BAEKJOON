#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n;
long long m;
vector<long long> arr;
long long result = 0;

int main() {
    FAST;
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long left = 0;
    long long right = arr[n - 1];

    while (left <= right) {
        long long cut = (left + right) / 2;
        long long total = 0;

        for (long long i : arr) {
            if (i > cut)
                total += i - cut;            
        }
        if (total >= m) {
            result = max(cut, result);
            left = (left + right) / 2 + 1;
        }
        else {
            right = (left + right) / 2 - 1;
        }
    }
        
    cout << result << "\n";
    
    return 0;
}

