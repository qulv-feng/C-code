#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <time.h>

#define DEFAULT_SZ 3
#define INC_SZ 2

typedef struct Bookinfo
{
	char codenum[20];
	char name[20];
	char publishing_house[20];
    int state;
	char lendtime[26];
	int borrowtimes;
}Bookinfo;

typedef struct System
{
	Bookinfo* data;
	int count;
	int capacity;
}System;

enum Option
{
	EXIT,
	ADD,
	LEND,
	RETURN,
	RANK,
	DELETE,
	SHOW,
};


void InitSys(System* sys);

void LoadSys(System* sys);

void SaveSys(System* sys);

void DestroySys(System* sys);

void AddSys(System* sys);

void LendSys(System* sys);

void ReturnSys(System* sys);

void RankSys(System* sys);

void DeleteSys(System* sys);

void ShowSys(System* sys);

void CheckCapacity(System* sys);

int FindName(System* sys, char* str);

int cmp_peo_by_borrowtimes(const void* e1, const void* e2);

 