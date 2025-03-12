#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// 1. 字符串大小写转换函数
void str_toggle_case(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

// 2. 字符串比较函数
int str_compare(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

// 3. 检查字符串是否为回文函数
int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // 不是回文
        }
    }
    return 1; // 是回文
}

// 4. 检查字符串是否为数字串函数
int is_numeric(const char *str) {
    if (*str == '\0') return 0; // 空字符串不是数字串
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // 不是数字串
        }
    }
    return 1; // 是数字串
}

// 5. 大数加减法运算函数
char* big_number_calculator(const char *num1, const char *num2, char op) {
    // 检查是否为数字串
    if (!is_numeric(num1) || !is_numeric(num2)) {
        printf("输入的字符串不是数字串，程序退出！\n");
        exit(EXIT_FAILURE);
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int max_len = (len1 > len2 ? len1 : len2) + 2; // 额外空间存放进位、借位和结束符

    char *result = (char *)malloc(max_len * sizeof(char));
    memset(result, 0, max_len);

    int carry = 0, i = len1 - 1, j = len2 - 1, k = max_len - 2;
    int borrow = 0; // 用于减法的借位
    int negative = 0; // 结果是否为负数的标志

    if (op == '+') {
        // 实现加法运算
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            result[k--] = (sum % 10) + '0';
            carry = sum / 10;
        }
    } else if (op == '-') {
        // 判断是否需要交换操作数（确保大数减法正确）
        if (len1 < len2 || (len1 == len2 && strcmp(num1, num2) < 0)) {
            const char *temp = num1;
            num1 = num2;
            num2 = temp;
            int temp_len = len1;
            len1 = len2;
            len2 = temp_len;
            negative = 1; // 结果为负
        }

        i = len1 - 1;
        j = len2 - 1;

        // 实现减法运算
        while (i >= 0 || j >= 0 || borrow) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

            int diff = digit1 - digit2 + borrow;
            if (diff < 0) {
                diff += 10; // 借位
                borrow = -1;
            } else {
                borrow = 0;
            }
            result[k--] = diff + '0';
        }
    } else {
        printf("不支持的操作符！\n");
        free(result);
        return NULL;
    }

    // 去除结果中的前导零
    while (k < max_len - 2 && result[k + 1] == '0') {
        k++;
    }

    // 如果是负数结果，在前面加上负号
    if (negative) {
        result[k] = '-';
        return result + k; // 返回结果的指针
    } else {
        return result + k + 1; // 跳过多余的前导零
    }
}


// 功能菜单
void display_menu() {
    printf("\n===== 功能菜单 =====\n");
    printf("1. 字符串大小写转换\n");
    printf("2. 字符串比较\n");
    printf("3. 检查字符串是否为回文\n");
    printf("4. 检查字符串是否为数字串\n");
    printf("5. 大数加法运算\n");
    printf("6. 退出程序\n");
}

int main() {
    int choice;
    char str1[100], str2[100], op;

    while (1) {
        display_menu();
        printf("请选择功能 (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("请输入字符串: ");
                scanf("%s", str1);
                str_toggle_case(str1);
                printf("转换后的字符串: %s\n", str1);
                break;

            case 2:
                printf("请输入第一个字符串: ");
                scanf("%s", str1);
                printf("请输入第二个字符串: ");
                scanf("%s", str2);
                int cmp_result = str_compare(str1, str2);
                if (cmp_result == 0)
                    printf("两个字符串相等\n");
                else if (cmp_result > 0)
                    printf("第一个字符串大于第二个字符串\n");
                else
                    printf("第一个字符串小于第二个字符串\n");
                break;

            case 3:
                printf("请输入字符串: ");
                scanf("%s", str1);
                if (is_palindrome(str1))
                    printf("该字符串是回文！\n");
                else
                    printf("该字符串不是回文！\n");
                break;

            case 4:
                printf("请输入字符串: ");
                scanf("%s", str1);
                if (is_numeric(str1))
                    printf("该字符串是数字串！\n");
                else
                    printf("该字符串不是数字串！\n");
                break;

            case 5:
                printf("请输入第一个数字串: ");
                scanf("%s", str1);
                printf("请输入第二个数字串: ");
                scanf("%s", str2);
                printf("请输入操作符 (+ 或 -): ");
                scanf(" %c", &op);
                char *result = big_number_calculator(str1, str2, op);
                if (result) {
                    printf("计算结果: %s\n", result);
                    free(result - 1); // 释放内存
                }
                break;

            case 6:
                printf("退出程序！\n");
                return 0;

            default:
                printf("无效选择，请重新输入！\n");
        }
    }
    return 0;
}
