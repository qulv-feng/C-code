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
//	scanf_s("%d", &num);  // 使用标准的 scanf
//	char arr1[16] = { 0 };  // 存储奇数位
//	char arr2[16] = { 0 };  // 存储偶数位
//	int i = 0;
//
//	for (i = 0; i < 16; i++) {
//		if ((num & 1) == 1) {  // 判断当前位是否为 1
//			arr1[i] = '1';  // 奇数位为 1
//		}
//		else {
//			arr1[i] = '0';  // 奇数位为 0
//		}
//		num = num >> 1;  // 右移一位，处理下一个二进制位
//	}
//
//	 重新设置 num，因为上面操作已经改变了 num
//	num = 0;  // 假设重新获取或设置 num 为输入值，方便演示
//
//	 分别取奇数位和偶数位
//	for (i = 0; i < 16; i++) {
//		if ((num & 1) == 1) {
//			arr2[i] = '1';  // 偶数位为 1
//		}
//		else {
//			arr2[i] = '0';  // 偶数位为 0
//		}
//		num = num >> 1;  // 右移
//	}
//
//	 打印奇数位
//	printf("Odd positions: ");
//	for (i = 0; i < 16; i++) {
//		printf("%c ", arr1[i]);
//	}
//	printf("\n");
//
//	 打印偶数位
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
//			arr[i][j] = ' ';  // 初始化为空格
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
//	scanf_s("%d", &n);  // 输入 X 形状的大小
//	char arr[20][20];  // 假设最大输入为 20
//
//	// 初始化数组，默认填充为空格
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			arr[i][j] = ' ';  // 初始化为空格
//		}
//	}
//
//	// 填充“X”的反斜线（左上到右下）
//	for (int i = 0; i < n; i++) {
//		arr[i][i] = '*';  // 反斜线位置
//	}
//
//	// 填充“X”的正斜线（右上到左下）
//	for (int i = 0; i < n; i++) {
//		arr[i][n - i - 1] = '*';  // 正斜线位置
//	}
//
//	// 打印结果
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%c", arr[i][j]);  // 输出每个字符
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

//// 计算总共能买多少瓶汽水的函数
//int calculateSodas(int money) {
//    int totalSodas = money;  // 初始买的汽水数量（即 20 元买 20 瓶）
//    int emptyBottles = money; // 空瓶子数量（刚买完的汽水）
//
//    // 空瓶子数量足够换汽水时，继续换
//    while (emptyBottles >= 2) {
//        int newSodas = emptyBottles / 2;  // 用空瓶换得的汽水数量
//        totalSodas += newSodas;           // 总汽水数量增加
//        emptyBottles = emptyBottles % 2 + newSodas; // 剩余的空瓶和新空瓶合并
//    }
//
//    return totalSodas;
//}
//
//int main() {
//    int money;
//    scanf_s("%d", &money); // 输入金额
//
//    // 计算并输出结果
//    int result = calculateSodas(money);
//    printf("%d\n", result);
//
//    return 0;
//}
