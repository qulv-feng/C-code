#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void menu()
{
	printf("**************************************************************************\n");
	printf("*************************1.add          2.search**************************\n");
	printf("*************************3.show         4.modify**************************\n");
	printf("*************************5.delete       6.sort****************************\n");
	printf("*************************0.exit         0.exit****************************\n");
	printf("**************************************************************************\n");
}

enum Option
{
	EXIT,
	ADD,
	SEARCH,
    SHOW,
	MODIFY,
	DELETE,
	SORT,
};

int main()
{
	int input = 0;
	Contact con;
	InitCon(&con);
	do
	{
		menu();
		printf("请选择->");
		scanf_s("%d", &input);
		switch (input)
		{
		case EXIT:
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		case ADD:
			AddCon(&con);
			break;
		case SEARCH:
			SearchCon(&con);
			break;
		case SHOW:
			ShowCon(&con);
			break;
		case MODIFY:
			Modify(&con);
			break;
		case DELETE:
			DeleteCon(&con);
			break;
		case SORT:
			SortCon(&con);
			break;
		default:
			printf("选择错误,重新选择\n");
			break;
		}
	} while (input);
	return 0;
}