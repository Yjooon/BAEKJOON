#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, k;

void backtrack(vector<int>& arr, vector<int>& temp) {
	if (temp.size() == m) {
		for (int i : temp) {
			cout << i << " ";
		}
		printf("\n");

		return;
	}
	
	for (int i = 0; i < arr.size(); i++) {
		bool flag = false;
		for (int k : temp) {
			if (arr[i] == k) {
				flag = true;
			}
		}
		
		if (flag)
			continue;

		temp.push_back(arr[i]);
		backtrack(arr, temp);
		temp.pop_back();
	}
}

int main(void) {
	
	scanf("%d %d", &n, &m);

	vector<int> arr;
	vector<int> temp;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		arr.push_back(k);
	}

	sort(arr.begin(), arr.end());
	backtrack(arr, temp);

	return 0;
}