#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
a[1000000] = { 0 };
/*функция быстрой сортировки*/
void quickSort(int *numbers, int left, int right)
{
	int pivot; /*начальны элемент*/
	int l_hold = left; /*левая граница*/
	int r_hold = right; /*правая граница*/
	pivot = numbers[left]; /*задаем значение начального элемента как значение левой границы*/
	while (left < right) /*продолжаем, пока границы не сомкнутся*/
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; /*сдвигаем правую границу, пока начальный элемент меньше, чем правая граница*/
		if (left != right) /*если границы не сомкнулись*/
		{
			numbers[left] = numbers[right]; /*меняем начальный элемент и правый элемент местами*/
			left++; /*сдвиг левой границы*/
		}
		while ((numbers[left] <= pivot) && (left < right)) /*сдвигаем левую границу, пока начальный элемент больше, чем левая граница*/
			left++; 
		if (left != right) 
		{
			numbers[right] = numbers[left]; /*меняем элементы правой и левой границы местами*/
			right--; /*сдвигаем границу местами*/
		}
	}
	numbers[left] = pivot; /*ставим начальный элемент на место*/
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) /*рекурсивно вызываю сортировку левой части массива*/
		quickSort(numbers, left, pivot - 1);
	if (right > pivot) /*рекурсивно вызываю сортировку правой части массива*/
		quickSort(numbers, pivot + 1, right);
}
int main()
{
	int n, j, k, i;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quickSort(a, 0, n - 1); 
			  
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	getchar();
	return 0;
}
