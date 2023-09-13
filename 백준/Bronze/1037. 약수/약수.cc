#include <iostream>
#include <vector>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, input;
vector<int> arr;

int main() {
    cin >> n;

    arr.push_back(1000000);
    arr.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input < arr[0]) {
            arr[0] = input;
        }
        if (input > arr[1]) {
            arr[1] = input;
        }
    }
    arr.push_back(arr[0] * arr[1]);

    cout << arr[2];
    
    return 0;
}
