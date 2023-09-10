#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n;
vector<vector<int>> arr;
vector<int> temp;
vector<int> result(3);

void square(int row, int column, int repeat) {
	if (arr[row][column] == 2)
		return;
	for (int i = row; i < row + repeat; i++) {
		for (int j = column; j < column + repeat; j++) {			
			if (arr[i][j] == -1)
				temp[0]++;
			else if (arr[i][j] == 0)
				temp[1]++;
			else if (arr[i][j] == 1)
				temp[2]++;
		}
	}
	return;
}
void squareOff(int row, int column, int repeat) {
	for (int i = row; i < row + repeat; i++) {
		for (int j = column; j < column + repeat; j++) {
			arr[i][j] = 2;
		}
	}
	return;
}

void func(int num) {
	int i = 0, j = 0;
	while (1) {
		temp.assign(3, 0);
		square(i, j, num);
		if ((i + num) == n && (j + num) == n)
			break;

		for (int k = 0; k < temp.size(); k++) {
			if (temp[k] == num * num) {
				squareOff(i, j, num);
				result[k]++;
			}
		}

		if (j + num == n) {
			j = 0;
			i += num;
		}
		else
			j += num;		
	}

	for (int k = 0; k < temp.size(); k++) {
		if (temp[k] == num * num) {
			squareOff(i, j, num);
			result[k]++;
		}
	}
	
	if (num != 1)
		func(num / 3);

	return;
}

int main() {
	FAST;
	cin >> n;

	arr.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	func(n);

	for (int i : result) {
		cout << i << "\n";
	}
    return 0;
}
