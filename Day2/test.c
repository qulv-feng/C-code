#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	int i = 0;
//	int sum = 0;
//	while (input)
//	{
//		int bit = input % 10;
//		if (bit % 2 == 1)
//		{
//			sum += pow(10, i);
//		}
//		i++;
//		input /= 10;
//	}
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//	int row = 0;
//	scanf_s("%d", &row);
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 1;i <= row;i++)
//	{
//		for (j = 0;j < row - i;j++)
//		{
//			printf("  ");
//		}
//		for (k = 0;k < row - j - 1;k++)
//		{
//			printf("* ");
//		}
//		printf("*");
//		printf("\n");
//	}
//	return 0;
//}

//int main() 
//{
//	double price = 0;
//	int mon = 0;
//	int day = 0;
//	int code = 0;
//	double money = 0;
//	scanf_s("%lf %d %d %d", &price, &mon, &day, &code);
//	if (mon == 11 && day == 11)
//	{
//		money = price * 0.7;
//		if (code == 1)
//			money -= 50;
//	}
//	else if (mon == 12 && day == 12)
//	{
//		money = price * 0.8;
//		if (code == 1)
//			money -= 50;
//	}
//	if(money>0)
//		printf("%.2f", money);
//	else
//		printf("Free!!!");
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	for (a = 0;a <= 1;a++)
//	{
//		for (b = 0;b <= 1;b++)
//		{
//			for (c = 0;c <= 1;c++)
//			{
//				for (d = 0;d <= 1;d++)
//				{
//					if ((a != 1) + (c == 1) + (d == 1) + (d != 1) == 3)
//					{
//						if ((a + b + c + d) == 1)
//						{
//							printf("%d %d %d %d", a, b, c, d);
//							printf("\n");
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

void spin(char* str, int k)
{
	int j = k;
	int len = strlen(str);
	k %= len;
	while (k)
	{
		char* start = str + k;//acdefb k=1
		char tmp_0 = *(start - 1);
		for (int i = 0;i < len - j;i++)
		{
			*(start - 1 + i) = *(start + i);
		}
		*(start + len - j - 1) = tmp_0;
		k--;
	}
}

void spin(char* str, int k)
{
	int len = strlen(str);
	k %= len;
	while (k)
	{
		char tmp = *str;
		for (int i = 0;i < len - 1;i++)
		{
			*(str + i) = *(str + 1 + i);
		}
		*(str + len - 1) = tmp;
		k--;
	}
}

//int main()
//{
//	char arr[] = { "abcdef" };
//	int k = 0;
//	scanf_s("%d", &k);
//	spin(arr, k);
//	printf("%s", arr);
//	return 0;
//}