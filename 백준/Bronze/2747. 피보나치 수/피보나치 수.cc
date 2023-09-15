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
    arr.resize(input + 1);

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= input; i++) {
        arr[i] = (arr[i - 2] + arr[i - 1]);
    }


    cout << arr[input];

    return 0;
}
