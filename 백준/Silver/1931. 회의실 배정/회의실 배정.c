#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}greed;

int compare(const void* a, const void* b) {
	greed A = *(greed*)a;
	greed B = *(greed*)b;
	if (A.y > B.y)
		return 1;
	else if (A.y == B.y) {
		if (A.x > B.x)
			return 1;
		else
			return -1;
	}
	else
		return -1;
}

int main(void) {
	greed gr[100010];
	int size;	
	scanf("%d", &size);
	
	int i = 0;
	for (i = 0; i < size; i++) {
		scanf("%d %d", &gr[i].x, &gr[i].y);
	}
	qsort(gr, i, sizeof(greed), compare);

	int count = 1;					//최소 한개
	int j = 0;
	for (i = 1; i < size; i++) {
		if (gr[j].y <= gr[i].x) {
			j = i;
			count++;
		}
	}


	
	printf("%d\n", count);
	return 0;
}