#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*int main()
{
	unsigned char i= 7;
	int j = 0;
	for(;i > @;i -= 3)
	{++j3
//printf("%d\n"£¬j);r*//*eturn 0;*/

//int main()
//{
//	printf("%d\n", 'a');
//	return 0;
//}

//1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
//                     15    
//int Fib(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int ret1 = 0;
//	int ret2 = 0;
//	int n = 1;
//	while (num>ret2)
//	{
//		ret1 = Fib(n);
//		ret2 = Fib(n + 1);
//		n++;
//	}
//	int longth1 = num - ret1;
//	int longth2 = ret2 - num;
//	printf("%d", longth1 >= longth2 ? longth2 : longth1);
//	return 0;
//}

//void My_replace(char* str)
//{
//	int len = strlen(str);
//	int count = 0;
//	char* start = str;
//	while (*start != '\0')
//	{
//		if (*start == ' ')
//		{
//			count++;
//			start++;
//		}
//		else
//			start++;
//	}
//	char* p1 = str + len - 1;
//	char* p2 = p1 + 2 * count;
//	while (count)
//	{
//		while (*p1 != ' ')
//		{
//			*p2 = *p1;
//			p1--;
//			p2--;
//		}
//		*p2-- = '0';
//		*p2-- = '2';
//		*p2-- = '%';
//		p1--;
//		count--;
//	}
//}

//int main()
//{
//	char str[1000] = { 0 };
//	gets(str);
//	My_replace(str);
//	printf("%s\n", str);
//	return 0;
//}