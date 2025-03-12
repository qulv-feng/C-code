#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// =============================
// 1. 字符串大小写转换函数
// =============================
// 功能:
// - 将字符串中的字母进行大小写转换
//   - 小写变为大写
//   - 大写变为小写
// 参数:
// - str: 输入的字符串，直接在原字符串上进行修改
// 返回值:
// - 无
void str_toggle_case(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) { // 如果是小写字母
            str[i] = toupper(str[i]); // 转换为大写
        } else if (isupper(str[i])) { // 如果是大写字母
            str[i] = tolower(str[i]); // 转换为小写
        }
    }
}

// =============================
// 2. 字符串比较函数
// =============================
// 功能:
// - 比较两个字符串的大小，基于ASCII码值
// 参数:
// - str1: 第一个字符串
// - str2: 第二个字符串
// 返回值:
// - 0: 两个字符串相等
// - 正数: 第一个字符串大于第二个字符串
// - 负数: 第一个字符串小于第二个字符串
int str_compare(const char *str1, const char *str2) {
    return strcmp(str1, str2); // 调用标准库函数
}

// =============================
// 3. 检查字符串是否为回文函数
// =============================
// 功能:
// - 判断一个字符串是否是回文
//   - 回文的定义: 从左到右和从右到左字符顺序完全相同
// 参数:
// - str: 输入的字符串
// 返回值:
// - 1: 是回文
// - 0: 不是回文
int is_palindrome(const char *str) {
    int len = strlen(str); // 获取字符串长度
    for (int i = 0; i < len / 2; i++) { // 只需比较前一半和后一半字符
        if (str[i] != str[len - i - 1]) { // 左右字符不相等
            return 0; // 不是回文
        }
    }
    return 1; // 是回文
}

// =============================
// 4. 检查字符串是否为数字串函数
// =============================
// 功能:
// - 判断字符串是否只由数字字符组成
// 参数:
// - str: 输入的字符串
// 返回值:
// - 1: 是数字串
// - 0: 不是数字串
int is_numeric(const char *str) {
    if (*str == '\0') return 0; // 空字符串不是数字串
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) { // 遇到非数字字符
            return 0; // 不是数字串
        }
    }
    return 1; // 是数字串
}

// =============================
// 5. 大数加减法运算函数
// =============================
// 功能:
// - 实现两个大整数的加法或减法运算
// 参数:
// - num1: 第一个大整数，字符串形式
// - num2: 第二个大整数，字符串形式
// - op: 操作符 ('+' 表示加法, '-' 表示减法)
// 返回值:
// - 结果字符串 (动态分配内存，需手动释放)
// 注意:
// - 如果输入的字符串不是数字串，会直接退出程序
char* big_number_calculator(const char *num1, const char *num2, char op) {
    // 检查输入是否为数字串
    if (!is_numeric(num1) || !is_numeric(num2)) {
        printf("输入的字符串不是数字串，程序退出！\n");
        exit(EXIT_FAILURE);
    }

    int len1 = strlen(num1); // 第一个数字的长度
    int len2 = strlen(num2); // 第二个数字的长度
    int max_len = (len1 > len2 ? len1 : len2) + 2; // 预留额外空间存放进位、符号和结束符

    char *result = (char *)malloc(max_len * sizeof(char)); // 动态分配内存存储结果
    memset(result, 0, max_len); // 初始化内存

    int carry = 0, i = len1 - 1, j = len2 - 1, k = max_len - 2; // carry 为进位，i 和 j 分别是 num1 和 num2 的索引
    int borrow = 0; // 用于减法的借位
    int negative = 0; // 标记结果是否为负数

    if (op == '+') {
        // 加法运算逻辑
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0; // 从右向左取 num1 当前位
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0; // 从右向左取 num2 当前位

            int sum = digit1 + digit2 + carry; // 当前位相加
            result[k--] = (sum % 10) + '0'; // 结果存储到字符串
            carry = sum / 10; // 计算进位
        }
    } else if (op == '-') {
        // 判断是否需要交换操作数（确保大数减法正确）
        if (len1 < len2 || (len1 == len2 && strcmp(num1, num2) < 0)) {
            const char *temp = num1; // 交换 num1 和 num2
            num1 = num2;
            num2 = temp;
            int temp_len = len1; // 同时交换长度
            len1 = len2;
            len2 = temp_len;
            negative = 1; // 结果为负数
        }

        i = len1 - 1;
        j = len2 - 1;

        // 减法运算逻辑
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
            result[k--] = diff + '0'; // 存储结果
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
        return result + k; // 返回结果指针
    } else {
        return result + k + 1; // 跳过多余的前导零
    }
}

// =============================
// 菜单显示函数
// =============================
// 功能:
// - 显示功能菜单
void display_menu() {
    printf("\n===== 功能菜单 =====\n");
    printf("1. 字符串大小写转换\n");
    printf("2. 字符串比较\n");
    printf("3. 检查字符串是否为回文\n");
    printf("4. 检查字符串是否为数字串\n");
    printf("5. 大数加法运算\n");
    printf("6. 退出程序\n");
}

// =============================
// 主函数: 程序入口
// =============================
int main() {
    int choice;
    char str1[100], str2[100], op;

    while (1) {
        display_menu(); // 显示菜单
        printf("请选择功能 (1-6): ");
        scanf("%d", &choice); // 读取用户选择

        switch (choice) {
            case 1: // 字符串大小写转换
                printf("请输入字符串: ");
                scanf("%s", str1);
                str_toggle_case(str1);
                printf("转换后的字符串: %s\n", str1);
                break;

            case 2: // 字符串比较
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

            case 3: // 检查是否为回文
                printf("请输入字符串: ");
                scanf("%s", str1);
                if (is_palindrome(str1))
                    printf("该字符串是回文！\n");
                else
                    printf("该字符串不是回文！\n");
                break;

            case 4: // 检查是否为数字串
                printf("请输入字符串: ");
                scanf("%s", str1);
                if (is_numeric(str1))
                    printf("该字符串是数字串！\n");
                else
                    printf("该字符串不是数字串！\n");
                break;

            case 5: // 大数加法运算
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

            case 6: // 退出程序
                printf("退出程序！\n");
                return 0;

            default:
                printf("无效选择，请重新输入！\n");
        }
    }
    return 0;
}
