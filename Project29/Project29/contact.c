#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void InitCon(Contact* p)
{
	assert(p);
	memset(p, 0, sizeof(*p));
	p->count = 0;
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

void AddCon(Contact* p) 
{
	assert(p);
	if (p->count >= MAX)
	{
		printf("通讯录已满\n");
		return;
	}
	printf("请输入名字:>");
	scanf_s("%s", p->date[p->count].name);
	printf("请输入年龄:>");
	scanf_s("%d",&(p->date[p->count].age));
	printf("请输入性别:>");
	scanf_s("%s", p->date[p->count].gender);
	printf("请输入电话:>");
	scanf_s("%s", p->date[p->count].tel);
	printf("请输入地址:>");
	scanf_s("%s", p->date[p->count].address);
	p->count++;
	printf("增加成功\n");
}

void SearchCon(Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf_s("%s", name);
	int ret = FindName(p, name);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		//打印数据
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
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
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (int i = 0;i < p->count;i++)
	{
		printf("%-20s \t %-3d %-10s \t %-30s \t %-50s\n",p->date[i].name,
                                                         p->date[i].age,
	                                                     p->date[i].gender,
	                                                     p->date[i].tel,
	                                                     p->date[i].address);
	}
}

void DelectCon(Contact* p)
{
	assert(p);
	char name_0[20] = { 0 };
	if (p->count <= 0)
	{
		printf("通讯录为空，无需删除");
	}
	printf("请输入要删除人的名字:>");
	scanf_s("%s", name_0);
	int ret = FindName(p,name_0);
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
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
	printf("删除成功\n");
}

void Monify(Contact* p)
{
	assert(p);
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf_s("%s", name);

	int ret = FindName(p, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入名字:>");
		scanf_s("%s", p->date[ret].name);
		printf("请输入年龄:>");
		scanf_s("%d", &(p->date[ret].age));
		printf("请输入性别:>");
		scanf_s("%s", p->date[ret].gender);
		printf("请输入电话:>");
		scanf_s("%s", p->date[ret].tel);
		printf("请输入地址:>");
		scanf_s("%s", p->date[ret].address);

		printf("修改成功\n");
	}
}
//void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void* elem1, const void* elem2));
int cmp_peo_by_name(const void* e1,const void* e2)
{
	return strcmp(((Pelinfo*)e1)->name, ((Pelinfo*)e2)->name);
}

void SortCon(Contact* p)
{
	assert(p);
	qsort(p->date, p->count,sizeof(p->date[0]),cmp_peo_by_name);
}

