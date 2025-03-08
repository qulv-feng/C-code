#include <stdio.h> // ��׼��������⣬���������������
#include <stdlib.h> // ��׼�⣬������������ɺ�����ͨ�ù���
#include <time.h> // ʱ��⣬�����������������

#define MAX_QUESTIONS 100 // ���忼��ģʽ����Ŀ���������

// ��������
void menu(); // ��ʾ���˵�
void practice_mode(int type); // ��ϰģʽ
void exam_mode(int type); // ����ģʽ
void generate_question(int type, int *num1, int *num2, char *op); // ������Ŀ
int evaluate_answer(int num1, int num2, char op); // �����

int main() {
    int choice, type; // choice�洢�û�ѡ���ģʽ��type�洢ѡ�����Ŀ����

    srand(time(NULL)); // ʹ�õ�ǰʱ��������������ӣ�ȷ��ÿ��������Ŀ���

    while (1) { // ����ѭ����ֱ���û�ѡ���˳�
        menu(); // ��ʾ�˵�
        printf("\n���������ѡ��: ");
        scanf("%d", &choice); // ��ȡ�û������ѡ��

        if (choice == 3) { // ���ѡ��3���˳�����
            printf("ϵͳ�˳����ټ���\n");
            break;
        }

        printf("��ѡ����Ŀ����:\n");
        printf("1. ʮ���ڼӼ���\n");
        printf("2. ʮ���Ӽ�����λ\n");
        printf("3. ʮ����������λ\n");
        printf("4. ��ʮ���ڼӼ���\n");
        printf("���������ѡ��: ");
        scanf("%d", &type); // ��ȡ�û��������Ŀ����

        if (type < 1 || type > 4) { // ��֤�������Ŀ�����Ƿ���Ч
            printf("��Ч����Ŀ���ͣ����ز˵���\n\n");
            continue; // ���ز˵�
        }

        if (choice == 1) { // ���ѡ����ϰģʽ
            practice_mode(type); // ������ϰģʽ
        } else if (choice == 2) { // ���ѡ����ģʽ
            exam_mode(type); // ���뿼��ģʽ
        } else { // ���ѡ����Ч
            printf("��Ч��ģʽ�����ز˵���\n\n");
        }
    }

    return 0; // ���������˳�
}

void menu() {
    // ��ʾ���˵�
    printf("\n======= ����ѵ��ϵͳ =======\n");
    printf("1. ��ϰģʽ\n");
    printf("2. ����ģʽ\n");
    printf("3. �˳�\n");
    printf("==========================================\n");
}

void practice_mode(int type) {
    int num1, num2, user_answer, correct_answer; // ��������洢���������û��𰸺���ȷ��
    char op; // �洢�����

    printf("\n��ϰģʽ - ��10��\n");

    for (int i = 0; i < 10; i++) { // ѭ������10����Ŀ
        generate_question(type, &num1, &num2, &op); // ������Ŀ
        correct_answer = evaluate_answer(num1, num2, op); // ������ȷ��

        while (1) { // ѭ��ֱ���û�������ȷ��
            printf("��%d��: %d %c %d = ", i + 1, num1, op, num2);
            scanf("%d", &user_answer); // ��ȡ�û���

            if (user_answer == correct_answer) { // �жϴ��Ƿ���ȷ
                printf("��ȷ��\n\n");
                break; // ����ѭ��
            } else {
                printf("���������ԣ�\n"); // ��ʾ�û����´���
            }
        }
    }
}

void exam_mode(int type) {
    int num1, num2, user_answer, correct_answer; // ��������洢���������û��𰸺���ȷ��
    char op; // �洢�����
    int num_questions, correct_count = 0; // ��Ŀ�����ʹ�Ե���Ŀ����

    printf("\n����ģʽ\n");
    printf("��������Ŀ����: ");
    scanf("%d", &num_questions); // ��ȡ�û��������Ŀ����

    if (num_questions < 1 || num_questions > MAX_QUESTIONS) { // ��֤��Ŀ�����Ƿ���Ч
        printf("��Ч����Ŀ���������ز˵���\n\n");
        return; // ���ز˵�
    }

    int user_answers[num_questions]; // �洢�û��Ĵ�
    char results[num_questions]; // �洢ÿ��Ľ������/��
    int question_nums[num_questions][2]; // �洢ÿ���������
    char operators[num_questions]; // �洢ÿ��������

    for (int i = 0; i < num_questions; i++) { // ѭ��������Ŀ
        generate_question(type, &num1, &num2, &op); // ������Ŀ
        correct_answer = evaluate_answer(num1, num2, op); // ������ȷ��

        question_nums[i][0] = num1; // �����һ��������
        question_nums[i][1] = num2; // ����ڶ���������
        operators[i] = op; // ���������

        printf("��%d��: %d %c %d = ", i + 1, num1, op, num2);
        scanf("%d", &user_answer); // ��ȡ�û���

        user_answers[i] = user_answer; // �����û���

        if (user_answer == correct_answer) { // �жϴ��Ƿ���ȷ
            results[i] = '��'; // ��ȷ���
            correct_count++; // ��ȷ������1
        } else {
            results[i] = 'X'; // ������
        }
    }

    printf("\n���Խ��:\n");
    for (int i = 0; i < num_questions; i++) { // ��ӡÿ��Ľ��
        printf("��%d��: %d %c %d = %d (%c)\n", i + 1, question_nums[i][0], operators[i], question_nums[i][1], user_answers[i], results[i]);
    }

    printf("\n��ȷ����: %d/%d\n", correct_count, num_questions); // ��ӡ��ȷ����
    printf("��ȷ��: %.2f%%\n\n", (correct_count / (float)num_questions) * 100); // ��ӡ��ȷ��
}

void generate_question(int type, int *num1, int *num2, char *op) {
    *op = (rand() % 2 == 0) ? '+' : '-'; // ������ɼӷ������

    switch (type) {
        case 1: // ʮ���ڼӼ���
            *num1 = rand() % 10 + 1; // �������1��10����
            *num2 = rand() % 10 + 1; // �������1��10����
            if (*op == '-' && *num1 < *num2) { // ����Ǽ����ҵ�һ����С�ڵڶ�����
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp; // ������������ȷ�����Ϊ����
            }
            break;

        case 2: // ʮ���Ӽ�����λ
            *num1 = rand() % 9 + 11; // ����11��19����
            *num2 = rand() % (10 - (*num1 % 10)); // ���ɸ�λ����ʹ�䲻��λ
            if (rand() % 2 == 0) { // �������λ��
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp;
            }
            *op = '+'; // ȷ���Ǽӷ�
            break;

        case 3: // ʮ����������λ
            *num1 = rand() % 9 + 11; // ����11��19����
            *num2 = rand() % ((*num1 % 10) + 1); // ���ɸ�λ����ʹ�䲻��λ
            *op = '-'; // ȷ���Ǽ���
            break;

        case 4: // ��ʮ���ڼӼ���
            *num1 = rand() % 20 + 1; // ����1��20����
            *num2 = rand() % 20 + 1; // ����1��20����
            if (*op == '-' && *num1 < *num2) { // ����Ǽ����ҵ�һ����С�ڵڶ�����
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp; // ������������ȷ�����Ϊ����
            }
            break;
    }
}

int evaluate_answer(int num1, int num2, char op) {
    return (op == '+') ? num1 + num2 : num1 - num2; // ������������㲢���ؽ��
}
