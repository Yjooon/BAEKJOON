#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int size = 0;
	scanf("%d", &size);

	//int arr[1000];
	int* arr = (int*)malloc(sizeof(int) * size);
	int a, b;
	for (int i = 0; i < size; i++) {
		scanf("%d %d", &a, &b);
		int c = 1;							//끝자리수만 반환할 변수
		for (int j = 0; j < b; j++) {
			c *= a;
			c %= 10;						//곱셈 후 10의자리 이상 값 떨구기
		}
		arr[i] = c;
	}

	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}

	free(arr);
	return 0;
}