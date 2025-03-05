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
        printf("系统错误：用户文件不存在！\n");
        return 0;
    }

    char file_user[50], file_pass[50];
    fscanf(fp, "%s %s", file_user, file_pass);
    fclose(fp);

    while (attempts < 3) {
        printf("\n用户登录\n");
        printf("用户名: ");
        scanf("%s", username);
        printf("密码: ");
        scanf("%s", password);

        if (strcmp(username, file_user) == 0 && strcmp(password, file_pass) == 0) {
            return 1;
        }
        else {
            printf("用户名或密码错误，剩余尝试次数：%d\n", 2 - attempts);
            attempts++;
        }
    }
    return 0;
}

void add_student() {
    Student* new_node = (Student*)malloc(sizeof(Student));
    Student* current = head;

    printf("\n录入学生信息\n");
    printf("学号: ");
    scanf("%s", new_node->id);

    while (current) {
        if (strcmp(current->id, new_node->id) == 0) {
            printf("错误：学号已存在！\n");
            free(new_node);
            return;
        }
        current = current->next;
    }

    printf("姓名: ");
    scanf("%s", new_node->name);
    printf("出生年月（年 月 日）: ");
    scanf("%d %d %d", &new_node->year, &new_node->month, &new_node->day);
    printf("四门课程成绩（空格分隔）: ");
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
    printf("学生信息添加成功！\n");
}

void calculate_statistics() {
    if (!head) {
        printf("没有学生记录！\n");
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

    printf("\n课程统计结果：\n");
    for (int i = 0; i < 4; i++) {
        printf("课程%d: 最高%.1f 最低%.1f 不及格%d人\n",
            i + 1, courses[i].max, courses[i].min, courses[i].fail);
    }
}

void display_all() {
    Student* current = head;
    if (!current) {
        printf("没有学生记录！\n");
        return;
    }

    printf("\n%-10s %-10s %-12s %-6s %-6s %-6s %-6s %-6s %-6s\n",
        "学号", "姓名", "出生日期", "成绩1", "成绩2", "成绩3", "成绩4", "总分", "均分");
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
    printf("输入查询学号: ");
    scanf("%s", target);

    Student* current = head;
    while (current) {
        if (strcmp(current->id, target) == 0) {
            printf("\n找到学生：\n");
            printf("学号: %s\n姓名: %s\n出生日期: %04d-%02d-%02d\n",
                current->id, current->name, current->year, current->month, current->day);
            printf("成绩: %.1f, %.1f, %.1f, %.1f\n总分: %.1f 平均分: %.1f\n",
                current->scores[0], current->scores[1],
                current->scores[2], current->scores[3],
                current->total, current->average);
            return;
        }
        current = current->next;
    }
    printf("未找到该学生！\n");
}

void search_by_name() {
    char target[50];
    printf("输入查询姓名: ");
    scanf("%s", target);

    Student* current = head;
    int found = 0;
    while (current) {
        if (strcmp(current->name, target) == 0) {
            if (!found) {
                printf("\n找到以下学生：\n");
                found = 1;
            }
            printf("学号: %s 成绩: %.1f, %.1f, %.1f, %.1f\n",
                current->id, current->scores[0], current->scores[1],
                current->scores[2], current->scores[3]);
        }
        current = current->next;
    }
    if (!found) printf("未找到该学生！\n");
}

void search_failed() {
    Student* current = head;
    int found = 0;

    printf("\n不及格学生列表：\n");
    while (current) {
        for (int i = 0; i < 4; i++) {
            if (current->scores[i] < 60) {
                printf("%s（%s）课程%d不及格（%.1f）\n",
                    current->name, current->id, i + 1, current->scores[i]);
                found = 1;
                break;
            }
        }
        current = current->next;
    }
    if (!found) printf("没有不及格学生！\n");
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
    printf("按学号排序完成！\n");
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
    printf("按年龄排序完成！\n");
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
    printf("按总分排序完成！\n");
}

void delete_student() {
    char target[20];
    printf("输入要删除的学号: ");
    scanf("%s", target);

    Student** ptr = &head;
    while (*ptr) {
        Student* current = *ptr;
        if (strcmp(current->id, target) == 0) {
            *ptr = current->next;
            free(current);
            printf("删除成功！\n");
            return;
        }
        ptr = &(*ptr)->next;
    }
    printf("未找到该学生！\n");
}

void save_to_file() {
    FILE* fp = fopen("data.txt", "w");
    if (!fp) {
        printf("保存失败！\n");
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
    printf("保存成功！\n");
}

void load_from_file() {
    FILE* fp = fopen("data.txt", "r");
    if (!fp) {
        printf("读取失败！\n");
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
    printf("读取成功！\n");
}

void search_menu() {
    int choice;
    do {
        printf("\n查询方式：\n");
        printf("1. 按学号查询\n");
        printf("2. 按姓名查询\n");
        printf("3. 查询不及格\n");
        printf("0. 返回\n选项: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: search_by_id(); break;
        case 2: search_by_name(); break;
        case 3: search_failed(); break;
        case 0: return;
        default: printf("无效选项！\n");
        }
    } while (1);
}

void sort_menu() {
    int choice;
    do {
        printf("\n排序方式：\n");
        printf("1. 按学号\n");
        printf("2. 按年龄\n");
        printf("3. 按总分\n");
        printf("0. 返回\n选项: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: sort_by_id(); break;
        case 2: sort_by_age(); break;
        case 3: sort_by_total(); break;
        case 0: return;
        default: printf("无效选项！\n");
        }
    } while (1);
}

void main_menu() {
    int choice;
    do {
        printf("\n主菜单\n");
        printf("1. 信息录入\n");
        printf("2. 信息统计\n");
        printf("3. 信息浏览\n");
        printf("4. 信息查询\n");
        printf("5. 信息排序\n");
        printf("6. 信息删除\n");
        printf("7. 保存信息\n");
        printf("8. 读取信息\n");
        printf("0. 退出系统\n");
        printf("选项: ");
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
        default: printf("无效选项！\n");
        }
    } while (1);
}

int main() {
    if (!login()) {
        printf("登录失败，程序退出！\n");
        return 0;
    }

    main_menu();

    // 释放内存
    Student* current = head;
    while (current) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}