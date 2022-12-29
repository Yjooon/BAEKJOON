#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num = 0;	
	scanf("%d", &num);
	int dp[1000001] = { 0, };
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= num; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = dp[i / 3] + 1 < dp[i] ? dp[i / 3] + 1 : dp[i];
		if(i % 2 == 0)
			dp[i] = dp[i/2] + 1 < dp[i] ? dp[i/2] + 1 : dp[i];		
	}
	printf("%d", dp[num]);
	return 0;
}