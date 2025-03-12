#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100

// ��������
void menu();
void practice_mode(int type);
void exam_mode(int type);
void generate_question(int type, int *num1, int *num2, char *op);
int evaluate_answer(int num1, int num2, char op);

int main() {
    int choice, type;
    
    srand(time(NULL)); // ���������

    while (1) {
        menu();
        printf("\n���������ѡ��: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("ϵͳ�˳����ټ���\n");
            break;
        }

        printf("��ѡ����Ŀ����:\n");
        printf("1. ʮ���ڼӼ���\n");
        printf("2. ʮ���Ӽ�����λ\n");
        printf("3. ʮ����������λ\n");
        printf("4. ��ʮ���ڼӼ���\n");
        printf("���������ѡ��: ");
        scanf("%d", &type);

        if (type < 1 || type > 4) {
            printf("��Ч����Ŀ���ͣ����ز˵���\n\n");
            continue;
        }

        if (choice == 1) {
            practice_mode(type);
        } else if (choice == 2) {
            exam_mode(type);
        } else {
            printf("��Ч��ģʽ�����ز˵���\n\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n======= һ�꼶�Ӽ���ѵ��ϵͳ =======\n");
    printf("1. ��ϰģʽ\n");
    printf("2. ����ģʽ\n");
    printf("3. �˳�\n");
    printf("==========================================\n");
}

void practice_mode(int type) {
    int num1, num2, user_answer, correct_answer;
    char op;

    printf("\n��ϰģʽ - ��10��\n");

    for (int i = 0; i < 10; i++) {
        generate_question(type, &num1, &num2, &op);
        correct_answer = evaluate_answer(num1, num2, op);

        while (1) {
            printf("��%d��: %d %c %d = ", i + 1, num1, op, num2);
            scanf("%d", &user_answer);

            if (user_answer == correct_answer) {
                printf("��ȷ��\n\n");
                break;
            } else {
                printf("���������ԣ�\n");
            }
        }
    }
}

void exam_mode(int type) {
    int num1, num2, user_answer, correct_answer;
    char op;
    int num_questions, correct_count = 0;

    printf("\n����ģʽ\n");
    printf("��������Ŀ����: ");
    scanf("%d", &num_questions);

    if (num_questions < 1 || num_questions > MAX_QUESTIONS) {
        printf("��Ч����Ŀ���������ز˵���\n\n");
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

        printf("��%d��: %d %c %d = ", i + 1, num1, op, num2);
        scanf("%d", &user_answer);

        user_answers[i] = user_answer;

        if (user_answer == correct_answer) {
            results[i] = '��';
            correct_count++;
        } else {
            results[i] = 'X';
        }
    }

    printf("\n���Խ��:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("��%d��: %d %c %d = %d (%c)\n", i + 1, question_nums[i][0], operators[i], question_nums[i][1], user_answers[i], results[i]);
    }

    printf("\n��ȷ����: %d/%d\n", correct_count, num_questions);
    printf("��ȷ��: %.2f%%\n\n", (correct_count / (float)num_questions) * 100);
}

void generate_question(int type, int *num1, int *num2, char *op) {
    *op = (rand() % 2 == 0) ? '+' : '-';

    switch (type) {
        case 1: // ʮ���ڼӼ���
            *num1 = rand() % 10 + 1;
            *num2 = rand() % 10 + 1;
            if (*op == '-' && *num1 < *num2) {
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp;
            }
            break;

        case 2: // ʮ���Ӽ�����λ
            *num1 = rand() % 9 + 11; // 11��19
            *num2 = rand() % (10 - (*num1 % 10));
            if (rand() % 2 == 0) {
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp;
            }
            *op = '+';
            break;

        case 3: // ʮ����������λ
            *num1 = rand() % 9 + 11; // 11��19
            *num2 = rand() % ((*num1 % 10) + 1);
            *op = '-';
            break;

        case 4: // ��ʮ���ڼӼ���
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
