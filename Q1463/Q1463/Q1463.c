#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num = 0;
	int count = 0;

	scanf("%d", &num);
	while (num != 1) {		
		if (num % 3 == 0) 
			num /= 3;		
		else if (num % 3 == 1)
			num -= 1;
		else if (num % 2 == 0)
			num /= 2;
		else
			num -= 1;
		count++;
	}
	printf("%d", count);
	return 0;
}