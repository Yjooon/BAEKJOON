#include <iostream>
#include <algorithm>
#include <vector>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL) //빠른 입출력
using namespace std;

int n, m, k;
vector<int> arr;
vector<int> temp;

void backtrack() {
	if (temp.size() == m) {
		for (int i : temp) cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); ++i) {
		temp.push_back(arr[i]);
		backtrack();
		temp.pop_back();
	}
}

int main(void) {
	FAST;
	cin >> n >> m;
	arr.resize(n); //벡터 크기를 n으로 지정

	for (int i = 0; i < n; ++i) 
		cin >> arr[i]; 

	sort(arr.begin(), arr.end());
	backtrack();

	return 0;
}