// q1-Del.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class List 
{
public:
	int data;
	List *pNext;
	List *pPrev;
};

void DeleteElement(List *lst) 
{
	List *prev, *next;
	prev = lst->pPrev;
	next = lst->pNext;
	if (prev != nullptr)
		prev->pNext = lst->pNext;
	if (next != nullptr)
		next->pPrev = lst->pPrev;
	delete lst;
}

int main()
{
	List *A = new List;
	A->data = 1;
	A->pPrev = nullptr;
	A->pNext = new List;
	A->pNext->data = 2;
	A->pNext->pPrev = A;
	A->pNext->pNext = new List;
	A->pNext->pNext->data = 3;
	A->pNext->pNext->pPrev = A->pNext;
	A->pNext->pNext->pNext = nullptr;
	DeleteElement(A->pNext);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
