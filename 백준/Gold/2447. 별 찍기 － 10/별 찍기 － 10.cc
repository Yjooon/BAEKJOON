#include <iostream>
#include <vector>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n;

void star(int num, int i, int j) {    
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) 
        cout << " ";
    else if (num / 3 == 0)
        cout << "*";
    else
        star(num / 3, i, j);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            star(n, i, j);
        }
        cout << "\n";
    }

    return 0;
}
