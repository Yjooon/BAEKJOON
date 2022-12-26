#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);

	int a = 0;
	int arr[10];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr[i] = a;
	}

	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k >= arr[i]) {
			count += k / arr[i];
			k %= arr[i];
		}
		if (k == 0)
			break;
	}		

	printf("%d", count);
	
	return 0;
}