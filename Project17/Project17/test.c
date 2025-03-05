#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // ��׼��������⣬���������������
#include <stdlib.h> // ��׼�⣬������������ɺ�����ͨ�ù���
#include <time.h> // ʱ��⣬�����������������

//#define MAX_QUESTIONS 100 // ���忼��ģʽ����Ŀ���������
//
//// ��������
//void menu(); // ��ʾ���˵�
//void practice_mode(int type); // ��ϰģʽ
//void exam_mode(int type); // ����ģʽ
//void generate_question(int type, int* num1, int* num2, char* op); // ������Ŀ
//int evaluate_answer(int num1, int num2, char op); // �����
//
//int main() {
//    int choice, type; // choice�洢�û�ѡ���ģʽ��type�洢ѡ�����Ŀ����
//
//    srand(time(NULL)); // ʹ�õ�ǰʱ��������������ӣ�ȷ��ÿ��������Ŀ���
//
//    while (1) { // ����ѭ����ֱ���û�ѡ���˳�
//        menu(); // ��ʾ�˵�
//        printf("\n���������ѡ��: ");
//        scanf("%d", &choice); // ��ȡ�û������ѡ��
//
//        if (choice == 3) { // ���ѡ��3���˳�����
//            printf("ϵͳ�˳����ټ���\n");
//            break;
//        }
//
//        printf("��ѡ����Ŀ����:\n");
//        printf("1. ʮ���ڼӼ���\n");
//        printf("2. ʮ���Ӽ�����λ\n");
//        printf("3. ʮ����������λ\n");
//        printf("4. ��ʮ���ڼӼ���\n");
//        printf("���������ѡ��: ");
//        scanf("%d", &type); // ��ȡ�û��������Ŀ����
//
//        if (type < 1 || type > 4) { // ��֤�������Ŀ�����Ƿ���Ч
//            printf("��Ч����Ŀ���ͣ����ز˵���\n\n");
//            continue; // ���ز˵�
//        }
//
//        if (choice == 1) { // ���ѡ����ϰģʽ
//            practice_mode(type); // ������ϰģʽ
//        }
//        else if (choice == 2) { // ���ѡ����ģʽ
//            exam_mode(type); // ���뿼��ģʽ
//        }
//        else { // ���ѡ����Ч
//            printf("��Ч��ģʽ�����ز˵���\n\n");
//        }
//    }
//
//    return 0; // ���������˳�
//}
//
//void menu() {
//    // ��ʾ���˵�
//    printf("\n======= ����ѵ��ϵͳ =======\n");
//    printf("1. ��ϰģʽ\n");
//    printf("2. ����ģʽ\n");
//    printf("3. �˳�\n");
//    printf("==========================================\n");
//}
//
//void practice_mode(int type) {
//    int num1, num2, user_answer, correct_answer; // ��������洢���������û��𰸺���ȷ��
//    char op; // �洢�����
//
//    printf("\n��ϰģʽ - ��10��\n");
//
//    for (int i = 0; i < 10; i++) { // ѭ������10����Ŀ
//        generate_question(type, &num1, &num2, &op); // ������Ŀ
//        correct_answer = evaluate_answer(num1, num2, op); // ������ȷ��
//
//        while (1) { // ѭ��ֱ���û�������ȷ��
//            printf("��%d��: %d %c %d = ", i + 1, num1, op, num2);
//            scanf("%d", &user_answer); // ��ȡ�û���
//
//            if (user_answer == correct_answer) { // �жϴ��Ƿ���ȷ
//                printf("��ȷ��\n\n");
//                break; // ����ѭ��
//            }
//            else {
//                printf("���������ԣ�\n"); // ��ʾ�û����´���
//            }
//        }
//    }
//}
//
//void exam_mode(int type) {
//    int num1, num2, user_answer, correct_answer; // ��������洢���������û��𰸺���ȷ��
//    char op; // �洢�����
//    int num_questions, correct_count = 0; // ��Ŀ�����ʹ�Ե���Ŀ����
//
//    printf("\n����ģʽ\n");
//    printf("��������Ŀ����: ");
//    scanf("%d", &num_questions); // ��ȡ�û��������Ŀ����
//
//    if (num_questions < 1 || num_questions > MAX_QUESTIONS) { // ��֤��Ŀ�����Ƿ���Ч
//        printf("��Ч����Ŀ���������ز˵���\n\n");
//        return; // ���ز˵�
//    }
//
//    int user_answers[num_questions]; // �洢�û��Ĵ�
//    char results[num_questions]; // �洢ÿ��Ľ������/��
//    int question_nums[num_questions][2]; // �洢ÿ���������
//    char operators[num_questions]; // �洢ÿ��������
//
//    for (int i = 0; i < num_questions; i++) { // ѭ��������Ŀ
//        generate_question(type, &num1, &num2, &op); // ������Ŀ
//        correct_answer = evaluate_answer(num1, num2, op); // ������ȷ��
//
//        question_nums[i][0] = num1; // �����һ��������
//        question_nums[i][1] = num2; // ����ڶ���������
//        operators[i] = op; // ���������
//
//        printf("��%d��: %d %c %d = ", i + 1, num1, op, num2);
//        scanf("%d", &user_answer); // ��ȡ�û���
//
//        user_answers[i] = user_answer; // �����û���
//
//        if (user_answer == correct_answer) { // �жϴ��Ƿ���ȷ
//            results[i] = '��'; // ��ȷ���
//            correct_count++; // ��ȷ������1
//        }
//        else {
//            results[i] = 'X'; // ������
//        }
//    }
//
//    printf("\n���Խ��:\n");
//    for (int i = 0; i < num_questions; i++) { // ��ӡÿ��Ľ��
//        printf("��%d��: %d %c %d = %d (%c)\n", i + 1, question_nums[i][0], operators[i], question_nums[i][1], user_answers[i], results[i]);
//    }
//
//    printf("\n��ȷ����: %d/%d\n", correct_count, num_questions); // ��ӡ��ȷ����
//    printf("��ȷ��: %.2f%%\n\n", (correct_count / (float)num_questions) * 100); // ��ӡ��ȷ��
//}
//
//void generate_question(int type, int* num1, int* num2, char* op) {
//    *op = (rand() % 2 == 0) ? '+' : '-'; // ������ɼӷ������
//
//    switch (type) {
//    case 1: // ʮ���ڼӼ���
//        *num1 = rand() % 10 + 1; // �������1��10����
//        *num2 = rand() % 10 + 1; // �������1��10����
//        if (*op == '-' && *num1 < *num2) { // ����Ǽ����ҵ�һ����С�ڵڶ�����
//            int temp = *num1;
//            *num1 = *num2;
//            *num2 = temp; // ������������ȷ�����Ϊ����
//        }
//        break;
//
//    case 2: // ʮ���Ӽ�����λ
//        *num1 = rand() % 9 + 11; // ����11��19����
//        *num2 = rand() % (10 - (*num1 % 10)); // ���ɸ�λ����ʹ�䲻��λ
//        if (rand() % 2 == 0) { // �������λ��
//            int temp = *num1;
//            *num1 = *num2;
//            *num2 = temp;
//        }
//        *op = '+'; // ȷ���Ǽӷ�
//        break;
//
//    case 3: // ʮ����������λ
//        *num1 = rand() % 9 + 11; // ����11��19����
//        *num2 = rand() % ((*num1 % 10) + 1); // ���ɸ�λ����ʹ�䲻��λ
//        *op = '-'; // ȷ���Ǽ���
//        break;
//
//    case 4: // ��ʮ���ڼӼ���
//        *num1 = rand() % 20 + 1; // ����1��20����
//        *num2 = rand() % 20 + 1; // ����1��20����
//        if (*op == '-' && *num1 < *num2) { // ����Ǽ����ҵ�һ����С�ڵڶ�����
//            int temp = *num1;
//            *num1 = *num2;
//            *num2 = temp; // ������������ȷ�����Ϊ����
//        }
//        break;
//    }
//}
//
//int evaluate_answer(int num1, int num2, char op) {
//    return (op == '+') ? num1 + num2 : num1 - num2; // ������������㲢���ؽ��
//}


//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[] = { 9,8,7,6,5,4,3,2,1 };
//	int temp[10];
//	int i = 0;
//	for (i = 0;i < 9;i++)
//	{
//		temp[i] = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp[i];
//	}
//	for (i = 0;i < 9;i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0;i < 9;i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

//void init(int arr[10])
//{
//	int i = 10;
//	for (i = 0;i < 10;i++)
//		arr[i] = 0;
//}
//
//void print(int arr[10])
//{
//	int i = 10;
//	for (i = 0;i < 10;i++)
//		printf("%d ", arr[i]);
//}
//
//void reverse(int arr1[10])
//{
//	int i = 0;
//		for (i = 0;i < 9;i++)
//		{
//			int j = 0;
//			for (j = 0;j < 9 - i;j++)
//			{
//				int tem = arr1[j];
//				arr1[j] = arr1[j+1];
//				arr1[j+1] = tem;
//			}
//		}
//}
//int main()
//{
//	int arr1[10] = {0,1,2,3,4,5,6,7,8,9};
//	int i = 0;
//	for (i = 0;i < 9;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 9 - i;j++)
//		{
//			int tem = arr1[j];
//			arr1[j] = arr1[j + 1];
//			arr1[j + 1] = tem;
//		}
//	}
//	for (i = 0;i < 10;i++)
//		printf("%d ", arr1[i]);
//	return 0;
//}


//srand((unsigned int ) time(NULL))



//int main()
//{
//	int a = 0;
//	int test = 1;
//	scanf_s("%d",&a);
//	int i = 0;
//	int count = 0;
//	for (i=1;i<=32;i++)
//	{
//		if (a & test == 1)
//			count++;
//		a = a >> 1;
//	}
//	printf("һ�ĸ���= %d ", count);
//	return 0;
//}
//
////
////srand((unsigned int)time(NULL));
////
//
//


//void reverse(int* px, int* py)
//{
//	int tmp = 0;
//	tmp = px;
//	px = py;
//	py = tmp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	reverse(&a, &b);
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}


//int main()
//{
//	double a = 1;
//	double * pa = &a;
//	*pa = 5;
//	printf("%d\n", sizeof(*pa));
//	return 0;
//}



//int main()
//{
//	int n = 0;
//	int i = 0;
//	int del = 0;
//	scanf_s("%d", &n);
//	int arr[50] = { 0 };
//	for (i = 0;i < n ; i++)
//	{
//		scanf_s("%d", &arr[i]);
//	}
//	scanf_s("%d", &del);
//	int j = 0;
//	for (i = 0;i < n; i++)
//	{
//		if (arr[i] != del)
//		{
//			arr[j] = arr[i];
//			j++;
//		}
//	}
//	if (j == i)
//		printf("���޴���");
//	else
//	{
//		for (i = 0;i < j; i++)
//			printf("%d ", arr[i]);
//	}
//
//	return 0;
//}




//int main()
//{
//	int i = 0;
//	int n = 0;
//	int arr[10000] = { 0 };
//	scanf_s("%d", &n);
//	for (i = 0;i < n-1; i++)
//		{
//			scanf_s("%d ", &arr[i]);
//		}
//	int max = arr[0];
//	int min = arr[0];
//	for (i = 1;i < n; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//
//	for (i = 1;i < n; i++)
//	{
//		if (arr[i] < min)
//			min = arr[i];
//	}
//	printf("%d ", max - min);
//	return 0;
//}
//int main()
//{
//	while (1)
//		printf("114514 ");
//	return 0;
//}



//int main()
//{
//	char ch = 0;
//	while (scanf_s("%c", &ch)==1)
//	{
//		if (ch >= 'a' && ch <= 'z')
//			printf("%c\n", ch - 32);
//		else if (ch >= 'A' && ch <= 'Z')
//			printf("%c\n", ch + 32);
//	}
//	return 0; 
//}


int main()
{
	int i = 0;
	int count = 0;
	int arr[999999] = { 0 };
	for (i = 10000;i <= 99999; i++)
	{
		if (i == (i / 10000) * (i % 10000) + (i / 1000) * (i % 1000) + (i / 100) * (i % 100) + (i / 10) * (i % 10))
			arr[count++] = i;
	}
	for (i = 0;i <= count;i++)
		printf("%d", arr[i]);
	return 0;
}
