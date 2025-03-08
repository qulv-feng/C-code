#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100

// 函数声明
void menu();
void practice_mode(int type);
void exam_mode(int type);
void generate_question(int type, int *num1, int *num2, char *op);
int evaluate_answer(int num1, int num2, char op);

int main() {
    int choice, type;
    
    srand(time(NULL)); // 随机数种子

    while (1) {
        menu();
        printf("\n请输入你的选择: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("系统退出，再见！\n");
            break;
        }

        printf("请选择题目类型:\n");
        printf("1. 十以内加减法\n");
        printf("2. 十几加几不进位\n");
        printf("3. 十几减几不退位\n");
        printf("4. 二十以内加减法\n");
        printf("请输入你的选择: ");
        scanf("%d", &type);

        if (type < 1 || type > 4) {
            printf("无效的题目类型！返回菜单。\n\n");
            continue;
        }

        if (choice == 1) {
            practice_mode(type);
        } else if (choice == 2) {
            exam_mode(type);
        } else {
            printf("无效的模式！返回菜单。\n\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n======= 一年级加减法训练系统 =======\n");
    printf("1. 练习模式\n");
    printf("2. 考试模式\n");
    printf("3. 退出\n");
    printf("==========================================\n");
}

void practice_mode(int type) {
    int num1, num2, user_answer, correct_answer;
    char op;

    printf("\n练习模式 - 共10题\n");

    for (int i = 0; i < 10; i++) {
        generate_question(type, &num1, &num2, &op);
        correct_answer = evaluate_answer(num1, num2, op);

        while (1) {
            printf("第%d题: %d %c %d = ", i + 1, num1, op, num2);
            scanf("%d", &user_answer);

            if (user_answer == correct_answer) {
                printf("正确！\n\n");
                break;
            } else {
                printf("错误，请重试！\n");
            }
        }
    }
}

void exam_mode(int type) {
    int num1, num2, user_answer, correct_answer;
    char op;
    int num_questions, correct_count = 0;

    printf("\n考试模式\n");
    printf("请输入题目数量: ");
    scanf("%d", &num_questions);

    if (num_questions < 1 || num_questions > MAX_QUESTIONS) {
        printf("无效的题目数量！返回菜单。\n\n");
        return;
    }

    int user_answers[num_questions];
    char results[num_questions];
    int question_nums[num_questions][2];
    char operators[num_questions];

    for (int i = 0; i < num_questions; i++) {
        generate_question(type, &num1, &num2, &op);
        correct_answer = evaluate_answer(num1, num2, op);

        question_nums[i][0] = num1;
        question_nums[i][1] = num2;
        operators[i] = op;

        printf("第%d题: %d %c %d = ", i + 1, num1, op, num2);
        scanf("%d", &user_answer);

        user_answers[i] = user_answer;

        if (user_answer == correct_answer) {
            results[i] = '√';
            correct_count++;
        } else {
            results[i] = 'X';
        }
    }

    printf("\n考试结果:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("第%d题: %d %c %d = %d (%c)\n", i + 1, question_nums[i][0], operators[i], question_nums[i][1], user_answers[i], results[i]);
    }

    printf("\n正确题数: %d/%d\n", correct_count, num_questions);
    printf("正确率: %.2f%%\n\n", (correct_count / (float)num_questions) * 100);
}

void generate_question(int type, int *num1, int *num2, char *op) {
    *op = (rand() % 2 == 0) ? '+' : '-';

    switch (type) {
        case 1: // 十以内加减法
            *num1 = rand() % 10 + 1;
            *num2 = rand() % 10 + 1;
            if (*op == '-' && *num1 < *num2) {
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp;
            }
            break;

        case 2: // 十几加几不进位
            *num1 = rand() % 9 + 11; // 11到19
            *num2 = rand() % (10 - (*num1 % 10));
            if (rand() % 2 == 0) {
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp;
            }
            *op = '+';
            break;

        case 3: // 十几减几不退位
            *num1 = rand() % 9 + 11; // 11到19
            *num2 = rand() % ((*num1 % 10) + 1);
            *op = '-';
            break;

        case 4: // 二十以内加减法
            *num1 = rand() % 20 + 1;
            *num2 = rand() % 20 + 1;
            if (*op == '-' && *num1 < *num2) {
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp;
            }
            break;
    }
}

int evaluate_answer(int num1, int num2, char op) {
    return (op == '+') ? num1 + num2 : num1 - num2;
}
