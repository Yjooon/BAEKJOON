#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> arr(11, 0);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    int a;
    vector<int> pr(num);
    for (int i = 1; i <= num; i++) {
        cin >> a;
        for (int j = 4; j <= a; j++) {
            arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
        }
        pr[i - 1] = arr[a];
    }
    for (int i = 0; i < num; i++) {
        cout << pr[i] << endl;
    }

    return 0;
}
