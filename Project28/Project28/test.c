#include <stdio.h>
struct stu
{
	char* name;
	int age;
	int gender;
}s1 = {"cheng",18,1};

struct S3
{
	double d;
	char c;
	int i;
};

struct S4
{
	char c1;
	struct S3 s3;
	double d;
};
//0 1 2 3 4 5 6 7 8 9    12 13 14 15 16 17 18 19 20 21 22 /////////
int main()
{
	printf("%d\n", sizeof(struct S4));
}

/*int main()
{
	char arr[] = "abcdef";
	s1.name = "sdfhilh";
	s1.name = arr;
	printf("%s", s1.name);
	return 0;
}*///01234567 8   9 10 11        12 13 14 15 16