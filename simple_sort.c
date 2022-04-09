#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
int a[1000000] = { 0 };

int main()
{
	int n, j, i;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;

}
