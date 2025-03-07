#include <stdio.h>
#include <string.h>
//void print(int (*p)[5],int row,int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < row; i++)
//	{
//		for (j = 0;j < col;j++)
//		{
//			printf("%d ",*(*(p+i)+j));
//		}
//		printf("\n");
//	}
//}
// 

void reverse_even_odds(int arr[], int len)
{
	int left = 0;
	int right = len-1;
	int i = 0;
	while (right > left)
	{
		while (right > left)
		{
			if (*(arr + left) % 2 != 0)
			{
				left++;
			}
			else
				break;
		}
		while (right > left)
		{
			if (*(arr + right) % 2 == 0)
			{
				right--;
			}
			else
				break;
		}
		int tmp = *(arr + left);
		*(arr + left) = *(arr + right);
		*(arr + right) = tmp;
	}
	while (i < len)
	{
		printf("%d ", *(arr + i));
		i++;
	}
}

void mune()
{
	printf("********************************\n");
	printf("************1.Add   ************\n");
	printf("************2.Sub   ************\n");
	printf("************3.Mul   ************\n");
	printf("************4.Div   ************\n");
	printf("************0.exit  ************\n");
	printf("********************************\n");
}
void cal(int (*p)(int,int))
{
	int x = 0;
	int y = 0;
	printf("Please input number\n");
	scanf_s("%d %d", &x, &y);
	int ret = p(x, y);
	printf("%d\n", ret);
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

int main()
{
	/*int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
	print(arr, 3, 5);
	return 0;*/

	/*void (  *signal(  int, void(*) (int)  )  )   (int);*/
	/*int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr)/sizeof(arr[0]);
	reverse_even_odds(arr, sz);
	return 0;*/

	int input = 0;
	do {
		mune();
		printf("Please choose your mode:");
		scanf_s("%d", &input);
		int (*arr[4]) = { Add,Sub,Mul,Div };
		switch (input)
		{
		case 1:
			cal(arr[input]);
			break;
		case 2:
			cal(arr[input]);
			break;
		case 3:
			cal(arr[input]);
			break;
		case 4:
			cal(arr[input]);
			break;
		case 0:
			printf("Glad to see you again\n");
			break;
		default:
			printf("ERR!!\n");
			break;
		}
	} while (input);
		return 0;
}