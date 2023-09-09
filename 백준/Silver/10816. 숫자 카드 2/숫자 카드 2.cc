#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, m;
int index = 0;
vector<int> arr;
vector<int> result;

int findIndexD(int num, int start, int end) {
    if (end == start) {        //같은 요소가 여러 개 있으면 제일 작은 인덱스로 반환
        return start;
    }

    if (num > arr[(start + end) / 2]) { // 절반 위 
        return findIndexD(num, (start + end) / 2 + 1, end);
    }
    else { //절반 아래
        return findIndexD(num, start, (start + end) / 2);
    }
}
int findIndexU(int num, int start, int end) {
    if (end == start) {        //같은 요소가 여러 개 있으면 제일 큰 인덱스로 반환
        return start;
    }

    if (num < arr[(start + end) / 2]) { // 절반 위 
        return findIndexU(num, start, (start + end) / 2);
    }
    else { //절반 아래
        return findIndexU(num, (start + end) / 2 + 1, end);
    }
}


void isNum(int num, int start, int end) {    
    if (end == start) {
        if (arr[start] == num) {
            int a = findIndexD(num + 1, 0, n - 1);
            int b = findIndexU(num - 1, 0, n - 1);
            result[index] = a - b - 1;
            if (arr[a] == num) {
                result[index]++;
            }
            if (arr[b] == num) {
                result[index]++;
            }
            index++;
        }
        else {
            result[index] = 0; 
            index++;
        }
        return;
    }

    if (num > arr[(start + end) / 2]) { // 절반 위 
        isNum(num, (start + end) / 2 + 1, end);
        return;
    }
    else { //절반 아래
        isNum(num, start, (start + end) / 2);
        return;
    }
}



int main() {
    FAST;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cin >> m;
    result.resize(m);
    int input = 0;
    for (int i = 0; i < m; i++) {
        cin >> input;
        isNum(input, 0, n - 1);
    }

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}

