#define _CRT_SECURE_NO_WARNINGS
#include "System.h"


void menu()
{
	printf("********************************************************************************\n");
	printf("*************************1.addbook          2.lendbook**************************\n");
	printf("*************************3.returnbook       4.rankbook**************************\n");
	printf("*************************5.deletebook       6.showbook**************************\n");
	printf("*************************0.exit             0.exit******************************\n");
	printf("********************************************************************************\n");
}

int main()
{
	int input = 0;
	System sys;
	InitSys(&sys);
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			SaveSys(&sys);
			DestroySys(&sys);
			printf("�˳�ͨѶ¼\n");
			break;
		case ADD:
			AddSys(&sys);
			break;
		case LEND:
			LendSys(&sys);
			break;
		case RETURN:
			ReturnSys(&sys);
			break;
		case RANK:
			RankSys(&sys);
			break;
		case DELETE:
			DeleteSys(&sys);
			break;
		case SHOW:
			ShowSys(&sys);
			break;
		default:
			printf("ѡ�����,����ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}