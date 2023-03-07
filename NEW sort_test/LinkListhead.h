#pragma once
#include<iostream>
using namespace std;

//µ¥Á´±í
struct LinkList{
	int date;
	LinkList* next;
};

//Ë«Á´±í
struct DoubleLinkList {
	int date;
	DoubleLinkList* prev;
	DoubleLinkList* next;
};