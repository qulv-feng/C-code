#include <stdio.h>

void mune()
{
	printf("******************\n");
	printf("*****1.模式一*****\n");
	printf("*****2.模式二*****\n");
	printf("*****0.exit  *****\n");
	printf("请输入模式\n");
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
	if (f == -1)
		f = 6;
	year++;

	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeapYear(year))
	{
		daysInMonth[1] = 29;
	}
	printf("Calendar for the year %d:\n\n", year);
	for (int month = 0; month < 12; month++)
	{
		printf("------ %d ------\n", month + 1);
		printf("Sun Mon Tue Wed Thu Fri Sat\n");
		int currentDay = f;
		for (int i = 0; i < currentDay; i++)
		{
			printf("    ");
		}

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

		f = currentDay;
	}
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
	printf("Calendar for the year %d month %d:\n\n", year,month);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	int d = 0;
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

int main()
{
	int mode = 0;
	do {
		mune();
		scanf("%d", &mode);
		if (mode == 1)
		{
			printf("请输入年份\n");
			int year = 0;
			scanf("%d", &year);
			calender1(year);
		}
		else if (mode == 2)
		{
			printf("请输入年份,月份\n");
			int year = 0;
			int month = 0;
			scanf("%d %d", &year, &month);
			calender2(year, month);
		}
		else if (mode == 0)
		{
			printf("欢迎下次使用");
		}
		else
		{
			printf("err\n");
			printf("请再次输入\n");
		}
	} while (mode);
	return 0;
}