#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, m;
vector<vector<int>> arr;
vector<vector<int>> row;
vector<int> temp;


int main() {
    FAST;    
    cin >> n >> m;    
    arr.resize(n, vector<int>(m));
    row.resize(n, vector<int>(m));
    string str;
    
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j] - '0';
        }
    }
    
    int result = 0, column = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                row[i][j] = arr[i][j];
                continue;
            }
            if (arr[i][j] == 0) {
                row[i][j] = 0;
                continue;
            }
            row[i][j] += row[i][j - 1] + arr[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            temp.clear();
            while (i < n && row[i][j] != 0) {
                temp.push_back(row[i][j]);
                i++;
            }

            column = 0;
            for (int k = 0; k < temp.size(); k++) {
                if (temp[k] <= result) {
                    column = 0;
                    continue;
                }
                column++;
                if (column > result) {
                    k -= column;
                    result = column;
                    column = 0;
                    continue;
                }
            }
        }
    }
    
    cout << result * result;

    return 0;
}
