#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
	int N, M;
    scanf("%d %d", &N, &M);
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    int temp[3];
    int sum = 0, max = 0;
    for (int i = 0; i < N; i++) {
        temp[0] = arr[i];
        for(int j = i + 1; j < N; j++){
            temp[1] = arr[j];
            for(int k = j + 1; k < N; k++){
                temp[2] = arr[k];
                sum = temp[0] + temp[1] + temp[2];
                if (sum <= M)
                    max = std::max(sum, max);
                if (max == M) {
                    printf("%d\n", max);
                    return 0;
                }
            }
        }
    }
    printf("%d\n", max);

	return 0;
}