#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, r, c, a = 0;
bool endFlag = false;

void func(int num, int row, int column) {
    if (!endFlag && r - row <= 1 && c - column <= 1) {
        endFlag = true;
        if (r - 1 == row && c - 1 == column) {
            a += 3; 
            cout << a; return;
        }
        else if (r - row > c - column) {
            a += 2; 
            cout << a; return;
        }
        else if (c - column > r - row) {
            a += 1;
            cout << a; return;
        }
        else {
            cout << a; return;
        }
    }
    if (num == 2) {
        a += 4;
        return;
    }
   
    if (endFlag)
        return;
    
    for (int i = row; i < row + num; i += num / 2) {
        for (int j = column; j < column + num; j += num / 2) {
            if (r - i >= num / 2 || c - j >= num / 2) {
                a += (num / 2) * (num / 2);
                continue;
            }
            func(num / 2, i, j);
        }
    }    
    return;
}

int main() {
    FAST;
    cin >> n >> r >> c;
    n = pow(2, n);

    func(n, 0, 0);

    return 0;
}
