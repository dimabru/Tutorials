#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mergeTwoArrays(char*, char*);
int checkIfInt(char *);

void main()
{
	char size1s[80], size2s[80];
	char *arr1, *arr2, *newarr;
	int size1, size2;

	do {
		printf("Enter size of first string\n");
		scanf("%s", &size1s);
		size1 = checkIfInt(size1s);
		if (size1 == -1) printf("Wrong input. Try again\n");
	} while (size1==-1);

	do {
		printf("Enter size of second string\n");
		scanf("%s", &size2s);
		size2 = checkIfInt(size2s);
		if (size2 == -1) printf("Wrong input. Try again\n");
	} while (size2 == -1);

	arr1 = (char*)malloc(size1);
	arr2 = (char*)malloc(size2);

	printf("Enter first sentence: \n");
	scanf("%s", arr1);

	printf("Enter second sentence: \n");
	scanf("%s", arr2);

	newarr = mergeTwoArrays(arr1, arr2);
	printf("The new merged array: %s\n", newarr);
	getch();
	free(arr1);
	free(arr2);
	free(newarr);
}

int checkIfInt(char *arr)
{
	int i,size=0;
	for (i = 0; i < strlen(arr); i++)
	{
		if (arr[i]<'0' || arr[i]>'9') return -1;
		size = size * 10 + (arr[i] - 48);
	}
	return size;
}

char *mergeTwoArrays(char *arr1, char *arr2)
{
	int i,j, size = strlen(arr1) + strlen(arr2) + 1;
	char *arr = (char*)malloc(size);

	for (i = 0; i < strlen(arr1); i++) arr[i] = arr1[i];
	for (i = strlen(arr1), j=0; i < size; i++, j++) arr[i] = arr2[j];
	printf("%d\n", size);
	arr[size - 1] = '\0';
	return arr;
}