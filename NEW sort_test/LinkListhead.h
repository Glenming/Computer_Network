#pragma once
#include<iostream>
using namespace std;

//������
struct LinkList{
	int date;
	LinkList* next;
};

//˫����
struct DoubleLinkList {
	int date;
	DoubleLinkList* prev;
	DoubleLinkList* next;
};