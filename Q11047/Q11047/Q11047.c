#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);

	int a = 0;
	int* arr = (int*)malloc(sizeof(int) * n);	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr[i] = a;
	}

	int count = 0;
	while (k > 0) {
		for (int i = 0; i < n; i++) {
			if (k >= arr[i] && k < arr[i + 1]) {
				k -= arr[i];
				count++;
				if (k >= arr[i])
					i--;
			}
		}		
	}
	printf("%d", count);
	
	free(arr);
	return 0;
}