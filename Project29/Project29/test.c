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


int main()
{
	int input = 0;
	Contact con;
	InitCon(&con);
	do
	{
		menu();
		printf("请输入模式>-");
		scanf_s("%d", &input);
		switch (input)
		{
		    case 1:
			    AddCon(&con);
				break;
			case 2:
				SearchCon(&con);
				break;
			case 3:
				ShowCon(&con);
				break;
			case 4:
				Monify(&con);
				break;
			case 5:
				DelectCon(&con);
				break;
			case 6:
				SortCon(&con);
				break;
		    default:
				printf("输入错误请再次输入\n");
				break;
		}
	} while (input);
	return 0;
}