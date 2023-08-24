#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtrack(vector<int>& arr, vector<int>& temp, int n, int m) {
	if (temp.size() == m) {
		for (int i : temp) {
			cout << i << " ";
		}
		printf("\n");

		return;
	}

	for (int i : arr) {
		temp.push_back(i);
		backtrack(arr, temp, n, m);
		temp.pop_back();

	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int>arr;
	vector<int>temp;

	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}

	backtrack(arr, temp, n, m);

	return 0;
}