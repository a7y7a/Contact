#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void menu()
{
	printf("*******1.add         2.del   *****\n");
	printf("*******3.search      4.modify*****\n");
	printf("*******5.sort        6.print*****\n");
	printf("*******       0.exit         *****\n");
}

enum Option
{
	exi,
	add,
	del,
	search,
	modify,
	sort,
	print
};

int main()
{
	Contact con;
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case exi:
			printf("ÍË³ö\n");
			SAVE(&con);
			DestoryContact(&con);
			break;
		case add:
			ADD(&con);
			break;
		case del:
			DEL(&con);
			break;
		case search:
			SEARCH(&con);
			break;
		case modify:
			MODIFY(&con);
			break;
		case sort:
			SORT(&con);
			break;
		case print:
			PRINT(&con);
			break;
		default:
			printf("´íÁË\n");
			break;
		}
	} while (input);
	return 0;
}