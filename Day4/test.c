#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GetMemory(char** p)
{
	*p = (char*)malloc(100);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
}

int main()
{
	Test();
	return 0;
}


//int main()
//{
//	return 0;
//}
//
//void test_1(int* q)
//{
//	*q = 2;
//}

//void test(void)
//{
//	int a = 1;
//	int* p = &a;
//	test_1(p);
//	printf("%d", *p);
//}
//
//int main()
//{
//	test();
//	return 0;
//}