#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Student {
    char id[20];
    char name[50];
    int year;
    int month;
    int day;
    float scores[4];
    float total;
    float average;
    struct Student* next;
} Student;

Student* head = NULL;

int login() {
    char username[50], password[50];
    int attempts = 0;
    FILE* fp = fopen("users.txt", "r");

    if (!fp) {
        printf("ϵͳ�����û��ļ������ڣ�\n");
        return 0;
    }

    char file_user[50], file_pass[50];
    fscanf(fp, "%s %s", file_user, file_pass);
    fclose(fp);

    while (attempts < 3) {
        printf("\n�û���¼\n");
        printf("�û���: ");
        scanf("%s", username);
        printf("����: ");
        scanf("%s", password);

        if (strcmp(username, file_user) == 0 && strcmp(password, file_pass) == 0) {
            return 1;
        }
        else {
            printf("�û������������ʣ�ೢ�Դ�����%d\n", 2 - attempts);
            attempts++;
        }
    }
    return 0;
}

void add_student() {
    Student* new_node = (Student*)malloc(sizeof(Student));
    Student* current = head;

    printf("\n¼��ѧ����Ϣ\n");
    printf("ѧ��: ");
    scanf("%s", new_node->id);

    while (current) {
        if (strcmp(current->id, new_node->id) == 0) {
            printf("����ѧ���Ѵ��ڣ�\n");
            free(new_node);
            return;
        }
        current = current->next;
    }

    printf("����: ");
    scanf("%s", new_node->name);
    printf("�������£��� �� �գ�: ");
    scanf("%d %d %d", &new_node->year, &new_node->month, &new_node->day);
    printf("���ſγ̳ɼ����ո�ָ���: ");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &new_node->scores[i]);
    }

    new_node->total = 0;
    for (int i = 0; i < 4; i++) {
        new_node->total += new_node->scores[i];
    }
    new_node->average = new_node->total / 4;

    new_node->next = head;
    head = new_node;
    printf("ѧ����Ϣ��ӳɹ���\n");
}

void calculate_statistics() {
    if (!head) {
        printf("û��ѧ����¼��\n");
        return;
    }

    typedef struct {
        float max;
        float min;
        int fail;
    } Course;

    Course courses[4] = { {-1, 101, 0}, {-1, 101, 0}, {-1, 101, 0}, {-1, 101, 0} };
    Student* current = head;

    while (current) {
        for (int i = 0; i < 4; i++) {
            float s = current->scores[i];
            if (s > courses[i].max) courses[i].max = s;
            if (s < courses[i].min) courses[i].min = s;
            if (s < 60) courses[i].fail++;
        }
        current = current->next;
    }

    printf("\n�γ�ͳ�ƽ����\n");
    for (int i = 0; i < 4; i++) {
        printf("�γ�%d: ���%.1f ���%.1f ������%d��\n",
            i + 1, courses[i].max, courses[i].min, courses[i].fail);
    }
}

void display_all() {
    Student* current = head;
    if (!current) {
        printf("û��ѧ����¼��\n");
        return;
    }

    printf("\n%-10s %-10s %-12s %-6s %-6s %-6s %-6s %-6s %-6s\n",
        "ѧ��", "����", "��������", "�ɼ�1", "�ɼ�2", "�ɼ�3", "�ɼ�4", "�ܷ�", "����");
    while (current) {
        printf("%-10s %-10s %04d-%02d-%02d ",
            current->id, current->name,
            current->year, current->month, current->day);
        for (int i = 0; i < 4; i++)
            printf("%-6.1f ", current->scores[i]);
        printf("%-6.1f %-6.1f\n", current->total, current->average);
        current = current->next;
    }
}

void search_by_id() {
    char target[20];
    printf("�����ѯѧ��: ");
    scanf("%s", target);

    Student* current = head;
    while (current) {
        if (strcmp(current->id, target) == 0) {
            printf("\n�ҵ�ѧ����\n");
            printf("ѧ��: %s\n����: %s\n��������: %04d-%02d-%02d\n",
                current->id, current->name, current->year, current->month, current->day);
            printf("�ɼ�: %.1f, %.1f, %.1f, %.1f\n�ܷ�: %.1f ƽ����: %.1f\n",
                current->scores[0], current->scores[1],
                current->scores[2], current->scores[3],
                current->total, current->average);
            return;
        }
        current = current->next;
    }
    printf("δ�ҵ���ѧ����\n");
}

void search_by_name() {
    char target[50];
    printf("�����ѯ����: ");
    scanf("%s", target);

    Student* current = head;
    int found = 0;
    while (current) {
        if (strcmp(current->name, target) == 0) {
            if (!found) {
                printf("\n�ҵ�����ѧ����\n");
                found = 1;
            }
            printf("ѧ��: %s �ɼ�: %.1f, %.1f, %.1f, %.1f\n",
                current->id, current->scores[0], current->scores[1],
                current->scores[2], current->scores[3]);
        }
        current = current->next;
    }
    if (!found) printf("δ�ҵ���ѧ����\n");
}

void search_failed() {
    Student* current = head;
    int found = 0;

    printf("\n������ѧ���б�\n");
    while (current) {
        for (int i = 0; i < 4; i++) {
            if (current->scores[i] < 60) {
                printf("%s��%s���γ�%d������%.1f��\n",
                    current->name, current->id, i + 1, current->scores[i]);
                found = 1;
                break;
            }
        }
        current = current->next;
    }
    if (!found) printf("û�в�����ѧ����\n");
}

void sort_by_id() {
    if (!head || !head->next) return;

    int swapped;
    Student** ptr;
    do {
        swapped = 0;
        ptr = &head;
        while (*ptr && (*ptr)->next) {
            Student* a = *ptr;
            Student* b = a->next;
            if (strcmp(a->id, b->id) > 0) {
                a->next = b->next;
                b->next = a;
                *ptr = b;
                swapped = 1;
            }
            ptr = &(*ptr)->next;
        }
    } while (swapped);
    printf("��ѧ��������ɣ�\n");
}

void sort_by_age() {
    if (!head || !head->next) return;

    int swapped;
    Student** ptr;
    do {
        swapped = 0;
        ptr = &head;
        while (*ptr && (*ptr)->next) {
            Student* a = *ptr;
            Student* b = a->next;

            int swap = 0;
            if (a->year != b->year) {
                swap = a->year > b->year;
            }
            else if (a->month != b->month) {
                swap = a->month > b->month;
            }
            else {
                swap = a->day > b->day;
            }

            if (swap) {
                a->next = b->next;
                b->next = a;
                *ptr = b;
                swapped = 1;
            }
            ptr = &(*ptr)->next;
        }
    } while (swapped);
    printf("������������ɣ�\n");
}

void sort_by_total() {
    if (!head || !head->next) return;

    int swapped;
    Student** ptr;
    do {
        swapped = 0;
        ptr = &head;
        while (*ptr && (*ptr)->next) {
            Student* a = *ptr;
            Student* b = a->next;

            if (a->total < b->total) {
                a->next = b->next;
                b->next = a;
                *ptr = b;
                swapped = 1;
            }
            ptr = &(*ptr)->next;
        }
    } while (swapped);
    printf("���ܷ�������ɣ�\n");
}

void delete_student() {
    char target[20];
    printf("����Ҫɾ����ѧ��: ");
    scanf("%s", target);

    Student** ptr = &head;
    while (*ptr) {
        Student* current = *ptr;
        if (strcmp(current->id, target) == 0) {
            *ptr = current->next;
            free(current);
            printf("ɾ���ɹ���\n");
            return;
        }
        ptr = &(*ptr)->next;
    }
    printf("δ�ҵ���ѧ����\n");
}

void save_to_file() {
    FILE* fp = fopen("data.txt", "w");
    if (!fp) {
        printf("����ʧ�ܣ�\n");
        return;
    }

    Student* current = head;
    while (current) {
        fprintf(fp, "%s %s %d %d %d ", current->id, current->name,
            current->year, current->month, current->day);
        for (int i = 0; i < 4; i++) {
            fprintf(fp, "%.2f ", current->scores[i]);
        }
        fprintf(fp, "\n");
        current = current->next;
    }
    fclose(fp);
    printf("����ɹ���\n");
}

void load_from_file() {
    FILE* fp = fopen("data.txt", "r");
    if (!fp) {
        printf("��ȡʧ�ܣ�\n");
        return;
    }

    Student* current = head;
    while (current) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;

    while (!feof(fp)) {
        Student* new_node = (Student*)malloc(sizeof(Student));
        if (fscanf(fp, "%s %s %d %d %d %f %f %f %f",
            new_node->id, new_node->name,
            &new_node->year, &new_node->month, &new_node->day,
            &new_node->scores[0], &new_node->scores[1],
            &new_node->scores[2], &new_node->scores[3]) != 9) {
            free(new_node);
            break;
        }

        new_node->total = 0;
        for (int i = 0; i < 4; i++) {
            new_node->total += new_node->scores[i];
        }
        new_node->average = new_node->total / 4;

        new_node->next = head;
        head = new_node;
    }
    fclose(fp);
    printf("��ȡ�ɹ���\n");
}

void search_menu() {
    int choice;
    do {
        printf("\n��ѯ��ʽ��\n");
        printf("1. ��ѧ�Ų�ѯ\n");
        printf("2. ��������ѯ\n");
        printf("3. ��ѯ������\n");
        printf("0. ����\nѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: search_by_id(); break;
        case 2: search_by_name(); break;
        case 3: search_failed(); break;
        case 0: return;
        default: printf("��Чѡ�\n");
        }
    } while (1);
}

void sort_menu() {
    int choice;
    do {
        printf("\n����ʽ��\n");
        printf("1. ��ѧ��\n");
        printf("2. ������\n");
        printf("3. ���ܷ�\n");
        printf("0. ����\nѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: sort_by_id(); break;
        case 2: sort_by_age(); break;
        case 3: sort_by_total(); break;
        case 0: return;
        default: printf("��Чѡ�\n");
        }
    } while (1);
}

void main_menu() {
    int choice;
    do {
        printf("\n���˵�\n");
        printf("1. ��Ϣ¼��\n");
        printf("2. ��Ϣͳ��\n");
        printf("3. ��Ϣ���\n");
        printf("4. ��Ϣ��ѯ\n");
        printf("5. ��Ϣ����\n");
        printf("6. ��Ϣɾ��\n");
        printf("7. ������Ϣ\n");
        printf("8. ��ȡ��Ϣ\n");
        printf("0. �˳�ϵͳ\n");
        printf("ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: add_student(); break;
        case 2: calculate_statistics(); break;
        case 3: display_all(); break;
        case 4: search_menu(); break;
        case 5: sort_menu(); break;
        case 6: delete_student(); break;
        case 7: save_to_file(); break;
        case 8: load_from_file(); break;
        case 0: return;
        default: printf("��Чѡ�\n");
        }
    } while (1);
}

int main() {
    if (!login()) {
        printf("��¼ʧ�ܣ������˳���\n");
        return 0;
    }

    main_menu();

    // �ͷ��ڴ�
    Student* current = head;
    while (current) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}