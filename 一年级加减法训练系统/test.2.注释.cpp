#include <stdio.h> // 标准输入输出库，用于输入输出功能
#include <stdlib.h> // 标准库，用于随机数生成和其他通用功能
#include <time.h> // 时间库，用于设置随机数种子

#define MAX_QUESTIONS 100 // 定义考试模式中题目的最大数量

// 函数声明
void menu(); // 显示主菜单
void practice_mode(int type); // 练习模式
void exam_mode(int type); // 考试模式
void generate_question(int type, int *num1, int *num2, char *op); // 生成题目
int evaluate_answer(int num1, int num2, char op); // 计算答案

int main() {
    int choice, type; // choice存储用户选择的模式，type存储选择的题目类型

    srand(time(NULL)); // 使用当前时间设置随机数种子，确保每次运行题目随机

    while (1) { // 无限循环，直到用户选择退出
        menu(); // 显示菜单
        printf("\n请输入你的选择: ");
        scanf("%d", &choice); // 获取用户输入的选择

        if (choice == 3) { // 如果选择3，退出程序
            printf("系统退出，再见！\n");
            break;
        }

        printf("请选择题目类型:\n");
        printf("1. 十以内加减法\n");
        printf("2. 十几加几不进位\n");
        printf("3. 十几减几不退位\n");
        printf("4. 二十以内加减法\n");
        printf("请输入你的选择: ");
        scanf("%d", &type); // 获取用户输入的题目类型

        if (type < 1 || type > 4) { // 验证输入的题目类型是否有效
            printf("无效的题目类型！返回菜单。\n\n");
            continue; // 返回菜单
        }

        if (choice == 1) { // 如果选择练习模式
            practice_mode(type); // 进入练习模式
        } else if (choice == 2) { // 如果选择考试模式
            exam_mode(type); // 进入考试模式
        } else { // 如果选择无效
            printf("无效的模式！返回菜单。\n\n");
        }
    }

    return 0; // 程序正常退出
}

void menu() {
    // 显示主菜单
    printf("\n======= 心算训练系统 =======\n");
    printf("1. 练习模式\n");
    printf("2. 考试模式\n");
    printf("3. 退出\n");
    printf("==========================================\n");
}

void practice_mode(int type) {
    int num1, num2, user_answer, correct_answer; // 定义变量存储运算数、用户答案和正确答案
    char op; // 存储运算符

    printf("\n练习模式 - 共10题\n");

    for (int i = 0; i < 10; i++) { // 循环生成10道题目
        generate_question(type, &num1, &num2, &op); // 生成题目
        correct_answer = evaluate_answer(num1, num2, op); // 计算正确答案

        while (1) { // 循环直到用户输入正确答案
            printf("第%d题: %d %c %d = ", i + 1, num1, op, num2);
            scanf("%d", &user_answer); // 获取用户答案

            if (user_answer == correct_answer) { // 判断答案是否正确
                printf("正确！\n\n");
                break; // 跳出循环
            } else {
                printf("错误，请重试！\n"); // 提示用户重新答题
            }
        }
    }
}

void exam_mode(int type) {
    int num1, num2, user_answer, correct_answer; // 定义变量存储运算数、用户答案和正确答案
    char op; // 存储运算符
    int num_questions, correct_count = 0; // 题目数量和答对的题目数量

    printf("\n考试模式\n");
    printf("请输入题目数量: ");
    scanf("%d", &num_questions); // 获取用户输入的题目数量

    if (num_questions < 1 || num_questions > MAX_QUESTIONS) { // 验证题目数量是否有效
        printf("无效的题目数量！返回菜单。\n\n");
        return; // 返回菜单
    }

    int user_answers[num_questions]; // 存储用户的答案
    char results[num_questions]; // 存储每题的结果（对/错）
    int question_nums[num_questions][2]; // 存储每题的运算数
    char operators[num_questions]; // 存储每题的运算符

    for (int i = 0; i < num_questions; i++) { // 循环生成题目
        generate_question(type, &num1, &num2, &op); // 生成题目
        correct_answer = evaluate_answer(num1, num2, op); // 计算正确答案

        question_nums[i][0] = num1; // 保存第一个运算数
        question_nums[i][1] = num2; // 保存第二个运算数
        operators[i] = op; // 保存运算符

        printf("第%d题: %d %c %d = ", i + 1, num1, op, num2);
        scanf("%d", &user_answer); // 获取用户答案

        user_answers[i] = user_answer; // 保存用户答案

        if (user_answer == correct_answer) { // 判断答案是否正确
            results[i] = '√'; // 正确标记
            correct_count++; // 正确计数加1
        } else {
            results[i] = 'X'; // 错误标记
        }
    }

    printf("\n考试结果:\n");
    for (int i = 0; i < num_questions; i++) { // 打印每题的结果
        printf("第%d题: %d %c %d = %d (%c)\n", i + 1, question_nums[i][0], operators[i], question_nums[i][1], user_answers[i], results[i]);
    }

    printf("\n正确题数: %d/%d\n", correct_count, num_questions); // 打印正确题数
    printf("正确率: %.2f%%\n\n", (correct_count / (float)num_questions) * 100); // 打印正确率
}

void generate_question(int type, int *num1, int *num2, char *op) {
    *op = (rand() % 2 == 0) ? '+' : '-'; // 随机生成加法或减法

    switch (type) {
        case 1: // 十以内加减法
            *num1 = rand() % 10 + 1; // 随机生成1到10的数
            *num2 = rand() % 10 + 1; // 随机生成1到10的数
            if (*op == '-' && *num1 < *num2) { // 如果是减法且第一个数小于第二个数
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp; // 交换两个数以确保结果为正数
            }
            break;

        case 2: // 十几加几不进位
            *num1 = rand() % 9 + 11; // 生成11到19的数
            *num2 = rand() % (10 - (*num1 % 10)); // 生成个位数，使其不进位
            if (rand() % 2 == 0) { // 随机交换位置
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp;
            }
            *op = '+'; // 确保是加法
            break;

        case 3: // 十几减几不退位
            *num1 = rand() % 9 + 11; // 生成11到19的数
            *num2 = rand() % ((*num1 % 10) + 1); // 生成个位数，使其不退位
            *op = '-'; // 确保是减法
            break;

        case 4: // 二十以内加减法
            *num1 = rand() % 20 + 1; // 生成1到20的数
            *num2 = rand() % 20 + 1; // 生成1到20的数
            if (*op == '-' && *num1 < *num2) { // 如果是减法且第一个数小于第二个数
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp; // 交换两个数以确保结果为正数
            }
            break;
    }
}

int evaluate_answer(int num1, int num2, char op) {
    return (op == '+') ? num1 + num2 : num1 - num2; // 根据运算符计算并返回结果
}
