#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define NUM_COURSES 5 // 4门课程

typedef struct Student 
{
    int id;
    char name[MAX_NAME_LENGTH];
    char birthdate[11]; // YYYY-MM-DD
    float scores[NUM_COURSES]; // 4门课程的成绩
    float totalScore;
    float averageScore;
    struct Student* next;
} Student;

typedef struct User 
{
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
   
} User;

// 课程统计结果
typedef struct CourseStatistics 
{
    float maxScore; // 最高分
    float minScore; // 最低分
    int failCount;  // 不及格人数
} CourseStatistics;

// 用户登录模块
int login(User* users, int userCount) 
{
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int attempts = 3;

    while (attempts > 0) 
    {
        printf("请输入用户名: ");
        scanf("%s", username);
        printf("请输入密码: ");
        scanf("%s", password);

        for (int i = 0; i < userCount; i++) 
        {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                printf("登录成功!\n");
                return 1;
            }
        }

        attempts--;
        printf("用户名或密码错误，剩余尝试次数: %d\n", attempts);
    }

    printf("登录失败，程序退出。\n");
    return 0;
}

// 创建学生节点
Student* createStudent(int id, char* name, char* birthdate, float scores[]) 
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    strcpy(newStudent->birthdate, birthdate);
    for (int i = 0; i < NUM_COURSES; i++) 
    {
        newStudent->scores[i] = scores[i];
    }
    newStudent->totalScore = 0;
    newStudent->averageScore = 0;
    newStudent->next = NULL;
    return newStudent;
}

// 添加学生信息
void addStudent(Student** head, Student* newStudent) 
{
    if (*head == NULL) 
    {
        *head = newStudent;
    }
    else 
    {
        Student* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// 统计学生信息
void calculateStatistics(Student* head, CourseStatistics stats[]) 
{
    Student* temp = head;

    // 初始化统计结果
    for (int i = 0; i < NUM_COURSES; i++) 
    {
        stats[i].maxScore = -1;
        stats[i].minScore = 101;
        stats[i].failCount = 0;
    }

    while (temp != NULL) 
    {
        temp->totalScore = 0;
        for (int i = 0; i < NUM_COURSES; i++) 
        {
            temp->totalScore += temp->scores[i];

            // 更新最高分和最低分
            if (temp->scores[i] > stats[i].maxScore) 
            {
                stats[i].maxScore = temp->scores[i];
            }
            if (temp->scores[i] < stats[i].minScore) 
            {
                stats[i].minScore = temp->scores[i];
            }

            // 统计不及格人数
            if (temp->scores[i] < 60) 
            {
                stats[i].failCount++;
            }
        }
        temp->averageScore = temp->totalScore / NUM_COURSES;
        temp = temp->next;
    }
}

// 显示所有学生信息
void displayStudents(Student* head) 
{
    Student* temp = head;
    while (temp != NULL) 
    {
        printf("学号: %d, 姓名: %s, 出生日期: %s, 成绩: ", temp->id, temp->name, temp->birthdate);
        for (int i = 0; i < NUM_COURSES; i++)
        {
            printf("%.2f ", temp->scores[i]);
        }
        printf("总分: %.2f, 平均分: %.2f\n", temp->totalScore, temp->averageScore);
        temp = temp->next;
    }
}

// 按学号查询学生信息
void searchStudent(Student* head, int id) 
{
    Student* temp = head;
    while (temp != NULL) 
    {
        if (temp->id == id) 
        {
            printf("学号: %d, 姓名: %s, 出生日期: %s, 成绩: ", temp->id, temp->name, temp->birthdate);
            for (int i = 0; i < NUM_COURSES; i++) 
            {
                printf("%.2f ", temp->scores[i]);
            }
            printf("总分: %.2f, 平均分: %.2f\n", temp->totalScore, temp->averageScore);
            return;
        }
        temp = temp->next;
    }
    printf("未找到学号为 %d 的学生。\n", id);
}

// 按学号或总分排序学生信息
void sortStudents(Student** head, int byTotalScore) 
{
    if (*head == NULL || (*head)->next == NULL) 
        return;

    Student* sorted = NULL;
    Student* current = *head;

    while (current != NULL) 
    {
        Student* next = current->next;
        if (sorted == NULL ||
                (byTotalScore ? sorted->totalScore <= current->totalScore : sorted->id >= current->id)) 
        {
            current->next = sorted;
            sorted = current;
        }
        else 
        {
            Student* temp = sorted;
            while (temp->next != NULL &&
                (byTotalScore ? temp->next->totalScore > current->totalScore : temp->next->id < current->id))
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

// 按学号删除学生信息
void deleteStudent(Student** head, int id) 
{
    Student* temp = *head;
    Student* prev = NULL;

    if (temp != NULL && temp->id == id) 
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// 保存学生信息到文件
void saveStudentsToFile(Student* head, const char* filename) 
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return;
    }

    Student* temp = head;
    while (temp != NULL) 
    {
        fprintf(file, "%d %s %s ", temp->id, temp->name, temp->birthdate);
        for (int i = 0; i < NUM_COURSES; i++) 
        {
            fprintf(file, "%.2f ", temp->scores[i]);
        }
        fprintf(file, "%.2f %.2f\n", temp->totalScore, temp->averageScore);
        temp = temp->next;
    }

    fclose(file);
}

// 从文件读取学生信息
Student* loadStudentsFromFile(const char* filename) 
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("无法打开文件 %s\n", filename);
        return NULL;
    }

    Student* head = NULL;
    Student* temp = NULL;
    int id;
    char name[MAX_NAME_LENGTH];
    char birthdate[11];
    float scores[NUM_COURSES];
    float totalScore, averageScore;

    while (fscanf(file, "%d %s %s", &id, name, birthdate) != EOF) 
    {
        for (int i = 0; i < NUM_COURSES; i++) 
        {
            fscanf(file, "%f", &scores[i]);
        }
        fscanf(file, "%f %f", &totalScore, &averageScore);

        Student* newStudent = createStudent(id, name, birthdate, scores);
        newStudent->totalScore = totalScore;
        newStudent->averageScore = averageScore;

        if (head == NULL) 
        {
            head = newStudent;
        }
        else 
        {
            temp->next = newStudent;
        }
        temp = newStudent;
    }

    fclose(file);
    return head;
}

// 显示各科成绩统计结果
void displayCourseStatistics(CourseStatistics stats[]) 
{
    printf("\n各科成绩统计结果:\n");
    for (int i = 0; i < NUM_COURSES; i++) 
    {
        printf("课程 %d:\n", i + 1);
        printf("  最高分: %.2f\n", stats[i].maxScore);
        printf("  最低分: %.2f\n", stats[i].minScore);
        printf("  不及格人数: %d\n", stats[i].failCount);
    }
}

// 主函数
int main() 
{
    User users[] = { {"123", "123"} };
    int userCount = 1;

    if (!login(users, userCount)) 
    {
        return 0;
    }

    Student* head = NULL;
    CourseStatistics stats[NUM_COURSES]; // 各科成绩统计结果
    int choice;
    do {
        printf("\n1. 录入学生信息\n");
        printf("2. 统计学生信息\n");
        printf("3. 浏览学生信息\n");
        printf("4. 查询学生信息\n");
        printf("5. 按学号排序学生信息\n");
        printf("6. 按总分排序学生信息\n");
        printf("7. 删除学生信息\n");
        printf("8. 保存学生信息\n");
        printf("9. 读取学生信息\n");
        printf("10. 显示各科成绩统计结果\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);

        switch (choice)
        {
          case 1: 
          {
            int id;
            char name[MAX_NAME_LENGTH];
            char birthdate[11];
            float scores[NUM_COURSES];
            printf("请输入学号: ");
            scanf("%d", &id);
            printf("请输入姓名: ");
            scanf("%s", name);
            printf("请输入出生日期 (YYYY-MM-DD): ");
            scanf("%s", birthdate);
            printf("请输入5门课程的成绩: ");
            for (int i = 0; i < NUM_COURSES; i++) 
            {
                scanf("%f", &scores[i]);
            }
            Student* newStudent = createStudent(id, name, birthdate, scores);
            addStudent(&head, newStudent);
            break;
          }
           case 2:
            calculateStatistics(head, stats);
            printf("学生信息统计完成。\n");
            break;
           case 3:
            displayStudents(head);
            break;
           case 4: 
           {
            int id;
            printf("请输入要查询的学号: ");
            scanf("%d", &id);
            searchStudent(head, id);
            break;
           }
           case 5:
            sortStudents(&head, 0); // 按学号排序
            break;
           case 6:
            sortStudents(&head, 1); // 按总分排序
            break;
           case 7: 
           {
            int id;
            printf("请输入要删除的学号: ");
            scanf("%d", &id);
            deleteStudent(&head, id);
            break;
           }
           case 8:
            saveStudentsToFile(head, "students.txt");
            break;
           case 9:
            head = loadStudentsFromFile("students.txt");
            break;
           case 10:
            displayCourseStatistics(stats);
            break;
           case 0:
            printf("退出系统。\n");
            break;
           default:
            printf("无效的选择，请重试。\n");
        }
    } while (choice != 0);

    return 0;
}