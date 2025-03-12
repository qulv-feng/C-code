#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p)
	{
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return p;
		}
		p++;
		s1=p;
		s2 = str2;
	}
	return NULL;
}


//int main()
//{
//	char arr1[] = { "asbbbbqcrf"};
//	char arr2[] = { "bbc" };
//	char* ret = my_strstr(arr1, arr2);
//	if (ret != NULL)
//		printf("%s\n", ret);
//	else
//		printf("No this string\n");
//	return 0;
//}