#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

#define MAX_NAME 20
#define MAX_GENDER 10
#define MAX_TEL 30
#define MAX_ADD 50


typedef struct Pelinfo
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tel[MAX_TEL];
	char address[MAX_ADD];
}Pelinfo;

typedef struct Contact
{
	Pelinfo date[MAX];
	int count;
}Contact;


void AddCon(Contact* p);

void InitCon(Contact* p);

void SearchCon(Contact* p);

void ShowCon(Contact* p);

void Monify(Contact* p);

void DelectCon(Contact* p);

void SortCon(Contact* p);

int FindName(Contact* p, char* str);



