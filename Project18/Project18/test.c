#include <stdio.h>
#include <string.h>
//int main() 
//{
//    int i = 0;
//    int count = 0;
//    int arr[999999] = { 0 };
//    for (i = 10000; i <= 99999; i++) {
//        if (i == (i / 10000) * (i % 10000) + (i / 1000) * (i % 1000) + (i / 100) *
//            (i % 100) + (i / 10) * (i % 10))
//            arr[count++] = i;
//    }
//    for (i = 0; i <= count-1; i++)
//        printf("%d ", arr[i]);
//    return 0;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof arr[0];
//	int* p = arr;
//	for (i = 0;i < sz;i++)
//		printf("%d ", *p + i);
//	return 0;
//}
//
//
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	//*pa = 20;
//	//printf("%d", a);
//	int **ppa = &pa;
//	**ppa = 20;
//	printf("%d", a);
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* parr[10] = { &a,&b,&c };
//	printf("%d\n", *parr[0]);
//	*parr[0] = 20;
//	printf("%d", a);
//	return 0;
//}
//
//
//
//struct Peo
//{
//	char tele[20];
//	char sex[5];
//	char name[20];
//	int height;
//};
//struct s
//{
//	struct Peo m;
//	int money;
//	char personality[20];
//};
//void print1(struct Peo* p1)
//{
//	printf("%s %s %s %d\n", p1->tele, p1->sex, p1->name, p1->height);
//}
//void print2(struct Peo p1)
//{
//	printf("%s %s %s %d\n", p1.tele, p1.sex, p1.name, p1.height);
//}
//int main()
//{
//	struct Peo p1 = { "18792176851","nan","chengjiangfeng",188 };
//	struct s p = { {"18792176851","nan","chengjiangfeng",188},88888,"humble" };
//	printf("%s %s %s %d\n", p1.tele, p1.sex, p1.name, p1.height);
//	printf("%s %s %s %d %d %s\n", p.m.tele,p.m.sex,p.m.name,p.m.height,p.money,p.personality);
//	print1(&p1);
//	print2(p1);
//	return 0;
//}
//
//
//
//
//int main()
//{
//	int a = 0;
//	scanf_s("%d", &a);
//	int test = 1;
//	int count = 0;
//	int i = 0;
//	for (i = 0;i < 32;i++)
//	{
//		if (a & test == 1)
//			count++;
//		a = a >> 1;
//	}
//	printf("%d", count);
//	return 0;
//
//}
//
//int numof(unsigned int num)
//{
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//			count++;
//		num = num / 2;
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	scanf_s("%d", &num);
//	int n = numof(num);
//	printf("%d", n);
//
//}
//
//
//
//Seize the day,make your life extraordinary.
//
//int diffnum(int a, int b)
//{
//	int c = a ^ b;
//	int count = 0;
//	while (c)
//			{
//		        c = c & (c - 1);
//		        count++;
//			}
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a, &b);
//	int n = diffnum(a, b);
//    printf("%d", n);
//
//	return 0;
//}
//
//
//int main()
//{
//	int num = 0;
//	scanf_s("%d", &num);
//	char arr1[999] = { 0 };
//	char arr2[999] = { 0 };
//	int i = 0;
//	int num2 = num;
//	for (i = 0;i < 16;i++)
//	{
//		if ((num & 1) == 1)
//		{
//			arr1[i] = '1';
//			num = num >> 2;
//		}
//		else
//		{
//			arr1[i] = '0';
//			num = num >> 2;
//		}
//	}
//	num2 = num2 >> 1;
//	for (i = 0;i < 16;i++)
//	{
//		if ((num2 & 1) == 1)
//		{
//			arr2[i] = '1';
//			num2 = num2 >> 2;
//		}
//		else
//		{
//			arr2[i] = '0';
//			num2 = num2 >> 2;
//		}
//	}
//	for (i = 0;i < 16;i++)
//		printf("%c ", arr1[i]);
//	printf("\n");
//	for (i = 0;i < 16;i++)
//		printf("%c ", arr2[i]);
//	return 0;
//}
//
//
//int main()
//{
//	int num = 0;
//	scanf_s("%d", &num);  // ʹ�ñ�׼�� scanf
//	char arr1[16] = { 0 };  // �洢����λ
//	char arr2[16] = { 0 };  // �洢ż��λ
//	int i = 0;
//
//	for (i = 0; i < 16; i++) {
//		if ((num & 1) == 1) {  // �жϵ�ǰλ�Ƿ�Ϊ 1
//			arr1[i] = '1';  // ����λΪ 1
//		}
//		else {
//			arr1[i] = '0';  // ����λΪ 0
//		}
//		num = num >> 1;  // ����һλ��������һ��������λ
//	}
//
//	 �������� num����Ϊ��������Ѿ��ı��� num
//	num = 0;  // �������»�ȡ������ num Ϊ����ֵ��������ʾ
//
//	 �ֱ�ȡ����λ��ż��λ
//	for (i = 0; i < 16; i++) {
//		if ((num & 1) == 1) {
//			arr2[i] = '1';  // ż��λΪ 1
//		}
//		else {
//			arr2[i] = '0';  // ż��λΪ 0
//		}
//		num = num >> 1;  // ����
//	}
//
//	 ��ӡ����λ
//	printf("Odd positions: ");
//	for (i = 0; i < 16; i++) {
//		printf("%c ", arr1[i]);
//	}
//	printf("\n");
//
//	 ��ӡż��λ
//	printf("Even positions: ");
//	for (i = 0; i < 16; i++) {
//		printf("%c ", arr2[i]);
//	}
//	printf("\n");
//
//	return 0;
//}
//
//
//
//
//int main()
//{
//	char arr[20][20];
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			arr[i][j] = ' ';  // ��ʼ��Ϊ�ո�
//		}
//	}
//	while(i<n)
//	{
//		arr[i][j] = '*';
//		i++;
//		j++;
//	}
//	i = 0;
//	j = n - 1;
//	while (i < n)
//	{
//		arr[i][j] = '*';
//		i++;
//		j--;
//	}
//	for (i = 0;i < n;i++)
//	{
//		for (j = 0;j < n; j++)
//		{
//			printf("%c", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//
//int main() {
//	int n;
//	scanf_s("%d", &n);  // ���� X ��״�Ĵ�С
//	char arr[20][20];  // �����������Ϊ 20
//
//	// ��ʼ�����飬Ĭ�����Ϊ�ո�
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			arr[i][j] = ' ';  // ��ʼ��Ϊ�ո�
//		}
//	}
//
//	// ��䡰X���ķ�б�ߣ����ϵ����£�
//	for (int i = 0; i < n; i++) {
//		arr[i][i] = '*';  // ��б��λ��
//	}
//
//	// ��䡰X������б�ߣ����ϵ����£�
//	for (int i = 0; i < n; i++) {
//		arr[i][n - i - 1] = '*';  // ��б��λ��
//	}
//
//	// ��ӡ���
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%c", arr[i][j]);  // ���ÿ���ַ�
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//
//
//
//
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	while (scanf_s("%d %d %d", &a, &b, &c)==3)
//	{
//		if ((a + b > c) && (a + c > b) && (b + c > a))
//		{
//			if ((a == b) && (b == c) && (c == a))
//				printf("Equilateral triangle!\n");
//			else if ((a == b) || (b == c) || (c == a))
//				printf("Isosceles triangle!\n");
//			else
//				printf("Ordinary triangle!\n");
//		}
//		else
//			printf("Not a triangle!\n");
//	}
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0;i < 10;i++)
//	{
//		scanf_s("%d", &arr[i]);
//	}
//	for (i = 0; i < 10;i++)
//		printf("%d ", arr[i]);
//	return 0;
//}
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 4;
//	int b = 4;
//	int ret = Add(a, b);
//	printf("%d", ret);
//	return 0;
//}



//void test(int a[10])
//{
//
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//e	test(arr);
//	return 0;
//}



//int main()
//{
//	char arr1[20] = "XXXXXXXXXXXXXXX";
//	char arr2[20] = "hello woard!";
//	strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int ret = 1;
//	int sum = 0;
//	int i = 0;
//	for (i=1;i<=n;i++)
//	{
//		ret = ret * i;
//		sum = sum + ret;
//	}
//		printf("%d", sum);
//return 0;
//}


//int main()
//{
//	printf("%d\n", sizeof (int));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(unsigned long long));
//	printf("%d\n", sizeof(unsigned int));
//	return 0;
//}

//void print(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", *arr++);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	return 0;
//}



//int main()
//{
//	char arr[99999] = {0};
//	fgets(arr);
//	int i = 0;
//	int len = 0;
//	while (arr[i++] != '\0')
//	len++;
//	i = 0;
//	for (i = len - 1;i >= 0;i--)
//		printf("%c", arr[i]);
//	return 0;
//}



//int main()
//{
//	char arr[100000] = { 0 };
//	gets(arr);
//	int right = strlen(arr)-1;
//	int left = 0;
//	while (right >= left)
//	{
//		char tmp = 0;
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	printf("%s", arr);
//	return 0;
//}




//int main()
//{
//	int row = 0;
//	scanf_s("%d", &row);
//	int col = row % 2 == 0 ? row-1 : row;
//	int half1 = row % 2 == 0 ? row / 2 : row/2 + 1;
//	int half2 = row /2;
//	int i = 0;
//	int edge = col / 2;
//	int mid = 1;
//	int j = 0;
//	for (i = 1;i <= half1;i++)
//	{
//		for (j = 1;j <= edge;j++)
//			printf(" ");
//		for(j = 1;j <= mid;j++)
//			printf("*");
//		for (j = 1;j <= edge;j++)
//			printf(" ");
//		edge--;
//		mid += 2;
//		printf("\n");
//	}
//	if (row % 2 != 0)
//	{
//		edge +=2;
//		mid -= 4;
//	}
//	else
//	{
//		edge += 1;
//		mid -= 2;
//	}
//	
//	for (i = 1;i <= half2;i++)
//	{
//		for (j = 1;j <= edge;j++)
//			printf(" ");
//		for (j = 1;j <= mid;j++)
//			printf("*");
//		for (j = 1;j <= edge;j++)
//			printf(" ");
//		edge++;
//		mid -= 2;
//		printf("\n");
//	}
//	return 0;
//}

//int assess(int m,int newcup)
//{
//	if (m == 1)
//		return 1;
//	else if(m == 0)
//		return 0;
//	else
//		return newcup + assess(m % 2 + m / 2, m / 2);
//}
//
//int main()
//{
//	int cup = 0;
//	int money = 0;
//	scanf_s("%d", &money);
//	cup = assess(money,money);
//	printf("%d", cup);
//	return 0;
//}

//// �����ܹ��������ƿ��ˮ�ĺ���
//int calculateSodas(int money) {
//    int totalSodas = money;  // ��ʼ�����ˮ�������� 20 Ԫ�� 20 ƿ��
//    int emptyBottles = money; // ��ƿ�����������������ˮ��
//
//    // ��ƿ�������㹻����ˮʱ��������
//    while (emptyBottles >= 2) {
//        int newSodas = emptyBottles / 2;  // �ÿ�ƿ���õ���ˮ����
//        totalSodas += newSodas;           // ����ˮ��������
//        emptyBottles = emptyBottles % 2 + newSodas; // ʣ��Ŀ�ƿ���¿�ƿ�ϲ�
//    }
//
//    return totalSodas;
//}
//
//int main() {
//    int money;
//    scanf_s("%d", &money); // ������
//
//    // ���㲢������
//    int result = calculateSodas(money);
//    printf("%d\n", result);
//
//    return 0;
//}
