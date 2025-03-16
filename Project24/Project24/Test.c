#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

//int main()
//{
//	char* str = "abcdef";
//	char arr[100] = { "qwqertyuui" };
//	strncat(arr,str,1);
//	printf("%s", arr);
//	return 0;

//char* my_strncat(char* dest,const char* src,int len)
//{
//	assert(dest && src);
//	char* start = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	for (int i = 0;i < len;i++)
//	{
//		if (*src != '\0')
//		{
//			*dest++ = *src++;
//		}
//		else
//		{
//			*dest = '\0';
//			dest++;
//		}
//	}
//	*dest = '\0';
//	return start;
//}

//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "To be ");
//	strcpy(str2, "or");
//	my_strncat(str1, str2, 8);
//	printf("%s",str1);
//	return 0;
//}
//
//char* my_strncpy(char* dest, const char* src, int len)
//{
//	assert(dest && src);
//	char* start = dest;
//	for (int i = 0;i < len;i++)
//	{
//		if (*src != '\0')
//		{
//			*dest++ = *src++;
//		}
//		else
//		{
//			*dest = '\0';
//			dest++;
//		}
//	}
//	*dest = '\0';
//	return start;
//}

//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "To be ");
//	strcpy(str2, "or not to be");
//	my_strncpy(str1, str2, 12);
//	puts(str1);
//	return 0;
//}

//
//int my_strncmp(const char* str1, const char* str2, unsigned int len)
//{
//	assert(str1 && str2);
//	int i = 0;
//	while(*str1 == *str2 && *str1!='\0' && *str2 != '\0' && i<len)
//	{
//		str1++;
//		str2++;
//		i++;
//	}
//	if (i == len)
//		return 0;
//	else
//		return(*str1 - *str2);
//}


//int main()
//{
//	char str1[100] = { "R2D2ezadad"};
//	char str2[100] = { "R2D2ef" };
//	int ret = my_strncmp(str1, str2,6);
//	printf("%d", ret);
//	re
// 
// turn 0;
//}

//int main()
//{
//	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
//	int n;
//	puts("Looking for R2 astromech droids...");
//	for (n = 0; n < 3; n++)
//		if (my_strncmp(str[n], "R2xx", 2) == 0)
//		{
//			printf("found %s\n", str[n]);
//		}
//	return 0;
//}

//int main()
//{
//	char myname[] = "Pierre de Fermat";
//	 /* using memcpy to copy string: */
//	memcpy(person.name, myname, strlen(myname) + 1);
//	person.age = 46;
//	 /* using memcpy to copy structure: */
//	memcpy(&person_copy, &person, sizeof(person));
//	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
//	return 0;
//}
// 
// 
//函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
//这个函数在遇到 '\0' 的时候并不会停下来。
//如果source和destination有任何的重叠，复制的结果都是未定义的。

//void* my_memcpy(void* dest, const void* src, unsigned int num)
//{
//	assert(dest && src);
//	void* p = dest;
//	int i = 0;
//	for (i = 0;i < num;i++)
//	{
//		*(char*)dest = *(char*)src;
//		(char*)dest += 1;
//		(char*)src += 1;
//	}
//	return p;
//}

//int main()
//{
//	char arr[100] = { "qwertyuuiopasdfghjk" };
//	char str[] = { "abcdef" };
//	my_memcpy(arr, str,strlen(str));
//	printf("%s", arr);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	int arr1[999] = { 0 };
//	int arr2[999] = { 0 };
//
//	int i = 0;
//	for (i = 0;i < n;i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	for (i = 0;i < m;i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	memcpy(arr1 + n, arr2, m*sizeof(arr2[0]));
//	int sz = m + n;
//	int j = 0;
//	for (i = 0;i < sz;i++)
//	{
//		int flag = 1;
//		for (j = 0;j < sz - i-1;j++)
//		{
//			if (arr1[j] > arr1[j + 1])
//			{
//				int tmp = arr1[j];
//				arr1[j] = arr1[j + 1];
//				arr1[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>

//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//
//    int arr1[999] = { 0 };
//    int arr2[999] = { 0 };
//
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (i = 0; i < m; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//
//    // 只拷贝 m 个元素，防止数组越界
//    memcpy(arr1 + n, arr2, m * sizeof(int));
//
//    int sz = n + m;  // 修正数组总大小计算
//
//    // 冒泡排序
//    for (i = 0; i < sz - 1; i++)
//    {
//        int flag = 1;
//        for (int j = 0; j < sz - i - 1; j++)
//        {
//            if (arr1[j] > arr1[j + 1])
//            {
//                int tmp = arr1[j];
//                arr1[j] = arr1[j + 1];
//                arr1[j + 1] = tmp;
//                flag = 0;
//            }
//        }
//        if (flag == 1)
//        {
//            break;
//        }
//    }
//
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//
//    return 0;
//}

int main()
{
	char str[] = "This is a simple string";
	char* pch;
	pch = strstr(str, "simple");
	strncpy(pch, "sample", 6);
	puts(str);
	return 0;
}