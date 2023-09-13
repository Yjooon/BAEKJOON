#include <iostream>
#include <vector>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n;
int input;
vector<int> arr;


int main() {
    FAST;    
    cin >> input;
    arr.resize(input);

    arr[0] = 1;
    arr[1] = 3;
    for (int i = 2; i < input; i++) {
        arr[i] = (arr[i - 2] * 2 + arr[i - 1])%10007;
    }


    cout << arr[input - 1];

    return 0;
}
