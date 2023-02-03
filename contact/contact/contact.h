#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 30
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT 3
#define SZ 2


typedef struct Peoinfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Peoinfo;

typedef struct Contact
{
	Peoinfo* data;
	int sz;
	int capicity;
}Contact;

void InitContact(Contact* pc);
void DestoryContact(Contact* pc);
void ADD(Contact* pc);
void PRINT(Contact* pc);
void DEL(Contact* pc);
void SEARCH(Contact* pc);
void MODIFY(Contact* pc);
void SORT(Contact* pc);
void SAVE(Contact* pc);