#define _CRT_SECURE_NO_WARNINGS
#include "System.h"

void DestroySys(System* sys)
{
	free(sys->data);
	sys->data = NULL;
	sys->count = 0;
	sys->capacity = 0;
}


void LoadSys(System* sys)
{
	FILE* pf = fopen("system.txt", "r");
	if (pf == NULL)
	{
		perror("LoadSys");
		return;
	}
	Bookinfo tmp = { 0 };
	while (fscanf(pf, "%s %s %s %d ",  tmp.codenum,
											tmp.name,
											tmp.publishing_house,
											&(tmp.state)) >=4)
	{
		fgets(tmp.lendtime, 26, pf);
		fscanf(pf, "%d", &(tmp.borrowtimes));
		CheckCapacity(sys);
		strcpy(sys->data[sys->count].codenum, tmp.codenum);
		strcpy(sys->data[sys->count].name, tmp.name);
		strcpy(sys->data[sys->count].publishing_house, tmp.publishing_house);
		sys->data[sys->count].state = tmp.state;
		strcpy(sys->data[sys->count].lendtime, tmp.lendtime);
		sys->data[sys->count].borrowtimes = tmp.borrowtimes;
		sys->count++;
	}
	fclose(pf);
	pf = NULL;
	printf("ͼ����Ϣ������\n");
}


void SaveSys(System* sys)
{
	FILE* pf = fopen("system.txt", "w");
	if (pf == NULL)
	{
		perror("SaveSys");
		return;
	}
	for (int i = 0;i < sys->count; i++)
	{
		fprintf(pf, "%s %s %s %d %s %d\n", sys->data[i].codenum,
										   sys->data[i].name,
										   sys->data[i].publishing_house,
										   sys->data[i].state,
										   sys->data[i].lendtime,
		                                   sys->data[i].borrowtimes);
	}
	fclose(pf);
	pf = NULL;
	printf("ͼ����Ϣ�ѱ���\n");
}


void InitSys(System* sys)
{
	assert(sys);
	sys->data = (Bookinfo*)calloc(DEFAULT_SZ, sizeof(Bookinfo));
	if (sys->data == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	sys->count = 0;
	sys->capacity = DEFAULT_SZ;
	LoadSys(sys);
}


void CheckCapacity(System* sys)
{
	assert(sys);
	if (sys->capacity == sys->count)
	{
		Bookinfo* ptr = (Bookinfo*)realloc(sys->data, (sys->capacity + INC_SZ) * sizeof(Bookinfo));
		if (ptr != NULL)
		{
			sys->data = ptr;
			memset(sys->data + sys->count, 0, INC_SZ * sizeof(Bookinfo));
			sys->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("%s", strerror(errno));
			printf("����ʧ��\n");
			return;
		}
	}
}


int FindName(System* sys, char* str)
{
	assert(sys && str);
	for (int i = 0;i < sys->count;i++)
	{
		if (strcmp(sys->data[i].name, str) == 0)
		{
			return i;
		}
	}
	return -1;
}
void AddSys(System* sys)
{
	assert(sys);
	CheckCapacity(sys);
	printf("�������鱾����\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int ret = FindName(sys, name);
	if (ret >= 0)
	{
		printf("�鱾�Ѵ��ڣ��������\n");
		return;
	}
	strcpy(sys->data[sys->count].name, name);
	printf("�������鱾���\n");
	scanf("%s", sys->data[sys->count].codenum);
	printf("�������鱾������\n");
	scanf("%s", sys->data[sys->count].publishing_house);
	printf("�鱾���ӳɹ�\n");
	sys->count++;
}


void DeleteSys(System* sys)
{
	assert(sys);
	printf("������Ҫɾ���鱾������\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int ret = FindName(sys, name);
	if (ret == -1)
	{
		printf("�鱾�����ڣ�ɾ��ʧ��\n");
		return;
	}
	if (sys->data[ret].state == 1)
	{
		printf("�鱾�ѽ���� ɾ��ʧ��\n");
		return;
	}
	for (int i = ret;i < sys->count - 1;i++)
	{
		sys->data[i] = sys->data[i + 1];
	}

    sys->count--;
    printf("ɾ���ɹ�\n");
}
 

void ShowSys(System* sys)
{
	assert(sys);
	int i = 0;
	printf("%-20s\t%-20s\t%-20s\t%-3s\t%-26s\t%-4s\n", "���", "����", "������", "״̬", "���ʱ��","�������");
	for (i = 0;i < sys->count;i++)
	{
		printf("%-20s\t%-20s\t%-20s\t",sys->data[i].codenum,
									   sys->data[i].name,
									   sys->data[i].publishing_house);
		if (sys->data[i].state == 0)
		{
			printf("δ���\t��                         \t%-3d\n",sys->data[i].borrowtimes);
		}
		else
		{
			printf("�ѽ��\t%2s\t%-3d\n", sys->data[i].lendtime
				                        , sys->data[i].borrowtimes);
		}
	}
}


void LendSys(System* sys)
{
	assert(sys);
	printf("����������鱾������\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int ret = FindName(sys, name);
	if (ret == -1)
	{
		printf("�鱾�����ڣ�����ʧ��\n");
		return;
	}
	if (sys->data[ret].state == 1)
	{
		printf("�鱾�ѽ���� ����ʧ��\n");
		return;
	}
	sys->data[ret].state = 1;
	sys->data[ret].borrowtimes++;
	time_t current_time;
	time(&current_time);
	strcpy(sys->data[ret].lendtime, ctime(&current_time));
	*(sys->data[ret].lendtime + 24) = '\0';
	printf("���ĳɹ�\n");
}


void ReturnSys(System* sys)
{
	assert(sys);
	printf("������黹�鱾������\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int ret = FindName(sys, name);
	if (ret == -1)
	{
		printf("�鱾�����ڣ��黹ʧ��\n");
		return;
	}
	if (sys->data[ret].state == 0)
	{
		printf("�鱾δ����� �黹ʧ��\n");
		return;
	}
	sys->data[ret].state = 0;
	memset(sys->data[ret].lendtime, 0, 26);
	printf("�鱾�黹�ɹ�\n");
}


int cmp_peo_by_borrowtimes(const void* e1, const void* e2)
{
	return ((Bookinfo*)e2)->borrowtimes - ((Bookinfo*)e1)->borrowtimes;
}

void RankSys(System* sys)
{
	
	assert(sys);
	qsort(sys->data, sys->count, sizeof(sys->data[0]), cmp_peo_by_borrowtimes);

	printf("------------------------���а�-------------------------\n");
	printf("        �鱾����                      ���Ĵ���         \n");
	for (int i = 0;i < sys->count; i++)
	{
		printf("        %-20s          %-3d\n", sys->data[i].name 
			                                  ,sys->data[i].borrowtimes);
	}
}