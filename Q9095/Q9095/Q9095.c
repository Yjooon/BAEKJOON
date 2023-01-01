#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num;
	scanf("%d", &num);

	int arr[11] = { 0, };
	arr[1] = 1;														//1
	arr[2] = 2;														//2
	arr[3] = 4;														//4

	int a = 0;
	int* pr = (int*)malloc(sizeof(int) * num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &a);
		for (int j = 4; j <= a; j++) {
			arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
		}
		pr[i - 1] = arr[a];
	}
	for (int i = 0; i < num; i++) {
		printf("%d\n", pr[i]);
	}

	//	
	//arr[1] = 1;														//1
	//arr[2] = 2;														//2
	//arr[3] = 4;														//4
	//arr[4] = 1 + (4 - 1) + (4 - 2) + 1 ;								//7
	//arr[5] = 1 + (5 - 1) + (5 - 2) + 3 + 2 + 1;						//13
	//arr[6] = 1 + (6 - 1) + (6 - 2) + (6 - 3) * 2 + 6 + 1 + 1;			//24
	//	
	return 0;
}