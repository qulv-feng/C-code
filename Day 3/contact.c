#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void InitCon(Contact* p)
{
	assert(p);
	p->date = (Peoinfo*)calloc(DEFAULT_SZ,sizeof(Peoinfo));
	if (p->date == NULL)
	{
		printf("%s", strerror(errno));
	}
	p->count = 0;
	p->capacity = DEFAULT_SZ;

	LoadContact(p);
}

int FindName(Contact* p, char* str)
{
	assert(p && str);
	for (int i = 0;i < p->count;i++)
	{
		if (strcmp((p->date[i].name), str) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DestoryContact(Contact* p)
{
	free(p->date);
	p->date = NULL;
	p->count = 0;
	p->capacity = 0;
}

void CheckCapacity(Contact* p)
{
	if (p->capacity == p->count)
	{
		Peoinfo* ptr = (Peoinfo*)realloc(p->date, (p->capacity + INC_SZ) * sizeof(Peoinfo));
		if (ptr != NULL)
		{
			p->date = ptr;
			p->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("%s", strerror(errno));
			printf("������ϵ��ʧ��\n");
			return;
		}
	}
}


void AddCon(Contact* p)
{
	assert(p);
	CheckCapacity(p);
	printf("����������:>");
	scanf("%s", p->date[p->count].name);
	printf("����������:>");
	scanf("%d", &(p->date[p->count].age));
	printf("�������Ա�:>");
	scanf("%s", p->date[p->count].gender);
	printf("������绰:>");
	scanf("%s", p->date[p->count].tel);
	printf("�������ַ:>");
	scanf("%s", p->date[p->count].address);
	p->count++;
	printf("���ӳɹ�\n");
}

void SearchCon(Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int ret = FindName(p, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-10s\t%-30s\t%-50s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-5d\t%-10s\t%-30s\t%-50s\n",
			p->date[ret].name,
			p->date[ret].age,
			p->date[ret].gender,
			p->date[ret].tel,
			p->date[ret].address);
	}
}

void ShowCon(Contact* p)
{
	assert(p);
	printf("%-20s\t%-5s\t%-10s\t%-30s\t%-50s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0;i < p->count;i++)
	{
		printf("%-20s\t%-5d\t%-10s\t%-30s\t%-50s\n", p->date[i].name,
			p->date[i].age,
			p->date[i].gender,
			p->date[i].tel,
			p->date[i].address);
	}
}

void DeleteCon(Contact* p)
{
	assert(p);
	char name_0[20] = { 0 };
	if (p->count <= 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��");
	}
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name_0);
	int ret = FindName(p, name_0);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	else
	{
		for (int i = ret;i < p->count - 1;i++)
		{
			p->date[i] = p->date[i + 1];
		}
	}
	p->count--;
	printf("ɾ���ɹ�\n");
}

void Modify(Contact* p)
{
	assert(p);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);

	int ret = FindName(p, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("����������:>");
		scanf("%s", p->date[ret].name);
		printf("����������:>");
		scanf("%d", &(p->date[ret].age));
		printf("�������Ա�:>");
		scanf("%s", p->date[ret].gender);
		printf("������绰:>");
		scanf("%s", p->date[ret].tel);
		printf("�������ַ:>");
		scanf("%s", p->date[ret].address);

		printf("�޸ĳɹ�\n");
	}
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((Peoinfo*)e1)->name, ((Peoinfo*)e2)->name);
}

void SortCon(Contact* p)
{
	assert(p);
	qsort(p->date, p->count, sizeof(p->date[0]), cmp_peo_by_name);
}

void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->date + i, sizeof(Peoinfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

void LoadContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	Peoinfo tmp = { 0 };
	while (fread(&tmp, sizeof(Peoinfo), 1, pf))
	{
		CheckCapacity(pc);
		pc->date[pc->count] = tmp;
		pc->count++;
	}

	fclose(pf);
	pf = NULL;
}