#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

static void CHEC(Contact* pc)
{
	if (pc->sz == pc->capicity)
	{
		Peoinfo* ptr = (Peoinfo*)realloc(pc->data, (pc->capicity + SZ) * sizeof(Peoinfo));
		if (ptr == NULL)
		{
			perror("InitContact");
			return;
		}
		pc->data = ptr;
		pc->capicity += SZ;
	}
}

static void LOADC(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "r");
	if (pf == NULL)
	{
		perror("SAVE");
		return;
	}
	int i = 0;
	while (fread(pc->data + i++, sizeof(Peoinfo), 1, pf))
	{
		pc->sz++;
		CHEC(pc);
	}
	fclose(pf);
	pf = NULL;
}

void InitContact(Contact* pc)
{
	Peoinfo* ptr = (Peoinfo*)calloc(DEFAULT, sizeof(Peoinfo));
	if (ptr == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->data = ptr;
	pc->sz = 0;
	pc->capicity = DEFAULT;
	LOADC(pc);
}

void SAVE(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("SAVE");
		return;
	}
	fwrite(pc->data, sizeof(Peoinfo), pc->sz, pf);
	fclose(pf);
	pf = NULL;
}

void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capicity = 0;
}

void ADD(Contact* pc)
{
	CHEC(pc);
	printf("请输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
}

void PRINT(Contact* pc)
{
	printf("%-30s\t%-10s\t%-10s\t%-12s\t%-30s\n", "名字", "性别", "年龄", "电话", "地址");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-30s\t", pc->data[i].name);
		printf("%-10s\t", pc->data[i].sex);
		printf("%-10d\t", pc->data[i].age);
		printf("%-12s\t", pc->data[i].tele);
		printf("%-30s\n", pc->data[i].addr);
	}
}

static int find(Contact* pc,char* name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (!strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void DEL(Contact* pc)
{
	char name[30] = { 0 };
	printf("删除的人名字;");
	scanf("%s", name);
	int pos = find(pc,name);
	if (pos == -1)
	{
		printf("不存在\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
}

void SEARCH(Contact* pc)
{
	char name[30] = { 0 };
	printf("查找的人名字;");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("不存在\n");
		return;
	}
	printf("%-30s\t", pc->data[pos].name);
	printf("%-10s\t", pc->data[pos].sex);
	printf("%-10d\t", pc->data[pos].age);
	printf("%-12s\t", pc->data[pos].tele);
	printf("%-30s\n", pc->data[pos].addr);
}

void MODIFY(Contact* pc)
{
	char name[30] = { 0 };
	printf("修改的人名字;");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("不存在\n");
		return;
	}
	printf("请输入名字：");
	scanf("%s", pc->data[pos].name);
	printf("请输入性别：");
	scanf("%s", pc->data[pos].sex);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入电话：");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pos].addr);
	printf("修改成功\n");
}

//void menu()
//{
//	printf("排序根据\n");
//	printf("*******1.name         2.sex*****\n");
//	printf("*******3.age         4.tele*****\n");
//	printf("*******       5.adr        *****\n");
//}

void SORT(Contact* pc)
{
	//menu();
	//int input = 0;
	//scanf("%d", &input);
	int i = 0,j = 0;
	for (i = 0; i < pc->sz - 1; i++)
	{
		for (j = 0; j < pc->sz - i - 1; j++)
		{
			if (strcmp(pc->data[i].name, pc->data[i + 1].name) > 0)
			{
				Peoinfo temp = pc->data[i];
				pc->data[i] = pc->data[i + 1];
				pc->data[i + 1] = temp;
			}
		}
	}
}