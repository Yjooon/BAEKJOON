#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

void backtrack(std::vector<int>& temp, std::vector<int>& arr, int m) {
	if (temp.size() == m) {
		for (int num : temp) {
			std::cout << num << " ";
		}
		printf("\n");
		
	}

	for (int a : arr) {
		bool selected = false;
		for (int b : temp) {
			if (b == a) {
				selected = true;
				break;
			}
		}

		if (!selected) {
			temp.push_back(a);
			backtrack(temp, arr, m);
			temp.pop_back();
		}
	}
}

int main(void) {
	int n, m;

	scanf("%d %d", &n, &m);

	std::vector<int> arr;
	std::vector<int> temp;

	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}
	backtrack(temp, arr, m);
	
	return 0;
}