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
	
	for (int i = 0; i < arr.size(); i++) {
		if (temp.size() >= 1) {
			if (arr[i] < temp[temp.size() - 1]) {
				continue;
			}
		}

		temp.push_back(arr[i]);
		backtrack(arr, temp, n, m);
		temp.pop_back();
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> arr;
	vector<int> temp;

	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}

	backtrack(arr, temp, n, m);

	return 0;
}