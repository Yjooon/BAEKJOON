#include <iostream>
#include <vector>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n;
vector<int> input;
vector<vector<int>> arr;

int main() {
    FAST;    
    arr.resize(41, vector<int>(2));
    arr[0][0] = 1; arr[0][1] = 0;
    arr[1][0] = 0; arr[1][1] = 1;    
    for (int i = 2; i < 41; i++) {
        arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
        arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
    }
    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];                
    }
    for (int i = 0; i < n; i++) {
        cout << arr[input[i]][0] << " " << arr[input[i]][1] << "\n";
    }


    return 0;
}
