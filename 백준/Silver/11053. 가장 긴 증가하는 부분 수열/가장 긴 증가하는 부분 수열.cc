#include <iostream>
#include <algorithm>
#include <vector>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N;
int arr[1000][2];

int main() {
    FAST;
    
    cin >> N;
        
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0];
    }
    arr[0][1] = 1;
    int dp = 0, result = 1;
    for (int i = 1; i < N; i++) {
        dp = 0;
        for (int j = 0; j < i; j++) {            
            if (arr[j][0] < arr[i][0]) {
                dp = max(dp, arr[j][1]);
            }            
        }
        arr[i][1] = dp + 1;
        result = max(result, arr[i][1]);
    }
    
    cout << result;

    return 0;
}
