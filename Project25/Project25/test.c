//#include <stdio.h>
//#include <math.h>
//#include <assert.h>
//
//void* my_memmove(void* dest, void* src, size_t bit)
//{
//	assert(dest && src);
//	void* p = dest;
//	if (dest >= src)
//	{
//		void* str = (char*)src + bit - 1;
//		void* end = (char*)dest + bit - 1;
//		while (bit--) 
//		{
//			*(char*)end = *(char*)str;
//			end = (char*)end - 1;
//			str = (char*)str - 1;
//		}
//	}
//	else
//	{
//		while(bit--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest - 1;
//			src = (char*)src - 1;
//		}
//	}
//	return p;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	my_memmove(arr + 4, arr , 5 * sizeof(int));
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int num = n;
//	int i = 1;
//	while (n > 10)
//	{
//		n = n / 10;
//		i = i + 1;
//	}
//	int sum = 0;
//	int big_num = 0;
//	for (int j = 1;j < i;j++)
//	{
//		big_num *= 10;
//	}
//	while (i--)
//	{
//		if ((num / big_num) != 0)
//		{
//			sum = sum + big_num;
//		}
//		num = num % big_num;
//		big_num /= 10;
//	}
//	printf("%d", sum);
//	return 0;
//}