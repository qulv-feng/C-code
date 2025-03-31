#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define NUM_COURSES 5 // 4�ſγ�

typedef struct Student 
{
    int id;
    char name[MAX_NAME_LENGTH];
    char birthdate[11]; // YYYY-MM-DD
    float scores[NUM_COURSES]; // 4�ſγ̵ĳɼ�
    float totalScore;
    float averageScore;
    struct Student* next;
} Student;

typedef struct User 
{
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
   
} User;

// �γ�ͳ�ƽ��
typedef struct CourseStatistics 
{
    float maxScore; // ��߷�
    float minScore; // ��ͷ�
    int failCount;  // ����������
} CourseStatistics;

// �û���¼ģ��
int login(User* users, int userCount) 
{
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int attempts = 3;

    while (attempts > 0) 
    {
        printf("�������û���: ");
        scanf("%s", username);
        printf("����������: ");
        scanf("%s", password);

        for (int i = 0; i < userCount; i++) 
        {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                printf("��¼�ɹ�!\n");
                return 1;
            }
        }

        attempts--;
        printf("�û������������ʣ�ೢ�Դ���: %d\n", attempts);
    }

    printf("��¼ʧ�ܣ������˳���\n");
    return 0;
}

// ����ѧ���ڵ�
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

// ���ѧ����Ϣ
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

// ͳ��ѧ����Ϣ
void calculateStatistics(Student* head, CourseStatistics stats[]) 
{
    Student* temp = head;

    // ��ʼ��ͳ�ƽ��
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

            // ������߷ֺ���ͷ�
            if (temp->scores[i] > stats[i].maxScore) 
            {
                stats[i].maxScore = temp->scores[i];
            }
            if (temp->scores[i] < stats[i].minScore) 
            {
                stats[i].minScore = temp->scores[i];
            }

            // ͳ�Ʋ���������
            if (temp->scores[i] < 60) 
            {
                stats[i].failCount++;
            }
        }
        temp->averageScore = temp->totalScore / NUM_COURSES;
        temp = temp->next;
    }
}

// ��ʾ����ѧ����Ϣ
void displayStudents(Student* head) 
{
    Student* temp = head;
    while (temp != NULL) 
    {
        printf("ѧ��: %d, ����: %s, ��������: %s, �ɼ�: ", temp->id, temp->name, temp->birthdate);
        for (int i = 0; i < NUM_COURSES; i++)
        {
            printf("%.2f ", temp->scores[i]);
        }
        printf("�ܷ�: %.2f, ƽ����: %.2f\n", temp->totalScore, temp->averageScore);
        temp = temp->next;
    }
}

// ��ѧ�Ų�ѯѧ����Ϣ
void searchStudent(Student* head, int id) 
{
    Student* temp = head;
    while (temp != NULL) 
    {
        if (temp->id == id) 
        {
            printf("ѧ��: %d, ����: %s, ��������: %s, �ɼ�: ", temp->id, temp->name, temp->birthdate);
            for (int i = 0; i < NUM_COURSES; i++) 
            {
                printf("%.2f ", temp->scores[i]);
            }
            printf("�ܷ�: %.2f, ƽ����: %.2f\n", temp->totalScore, temp->averageScore);
            return;
        }
        temp = temp->next;
    }
    printf("δ�ҵ�ѧ��Ϊ %d ��ѧ����\n", id);
}

// ��ѧ�Ż��ܷ�����ѧ����Ϣ
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

// ��ѧ��ɾ��ѧ����Ϣ
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

// ����ѧ����Ϣ���ļ�
void saveStudentsToFile(Student* head, const char* filename) 
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("�޷����ļ� %s\n", filename);
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

// ���ļ���ȡѧ����Ϣ
Student* loadStudentsFromFile(const char* filename) 
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("�޷����ļ� %s\n", filename);
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

// ��ʾ���Ƴɼ�ͳ�ƽ��
void displayCourseStatistics(CourseStatistics stats[]) 
{
    printf("\n���Ƴɼ�ͳ�ƽ��:\n");
    for (int i = 0; i < NUM_COURSES; i++) 
    {
        printf("�γ� %d:\n", i + 1);
        printf("  ��߷�: %.2f\n", stats[i].maxScore);
        printf("  ��ͷ�: %.2f\n", stats[i].minScore);
        printf("  ����������: %d\n", stats[i].failCount);
    }
}

// ������
int main() 
{
    User users[] = { {"123", "123"} };
    int userCount = 1;

    if (!login(users, userCount)) 
    {
        return 0;
    }

    Student* head = NULL;
    CourseStatistics stats[NUM_COURSES]; // ���Ƴɼ�ͳ�ƽ��
    int choice;
    do {
        printf("\n1. ¼��ѧ����Ϣ\n");
        printf("2. ͳ��ѧ����Ϣ\n");
        printf("3. ���ѧ����Ϣ\n");
        printf("4. ��ѯѧ����Ϣ\n");
        printf("5. ��ѧ������ѧ����Ϣ\n");
        printf("6. ���ܷ�����ѧ����Ϣ\n");
        printf("7. ɾ��ѧ����Ϣ\n");
        printf("8. ����ѧ����Ϣ\n");
        printf("9. ��ȡѧ����Ϣ\n");
        printf("10. ��ʾ���Ƴɼ�ͳ�ƽ��\n");
        printf("0. �˳�\n");
        printf("��ѡ�����: ");
        scanf("%d", &choice);

        switch (choice)
        {
          case 1: 
          {
            int id;
            char name[MAX_NAME_LENGTH];
            char birthdate[11];
            float scores[NUM_COURSES];
            printf("������ѧ��: ");
            scanf("%d", &id);
            printf("����������: ");
            scanf("%s", name);
            printf("������������� (YYYY-MM-DD): ");
            scanf("%s", birthdate);
            printf("������5�ſγ̵ĳɼ�: ");
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
            printf("ѧ����Ϣͳ����ɡ�\n");
            break;
           case 3:
            displayStudents(head);
            break;
           case 4: 
           {
            int id;
            printf("������Ҫ��ѯ��ѧ��: ");
            scanf("%d", &id);
            searchStudent(head, id);
            break;
           }
           case 5:
            sortStudents(&head, 0); // ��ѧ������
            break;
           case 6:
            sortStudents(&head, 1); // ���ܷ�����
            break;
           case 7: 
           {
            int id;
            printf("������Ҫɾ����ѧ��: ");
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
            printf("�˳�ϵͳ��\n");
            break;
           default:
            printf("��Ч��ѡ�������ԡ�\n");
        }
    } while (choice != 0);

    return 0;
}