#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void mune()
{
	printf("******************\n");
	printf("*****1.ģʽһ*****\n");
	printf("*****2.ģʽ��*****\n");
	printf("*****3.ģʽ��*****\n");
	printf("*****0.exit  *****\n");
	printf("������ģʽ : ");
}


int isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	else

	{
		return 0;
	}
}


void calender1(int year)
{
	year -= 1;
	int f = 37 + year + year / 4 - year / 100 + year / 400;
	f = f % 7 - 1;
	if (f == -1) f = 6;
	year++;

	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(year))
	{
		daysInMonth[1] = 29;
	}

	printf("|==================Calendar for the year %d===================|\n", year);
	printf("|                                                               |\n");
	printf("|                                                               |\n");

	for (int pair = 0; pair < 6; pair++)
	{
		int left_month = pair;
		int right_month = pair + 6;

		printf("|------ %d ------                                ", left_month + 1);
		if (right_month + 1 < 10)
		{
			printf("------ %d ------ |\n", right_month + 1);
		}
		else
		{
			printf("------ %d ----- |\n", right_month + 1);
		}
		printf("|Sun Mon Tue Wed Thu Fri Sat        ");
		printf("Sun Mon Tue Wed Thu Fri Sat |\n");


		int left_start = f;
		for (int i = 0; i < left_month; i++)
		{
			left_start = (left_start + daysInMonth[i]) % 7;
		}


		int right_start = f;
		for (int i = 0; i < right_month; i++)
		{
			right_start = (right_start + daysInMonth[i]) % 7;
		}


		int left_day = 1, right_day = 1;
		while (left_day <= daysInMonth[left_month] || right_day <= daysInMonth[right_month])
		{
			printf("|");
			for (int i = 0; i < 7; i++)
			{
				if (i < left_start && left_day == 1)
				{
					printf("    ");
				}
				else if (left_day <= daysInMonth[left_month])
				{
					printf("%3d ", left_day++);
				}
				else
				{
					printf("    ");
				}
			}

			printf("       ");


			for (int i = 0; i < 7; i++)
			{
				if (i < right_start && right_day == 1)
				{
					printf("    ");
				}
				else if (right_day <= daysInMonth[right_month])
				{
					printf("%3d ", right_day++);
				}
				else
				{
					printf("    ");
				}
			}

			printf("|\n");
			left_start = 0;
			right_start = 0;
		}
		printf("|                                                               |\n");
	}
	printf("|===============================================================|\n");
}


void calender2(int year, int month)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}

	int f = (13 * (month + 1)) / 5 + 1 + year + (year / 4) - (year / 100) + (year / 400);

	f = f % 7;

	if (f == 0)
	{
		f = 6;
	}
	else
	{
		f -= 1;
	}

	year++;
	if (month == 13)
		month = 1;
	else if (month == 14)
		month = 2;

	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeapYear(year))
	{
		daysInMonth[1] = 29;
	}
	printf("Calendar for the year %d month %d:\n\n", year, month);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	int currentDay = f;
	for (int i = 0; i < currentDay; i++)
	{
		printf("    ");
	}
	month--;
	for (int day = 1; day <= daysInMonth[month]; day++)
	{
		printf("%3d ", day);
		currentDay++;

		if (currentDay > 6)
		{
			currentDay = 0;
			printf("\n");
		}
	}
	printf("\n\n");
}


void calender3(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}

	int f = (13 * (month + 1)) / 5 + day + year + (year / 4) - (year / 100) + (year / 400);

	f = f % 7;

	if (f == 0)
	{
		f = 6;
	}
	else
	{
		f -= 1;
	}
	f++;
	if (month == 13)
		month = 1;
	else if (month == 14)
		month = 2;
	year++;
	if (month == 1 && day == 1)
		printf("%d��%d��%d������%d,ΪԪ���ڡ�\n", year, month, day, f);
	else if (month == 2 && day == 14)
		printf("%d��%d��%d������%d,Ϊ���˽ڡ�\n", year, month, day, f);
	else if (month == 3 && day == 8)
		printf("%d��%d��%d������%d,Ϊ��Ů�ڡ�\n", year, month, day, f);
	else if (month == 3 && day == 12)
		printf("%d��%d��%d������%d,Ϊֲ���ڡ�\n", year, month, day, f);
	else if (month == 4 && day == 1)
		printf("%d��%d��%d������%d,Ϊ���˽ڡ�\n", year, month, day, f);
	else if (month == 5 && day == 1)
		printf("%d��%d��%d������%d,Ϊ�Ͷ��ڡ�\n", year, month, day, f);
	else if (month == 5 && day == 4)
		printf("%d��%d��%d������%d,Ϊ����ڡ�\n", year, month, day, f);
	else if (month == 6 && day == 1)
		printf("%d��%d��%d������%d,Ϊ��ͯ�ڡ�\n", year, month, day, f);
	else if (month == 7 && day == 1)
		printf("%d��%d��%d������%d,Ϊ�����ڡ�\n", year, month, day, f);
	else if (month == 8 && day == 1)
		printf("%d��%d��%d������%d,Ϊ�����ڡ�\n", year, month, day, f);
	else if (month == 9 && day == 10)
		printf("%d��%d��%d������%d,Ϊ��ʦ�ڡ�\n", year, month, day, f);
	else if (month == 12 && day == 25)
		printf("%d��%d��%d������%d,Ϊʥ���ڡ�\n", year, month, day, f);
	else if (month == 12 && day == 24)
		printf("%d��%d��%d������%d,Ϊƽ��ҹ��\n", year, month, day, f);
	else if (month == 10 && day == 1)
		printf("%d��%d��%d������%d,Ϊ����ڡ�\n", year, month, day, f);
	else
		printf("%d��%d��%d������%d,�޽ڼ��ա�\n", year, month, day, f);
}


int main()
{
	int mode = 0;
	do {
		mune();
		scanf_s("%d", &mode);
		if (mode == 1)
		{
			printf("��������� : ");
			int year = 0;
			scanf("%d", &year);
			calender1(year);
		}
		else if (mode == 2)
		{
			printf("���������,�·� : ");
			int year = 0;
			int month = 0;
			scanf("%d %d", &year, &month);
			calender2(year, month);
		}
		else if (mode == 3)
		{
			printf("���������,�·�,���� : ");
			int year = 0;
			int month = 0;
			int day = 0;
			scanf("%d %d %d", &year, &month, &day);
			calender3(year, month, day);
		}
		else if (mode == 0)
		{
			printf("��ӭ�´�ʹ��");
		}
		else
		{
			printf("err\n");
			printf("���ٴ����� : ");
		}
	} while (mode);
	return 0;
}