#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct Str
{
	int i;
	int arr[];
}Str;

//int main()
//{
//	Str* s1;
//	s1 = (Str*)malloc(sizeof(Str) + 10*sizeof(int));
//	if (s1 == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	s1->i = 2;
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		s1->arr[i] = i;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", s1->arr[i]);
//	}
//	printf("\n%d", s1->i);
//
//	Str* ptr = (Str*)realloc(s1, sizeof(Str) + 80);
//	if (ptr != NULL)
//	{
//		s1 = ptr;
//		ptr = NULL;
//	}
//
//	free(s1);
//	s1 = NULL;
//
//	return 0;
//}

typedef struct S
{
	int i;
	int* arr;
}S;

int main()
{
	S* s1;
	s1->i = 0;
	s1->i = (S*)malloc(sizeof(S));
	s1->arr = (S*)malloc(40);
	if(s1->i == NULL)
		{
			printf("%s\n", strerror(errno));
			return 1;
		}
	if (s1->arr == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}

	s1->i = 2;
	int i = 0;
	for (i = 0;i < 10;i++)
	{
		s1->arr[i] = i;
	}
	for (i = 0;i < 10;i++)
	{
		printf("%d ", s1->arr[i]);
	}
	printf("\n%d", s1->i);

	Str* ptr = (Str*)realloc(s1->arr, 80);
		if (ptr != NULL)
		{
			s1->arr = ptr;
			ptr = NULL;
		}

	free(s1->arr);
	free(s1->i);

	return 0;
}

