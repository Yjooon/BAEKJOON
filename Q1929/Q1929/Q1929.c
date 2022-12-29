#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int m, n;
	scanf("%d %d", &m, &n);
	int arr[100000] = { 0, };
	int count = 0;
	if (m <= 2) {						//시작이 2보다 작을때 2 집어넣어버리기
		arr[count] = 2; count++;
		m = 3;
	}
	if (m % 2 == 0)						//짝수 처리 
		m++;
	for (int i = m; i < n; i+=2) {		//3 이상 홀수에 대해서 2씩 증가.
		for (int j = 2; j < i; j++) {
			if (i % j == 0 ) {
				break;
			}
			if (j == i / 3 + 1) {
				arr[count] = i;
				count++;
			}			
		}
	}
	for(int i = 0; i < count; i++)
		printf("%d\n", arr[i]);
	return 0;
}