#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	int m, n;
	scanf("%d %d", &m, &n);
	int arr[100000] = { 0, };
	int count = 0;
	arr[count] = 2;
	count++;

	for (int i = 2; i <= n; i++) {			//2부터 n까지 각 숫자가 소수인지? 각 숫자 접근하는 반복문
		for (int j = 0; j < count; j++) {	//접근된 숫자에 대해서 소수인지 판별하려고 그 숫자보다 낮은 소수로 나눠보기.
			if (i % arr[j] == 0) {			//나누어 떨어지는 경우가 있으면 break. 
				break;
			}
			if (pow(arr[j], 2) > i) {			// 에라토스테네스의 체
				arr[count] = i;
				count++;
				break;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		if(arr[i] >= m)
			printf("%d\n", arr[i]);
	}
	return 0;
}