#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int num = 0;
	while (1) {
		num++;
		if (b >= c) {
			num = -1;
			break;
		}
		else {
			c -= b;
			num = a / c + 1;
			break;			
		}
	}

	printf("%d", num);
	
	

	return 0;
}