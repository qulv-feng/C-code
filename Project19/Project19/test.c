#include <stdio.h>
#include <stdio.h>
#include <assert.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a, &b);
//	int max = a > b ? a : b;
//	int num = a > b ? a : b;
//	while (1)
//	{
//		if (num % a == 0 && num % b == 0)
//		{
//			printf("%d", num);
//			break;
//		}
//		else
//		{
//			num+=max;
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a, &b);
//	int i = 1;
//	int max = a > b ? a : b;
//	int min = a < b ? a : b;
//	while ((max*i)%min != 0)
//	{
//		i++;
//	}
//	printf("%d", max * i);
//	return 0;
//}


//I like beijing.
//int main()
//{
//	char arr1[100] = { 0 };
//	gets(arr1);
//	int count = 0;
//	int j = 0;
//	int x = 0;
//	int y = 0;
//	int i = 0;
//	int len = strlen(arr1);
//	int arr2[100] = { 0 };
//	for (i = 0;i < len;i++)
//	{
//		if (arr1[i] == ' ')
//		{
//			arr2[count] = i;
//			count++;
//		}
//	}
//	int tmp = count;
//	arr2[count] = len - 1;
//	for (i = 0;i <= count;i++)
//	{
//		if (i == 0)
//		{
//			y = arr2[tmp];
//			if (tmp - 1 < 0)
//			{
//				x = 0;
//				j = 0;
//			}
//			else
//			{
//				x = arr2[tmp - 1];
//				j = arr2[tmp - 1]+1;
//			}
//			while (j >= x && j <= y)
//			{
//				printf("%c", arr1[j]);
//				j++;
//			}
//			tmp--;
//		}
//		else
//		{
//			y = arr2[tmp];
//			if (tmp - 1 < 0)
//			{
//				x = 0;
//				j = 0;
//			}
//			else
//			{
//				x = arr2[tmp - 1];
//				j = arr2[tmp - 1];
//			}
//			while (j >= x && j <= y)
//			{
//				printf("%c", arr1[j]);
//				j++;
//			}
//			tmp--;
//		}
//	}
//	return 0;
//}


//int main() {
//    char arr1[100] = { 0 };
//    int arr2[100] = { 0 };
//    int count = 0; // ��¼�ո������
//    int len;
//
//     �����ַ��������Ƴ���
//    printf("������һ�仰�����Ȳ�����99����\n");
//    fgets(arr1, sizeof(arr1), stdin);
//    len = strlen(arr1);
//
//     ȥ��ĩβ�Ļ��з�
//    if (arr1[len - 1] == '\n') {
//        arr1[len - 1] = '\0';
//        len--;
//    }
//
//     ��¼�ո��λ��
//    for (int i = 0; i < len; i++) {
//        if (arr1[i] == ' ') {
//            arr2[count++] = i;
//        }
//    }
//    arr2[count] = len; // ���һ�����ʵĽ���λ��
//
//     �����������
//    int start, end;
//    for (int i = count; i >= 0; i--) {
//        start = (i == 0) ? 0 : arr2[i - 1] + 1;
//        end = arr2[i];
//        for (int j = start; j < end; j++) {
//            putchar(arr1[j]);
//        }
//        if (i > 0) {
//            putchar(' ');
//        }
//    }
//    putchar('\n');
//    return 0;
//}


//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* start = arr;
//	int* end = *start + 100 - 1;
//	return 0;
//}

//void reverse(char* start, char* end)
//{
//	assert(start);
//	assert(end);
//	while (end >= start)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		end--;
//		start++;
//	}
//}
//
//int main()
//{
//	printf("������һ�仰�����Ȳ�����99����\n");
//	char arr[101] = { 0 };
//	gets(arr);
//	int len = strlen(arr);
//	char* start = arr;
//	char* end = arr + len - 1;
//	reverse(start,end);
//	end = start;
//	while (*start)
//	{
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		reverse(start, end - 1);
//		if (*end != '\0')
//		{
//			end++;
//
//		}
//		start = end;
//	}
//	printf("%s", arr);
//	return 0;
//}



//int main()
//{
//    int m = 0;
//    int n = 0;
//    scanf_s("%d %d", &m, &n);
//    int i = 0;
//    int j = 0;
//    int arr[100][100] = {0};
//    for (i = 0;i < m;i++)
//    {
//        for (j = 0;j < n;j++)
//        {
//            scanf_s("%d", &arr[i][j]);
//        }
//    }
//    for (i = 0;i < n;i++)
//    {
//        for (j = 0;j < m;j++)
//        {
//            printf("%d", arr[j][i]);
//            if (j != m - 1)
//                printf(" ");
//        }
//        if(i != n-1)
//            printf("\n");
//    }
//    return 0;
//}

//int main()
//{
//    int m = 0;
//    int n = 0;
//
//    // �������������
//    scanf_s("%d %d", &m, &n);
//
//    int i = 0, j = 0;
//    int arr[6][6] = { 0 }; // ��Ŀ���� m �� n �� 2 �� 6 ֮��
//
//    // �����������
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf_s("%d", &arr[i][j]);
//        }
//    }
//
//    // ���ת�þ���
//    for (i = 0; i < n; i++) // ԭ�����б�Ϊ�µ���
//    {
//        for (j = 0; j < m; j++) // ԭ�����б�Ϊ�µ���
//        {
//            printf("%d ", arr[j][i]); // ע��˴����ʵ��� arr[j][i]
//        }
//        printf("\n");
//    }
//
//    return 0;
//}


//#include <stdio.h>
//
//#define MAXN 10
//
//int Sum(int List[], int N);
//
//int main()
//{
//    int List[MAXN], N, i;
//
//    scanf_s("%d", &N);
//    for (i = 0; i < N; i++)
//        scanf_s("%d", &List[i]);
//    printf("%d\n", Sum(List, N));
//
//    return 0;
//}

//int Sum(int List[], int N)
//{
//    int i = 0;
//    int sum = 0;
//    for (i = 0; i < N;i++)
//    {
//        sum += *List;
//        List++;
//    }
//    return sum;
//}



