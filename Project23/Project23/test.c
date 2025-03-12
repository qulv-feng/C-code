#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
size_t my_strlen(char* str)
{
	assert(str);
	size_t count = 0;
	while (1)
	{
		if (*str == '\0')
			break;
		else
		{
			count++;
			str++;
		}
	}
	return count;
}


//int my_strlen(char* str)
//{
//	assert(str);
//	char* p = str;
//	while (1)
//	{
//		if (*str == '\0')
//			break;
//		else
//		{
//			str++;
//		}
//	}
//	return str-p;
//}


//int main()
//{
//	char arr[] = { "qwdsreasfw" };
//	int len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}

//#include <stdio.h>


//char* my_strcpy(char* a,const char* b)
//{
//	assert(a);
//	assert(b);
//	char* ret = a;
//	while ((*a++ = *b++) != '\0')
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr[] = "asdfghjk";
//	char* str = "abcdef";
//	my_strcpy(arr, str);
//	printf("%s", arr);
//}

char* my_strcat_s(char* dest,int len ,const char* src)
{
	assert(dest && src);
	char* start = dest;
	int len_dest = my_strlen(dest);
	int len_src = my_strlen(src);
	if (len_dest + len_src + 1 < len)
	{
		dest = dest + len_dest;
		while ((*dest++ = *src++) != '\0')
		{
			;
		}
	}
	else
	{
		return NULL;
	}

	return start;
}
int main()
{
	char arr[100] = { "hello " };
	char* p = "world";
    my_strcat_s(arr,sizeof(arr), p);
	printf("%s", arr);
	return 0;
}

//#include <stdio.h>
//#include <assert.h>
//#include <string.h>  // ���� strlen
//
//char* my_strcat_s(char* dest, int len, const char* src)
//{
//	assert(dest && src);  // ȷ��ָ�벻Ϊ��
//
//	int dest_len = strlen(dest);  // ��ȡĿ���ַ�������
//	int src_len = strlen(src);    // ��ȡԴ�ַ�������
//
//	if (dest_len + src_len + 1 < len) 
//	{  // ȷ��ƴ�Ӻ󲻻����
//		char* start = dest + dest_len;   // ��λ��Ŀ���ַ����� '\0' ��
//
//		while ((*start++ = *src++) != '\0')
//		{
//			;  // ���ַ����� src �� dest ĩβ
//		}
//		return dest;
//	}
//	else
//	{
//		printf("err: buffer too small\n");
//		return NULL;  // ���� NULL ��ָʾ����
//	}
//}
//
//int main() {
//	char arr[100] = "hello ";
//	char* p = "world";
//
//	if (my_strcat_s(arr, sizeof(arr), p)) {
//		printf("%s\n", arr);
//	}
//	else {
//		printf("ƴ��ʧ��\n");
//	}
//
//	return 0;
//}