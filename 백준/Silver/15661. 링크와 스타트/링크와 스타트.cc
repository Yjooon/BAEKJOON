#include <iostream>
#include <vector>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, result = 2147483647;
vector<vector<int>> arr;
vector<int> start;
vector<int> link;

int pickTwo(vector<int>& a) {
	int value = 0;
	for (int i = 0; i < a.size(); i++) {
		for(int j = i + 1; j < a.size(); j++)
			value += arr[a[i] - 1][a[j] - 1];
	}
	return value;
}

void makeTeam() {
	for (int k = 2; k < n; k++) {
		if (start.size() == k) {
			link.clear();
			for (int i = 1; i <= n; i++) {
				bool flag = false;
				for (int j : start) {
					if (i == j)
						flag = true;
				}
				if (!flag) {
					link.push_back(i);
				}
			}
			result = min(result, abs(pickTwo(start) - pickTwo(link)));		
		}
	}
	


	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (flag && start.size() > 0) {
			i = start.back() + 1;
			flag = false;
		}
		if (i > n)
			continue;	

		start.push_back(i);
		makeTeam();
		start.pop_back();
	}
}

int main() {
	FAST;
	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++) {
		arr[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			arr[i][j] += arr[j][i];
		}
	}

	makeTeam();	

	cout << result;

	return 0;
}