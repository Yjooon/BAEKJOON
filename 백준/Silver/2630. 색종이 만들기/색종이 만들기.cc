#include <iostream>
#include <vector>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, temp = -1;
vector<vector<int>> arr;
vector<int> result(2);

void add(int num, int row, int column) {
    temp = 0;
    for (int i = row; i < row + num; i++) {
        for (int j = column; j < column + num; j++) {
            temp += arr[i][j];
        }
    }
}

void func(int num, int row, int column) {
    add(num, row, column);

    if (temp == 0) {
        result[0]++;
    }
    else if (temp == (num * num)) {
        result[1]++;
    }
    else {
        for (int i = row; i < row + num; i += num / 2) {
            for (int j = column; j < column + num; j += num / 2) {
                func(num / 2, i, j);
            }
        }
    }
    return;
}

int main() {
    cin >> n;
    arr.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    func(n, 0, 0);
    cout << result[0] << "\n" << result[1];

    return 0;
}
