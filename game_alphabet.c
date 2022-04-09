#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int check_char(char str[21], char a) {
	int i = 0;
	while (str[i] != '\0')
	{
		//printf("%c\n", str[i]);
		if (str[i] == a)
			return 1;

		i++;
	}
	return 0;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char str[21] = "_";
	char a = 'a' - 1;
	int i = 0, k;

	while (i < 26 || str[0] != '_')
	{
		a += 1;
		scanf("%s", str);
		if (str[0] == '_')
		{
			printf("NO WINNER");
			break;
		}

		k = check_char(str, a);
		if (k == 0)
		{
			if (i % 2 == 0)
			{
				printf("PLAYER 2");
			}
			else
			{
				printf("PLAYER 1");
			}
			break;
		}


		str[0] = '_';
		i++;
	}

	return 0;
}
