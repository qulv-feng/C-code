#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX 100

#define MAX_NAME 20
#define MAX_GENDER 10
#define MAX_TEL 30
#define MAX_ADD 50

#define DEFAULT_SZ 3
#define INC_SZ 2


typedef struct Pelinfo
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tel[MAX_TEL];
	char address[MAX_ADD];
}Peoinfo;



typedef struct Contact
{
	Peoinfo* date;
	int count;
	int capacity;
}Contact;


void AddCon(Contact* p);

void InitCon(Contact* p);

void SearchCon(Contact* p);

void ShowCon(Contact* p);

void Modify(Contact* p);

void DeleteCon(Contact* p);

void SortCon(Contact* p);

int FindName(Contact* p, char* str);

void CheckCapacity(Contact* p);

void DestoryContact(Contact* p);

void SaveContact(Contact* p);

void SaveContact(Contact* p);

