#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// =============================
// 1. �ַ�����Сдת������
// =============================
// ����:
// - ���ַ����е���ĸ���д�Сдת��
//   - Сд��Ϊ��д
//   - ��д��ΪСд
// ����:
// - str: ������ַ�����ֱ����ԭ�ַ����Ͻ����޸�
// ����ֵ:
// - ��
void str_toggle_case(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) { // �����Сд��ĸ
            str[i] = toupper(str[i]); // ת��Ϊ��д
        } else if (isupper(str[i])) { // ����Ǵ�д��ĸ
            str[i] = tolower(str[i]); // ת��ΪСд
        }
    }
}

// =============================
// 2. �ַ����ȽϺ���
// =============================
// ����:
// - �Ƚ������ַ����Ĵ�С������ASCII��ֵ
// ����:
// - str1: ��һ���ַ���
// - str2: �ڶ����ַ���
// ����ֵ:
// - 0: �����ַ������
// - ����: ��һ���ַ������ڵڶ����ַ���
// - ����: ��һ���ַ���С�ڵڶ����ַ���
int str_compare(const char *str1, const char *str2) {
    return strcmp(str1, str2); // ���ñ�׼�⺯��
}

// =============================
// 3. ����ַ����Ƿ�Ϊ���ĺ���
// =============================
// ����:
// - �ж�һ���ַ����Ƿ��ǻ���
//   - ���ĵĶ���: �����Һʹ��ҵ����ַ�˳����ȫ��ͬ
// ����:
// - str: ������ַ���
// ����ֵ:
// - 1: �ǻ���
// - 0: ���ǻ���
int is_palindrome(const char *str) {
    int len = strlen(str); // ��ȡ�ַ�������
    for (int i = 0; i < len / 2; i++) { // ֻ��Ƚ�ǰһ��ͺ�һ���ַ�
        if (str[i] != str[len - i - 1]) { // �����ַ������
            return 0; // ���ǻ���
        }
    }
    return 1; // �ǻ���
}

// =============================
// 4. ����ַ����Ƿ�Ϊ���ִ�����
// =============================
// ����:
// - �ж��ַ����Ƿ�ֻ�������ַ����
// ����:
// - str: ������ַ���
// ����ֵ:
// - 1: �����ִ�
// - 0: �������ִ�
int is_numeric(const char *str) {
    if (*str == '\0') return 0; // ���ַ����������ִ�
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) { // �����������ַ�
            return 0; // �������ִ�
        }
    }
    return 1; // �����ִ�
}

// =============================
// 5. �����Ӽ������㺯��
// =============================
// ����:
// - ʵ�������������ļӷ����������
// ����:
// - num1: ��һ�����������ַ�����ʽ
// - num2: �ڶ������������ַ�����ʽ
// - op: ������ ('+' ��ʾ�ӷ�, '-' ��ʾ����)
// ����ֵ:
// - ����ַ��� (��̬�����ڴ棬���ֶ��ͷ�)
// ע��:
// - ���������ַ����������ִ�����ֱ���˳�����
char* big_number_calculator(const char *num1, const char *num2, char op) {
    // ��������Ƿ�Ϊ���ִ�
    if (!is_numeric(num1) || !is_numeric(num2)) {
        printf("������ַ����������ִ��������˳���\n");
        exit(EXIT_FAILURE);
    }

    int len1 = strlen(num1); // ��һ�����ֵĳ���
    int len2 = strlen(num2); // �ڶ������ֵĳ���
    int max_len = (len1 > len2 ? len1 : len2) + 2; // Ԥ������ռ��Ž�λ�����źͽ�����

    char *result = (char *)malloc(max_len * sizeof(char)); // ��̬�����ڴ�洢���
    memset(result, 0, max_len); // ��ʼ���ڴ�

    int carry = 0, i = len1 - 1, j = len2 - 1, k = max_len - 2; // carry Ϊ��λ��i �� j �ֱ��� num1 �� num2 ������
    int borrow = 0; // ���ڼ����Ľ�λ
    int negative = 0; // ��ǽ���Ƿ�Ϊ����

    if (op == '+') {
        // �ӷ������߼�
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0; // ��������ȡ num1 ��ǰλ
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0; // ��������ȡ num2 ��ǰλ

            int sum = digit1 + digit2 + carry; // ��ǰλ���
            result[k--] = (sum % 10) + '0'; // ����洢���ַ���
            carry = sum / 10; // �����λ
        }
    } else if (op == '-') {
        // �ж��Ƿ���Ҫ������������ȷ������������ȷ��
        if (len1 < len2 || (len1 == len2 && strcmp(num1, num2) < 0)) {
            const char *temp = num1; // ���� num1 �� num2
            num1 = num2;
            num2 = temp;
            int temp_len = len1; // ͬʱ��������
            len1 = len2;
            len2 = temp_len;
            negative = 1; // ���Ϊ����
        }

        i = len1 - 1;
        j = len2 - 1;

        // ���������߼�
        while (i >= 0 || j >= 0 || borrow) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

            int diff = digit1 - digit2 + borrow;
            if (diff < 0) {
                diff += 10; // ��λ
                borrow = -1;
            } else {
                borrow = 0;
            }
            result[k--] = diff + '0'; // �洢���
        }
    } else {
        printf("��֧�ֵĲ�������\n");
        free(result);
        return NULL;
    }

    // ȥ������е�ǰ����
    while (k < max_len - 2 && result[k + 1] == '0') {
        k++;
    }

    // ����Ǹ����������ǰ����ϸ���
    if (negative) {
        result[k] = '-';
        return result + k; // ���ؽ��ָ��
    } else {
        return result + k + 1; // ���������ǰ����
    }
}

// =============================
// �˵���ʾ����
// =============================
// ����:
// - ��ʾ���ܲ˵�
void display_menu() {
    printf("\n===== ���ܲ˵� =====\n");
    printf("1. �ַ�����Сдת��\n");
    printf("2. �ַ����Ƚ�\n");
    printf("3. ����ַ����Ƿ�Ϊ����\n");
    printf("4. ����ַ����Ƿ�Ϊ���ִ�\n");
    printf("5. �����ӷ�����\n");
    printf("6. �˳�����\n");
}

// =============================
// ������: �������
// =============================
int main() {
    int choice;
    char str1[100], str2[100], op;

    while (1) {
        display_menu(); // ��ʾ�˵�
        printf("��ѡ���� (1-6): ");
        scanf("%d", &choice); // ��ȡ�û�ѡ��

        switch (choice) {
            case 1: // �ַ�����Сдת��
                printf("�������ַ���: ");
                scanf("%s", str1);
                str_toggle_case(str1);
                printf("ת������ַ���: %s\n", str1);
                break;

            case 2: // �ַ����Ƚ�
                printf("�������һ���ַ���: ");
                scanf("%s", str1);
                printf("������ڶ����ַ���: ");
                scanf("%s", str2);
                int cmp_result = str_compare(str1, str2);
                if (cmp_result == 0)
                    printf("�����ַ������\n");
                else if (cmp_result > 0)
                    printf("��һ���ַ������ڵڶ����ַ���\n");
                else
                    printf("��һ���ַ���С�ڵڶ����ַ���\n");
                break;

            case 3: // ����Ƿ�Ϊ����
                printf("�������ַ���: ");
                scanf("%s", str1);
                if (is_palindrome(str1))
                    printf("���ַ����ǻ��ģ�\n");
                else
                    printf("���ַ������ǻ��ģ�\n");
                break;

            case 4: // ����Ƿ�Ϊ���ִ�
                printf("�������ַ���: ");
                scanf("%s", str1);
                if (is_numeric(str1))
                    printf("���ַ��������ִ���\n");
                else
                    printf("���ַ����������ִ���\n");
                break;

            case 5: // �����ӷ�����
                printf("�������һ�����ִ�: ");
                scanf("%s", str1);
                printf("������ڶ������ִ�: ");
                scanf("%s", str2);
                printf("����������� (+ �� -): ");
                scanf(" %c", &op);
                char *result = big_number_calculator(str1, str2, op);
                if (result) {
                    printf("������: %s\n", result);
                    free(result - 1); // �ͷ��ڴ�
                }
                break;

            case 6: // �˳�����
                printf("�˳�����\n");
                return 0;

            default:
                printf("��Чѡ�����������룡\n");
        }
    }
    return 0;
}
