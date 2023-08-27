#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL) //빠른 입출력

using namespace std;

int n, m;
vector<int> arr;
vector<int> temp;
vector<int> index;

set<vector<int>> result;

void backtrack() {
	if (temp.size() == m) {
		result.insert(temp);		
		return;
	}

	for (int i = 0; i < arr.size(); ++i) {	
		//index로 중복 처리
		bool flag = false;
		for (int k : index) {
			if (k == i) {
				flag = true;
			}
		}
		if (flag)
			continue;
		
		temp.push_back(arr[i]); 
		index.push_back(i);		
		backtrack();
		temp.pop_back();
		index.pop_back();
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

	for (const auto& i : result) {
		for (int num : i) {
			cout << num << " ";
		}
		cout << "\n";
	}

	return 0;
}