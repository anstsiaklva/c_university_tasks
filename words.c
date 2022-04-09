#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int check_char(char str[21], char a) {
	int i = 0;
	while (str[i] != '\0') {
		//printf("%c\n", str[i]);
		if (str[i] == a) {
			return 1;
		}
		i++;
	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char str[100] = " ";
	char str_first[100] = " ";
	int i, flag;

	scanf("%s", str_first);
	while (scanf("%s", str) == 1)
	{
		i = 0;
		flag = 0;
		while (str_first[i] != '\0')
		{
			flag += check_char(str, str_first[i]);
			i++;
		}
		if (flag == 0)
			printf("%s\n", str);

	}


	return 0;
}
