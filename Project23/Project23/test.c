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
//#include <string.h>  // 用于 strlen
//
//char* my_strcat_s(char* dest, int len, const char* src)
//{
//	assert(dest && src);  // 确保指针不为空
//
//	int dest_len = strlen(dest);  // 获取目标字符串长度
//	int src_len = strlen(src);    // 获取源字符串长度
//
//	if (dest_len + src_len + 1 < len) 
//	{  // 确保拼接后不会溢出
//		char* start = dest + dest_len;   // 定位到目标字符串的 '\0' 处
//
//		while ((*start++ = *src++) != '\0')
//		{
//			;  // 逐字符复制 src 到 dest 末尾
//		}
//		return dest;
//	}
//	else
//	{
//		printf("err: buffer too small\n");
//		return NULL;  // 返回 NULL 以指示错误
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
//		printf("拼接失败\n");
//	}
//
//	return 0;
//}