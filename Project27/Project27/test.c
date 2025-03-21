#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

//size_t test(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	int len = strlen(str1);
//	int k = 0;
//	char* p1 = str1;
//	while(*str2 != *str1)
//	{
//		str1++;
//		k++;
//	}
//	for (int i = 0;i < len - k;i++)
//	{
//		if (*str1 != *str2)
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	for (int i = 0;i < k;i++)
//	{
//		if (*p1 != *str2)
//		{
//			return 0;
//		}
//		p1++;
//		str2++;
//	}
//	return 1;
//}

size_t test(char* str1, const char* str2)\
{
	assert(str1 && str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	strncat(str1,str1,len1);
	if (strstr(str1, str2) != NULL)
		return 1;
	else
		return 0;
}

//
//int main()
//{
//	char arr1[100] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = test(arr1,arr2);
//	printf("%d", ret);
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    int arr[10][10];
//    for (int i = 0;i < n;i++)
//    {
//        for (int j = 0;j < m;j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (int i = 0;i < m;i++)
//    {
//        for (int j = 0;j < n;j++)
//        {
//            printf("%d ", arr[j][i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include <stdio.h>

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[100];
//    for (int i = 0;i < n;i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int i = 0;
//    while (((arr[i] - arr[i + 1]) == 0) && (i < n - 1))
//    {
//        i++;
//    }
//    if ((arr[i] - arr[i + 1]) > 0)
//    {
//        int j = 0;
//        while (arr[j] >= arr[j + 1] && j < n - 1)
//        {
//            j++;
//        }
//        if (j == n-1)
//            printf("sorted");
//        else
//            printf("unsorted");
//    }
//    else if ((arr[i] - arr[i + 1]) < 0)
//    {
//        int j = 0;
//        while (arr[j] <= arr[j + 1] && j < n - 1)
//        {
//            j++;
//        }
//        if (j == n-1)
//            printf("sorted");
//        else
//            printf("unsorted");
//    }
//    else
//    {
//        printf("sorted");
//    }
//    return 0;
//}
//struct stu
//{
//	char name[20];
//	int age;
//};