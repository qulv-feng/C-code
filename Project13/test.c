#include <stdio.h>
//int main()
//{
//	int i = 1;
//	for (i = 1;i <= 100;i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;   
//scanf_s("%d %d", &a, &b);


	/*if (a <= b)
	{
		for (i = a;i > 0;i--)
		{
			if (a % i == 0 && b % i == 0)
			{
				printf("i = %d ", i);
				break;
			}
		}
	}
	else
	{
		for (i = b;i > 0;i--)
		{
			if (a % i == 0 && b % i == 0)
			{
				printf("i = %d ", i);
				break;
			}
		}
	}*/


	/*int min = a > b ? a : b;  
	int max = a < b ? a : b;
	if (max % min == 0)
	{
		printf("%d ", min);
	}
	else
	{
		while (1)
		{
			int c = max % min;
			if (min % c == 0)
			{
				printf("%d ", c);
				break;
			}
			else
			{
				max = min;
				min = c;
			}
		}
	}*/

	/*while (a % b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	printf("%d ", c);*/

//
//	return 0;
//}




//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1;i <= 100;i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if(i/10 == 9)
//			count++;
//	}
//	printf("%d ", count);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	float x = 0;
//	float y = 0;
//	for (i = 1;i <= 100;i++)
//	{
//		if (i % 2 == 0)
//			x -= 1.0 / i;
//		if (i % 2 == 1)
//			y += 1.0 / i;
//
//	}
//	printf("%f", x+y);
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int i = 1;
//	int max = 0;
//	for (i = 1; i < + n; i++)
//	{
//		int num = 0;
//		scanf_s("%d", &num);
//		static max = num;
//		if (num > max)
//			max = num;
//	}
//	printf(" max= %d ", max);
//	return 0;
//}

//void mul(int n)
//{
//	int i = 0;
//	for (i = 1;i <= n;i++)
//	{
//		int j = 0;
//		for (j = 1;j <= i;j++)
//			printf("%d*%d=%-2d ", i, j, i * j);
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	mul(n);
//	return 0;
//}




//Ã°ÅÝÅÅÐò
void bubble(int arr[], int sz)
{
	int i = 0;
		for (i = 0;i < sz-1;i++)
		{
			int n = 0;
			for (n=0;n<sz-i-1;n++)
			{
				if (arr[n] > arr[n + 1])
				{
					int tmp = arr[n];
					arr[n] = arr[n+1];
					arr[n+1] = tmp;
				}
				    
			}
		}
}

int main()
{
	int arr[10] = {0};
	int i = 0;
	for(i=0;i<10;i++)
	    scanf_s("%d", &arr[i]);
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sz);
	for (i = 0;i <= sz - 1;i++)
		printf("%d ", arr[i]);
	return 0;
} 