#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int n = 0;
	int count = 0;

	scanf("%d", &n);
	//일단 최대한 많이 5를 넣어보고, 3으로 안나눠진다고 하면
	//하나씩 빼면서 3으로 나눠지는 값을 맞추고
	//다뺐는데도 안맞춰지면 -1 반환하면 될 것 같다. 
	

	int remain = n % 5;
	switch (remain)
	{
	case 0:
		count = n / 5;
		break;
	case 1:	//5 하나 빼기. 121같은 경우. 120+1 말고 115+6
		n -= remain + 5 * 1;
		if (n >= 0)
			count = n / 5 + 2;
		else
			count = -1;
		break;
	case 2: //5 두개 빼기. 122 120+2말고 110+12 
		n -= remain + 5 * 2;
		if (n >= 0)
			count = n / 5 + 4;
		else
			count = -1;
		break;
	case 3: //5로 나누고 나머지가 3이니 1 더해주기.
		count = (n / 5) + 1;
		break;
	case 4: //나머지 4니까 한번만 빼주기. 124 -> 120+4 말고 115 + 9
		n -= remain + 5 * 1;
		if (n >= 0)
			count = n / 5 + 3;
		else
			count = -1;
		break;
	
	default:
		printf("Error!");
		break;
	}



	
	printf("%d", count);
	return 0;
}