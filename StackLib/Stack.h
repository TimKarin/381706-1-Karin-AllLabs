#pragma once
#include <iostream>
#include "Exeption.h"
using namespace std;

template <class T>
class TStack {
protected:
	int size;
	int top;
	T* mas;
public:
	TStack<T> (int n=0);
	TStack<T> (TStack<T> &A);
	void Put (T A);
	T Get();
	int GetSize();
	bool IsFull();
	bool IsEmpty();
};

template <class T>
TStack<T>::TStack(int n){
	if (n < 0)
	{
		TExeption Ex("negative size", "TStack", "TStack", 1);
		throw Ex;
	}
	else if (n == 0) {
		size = 0;
		top = 0;
		mas = nullptr;
	}
	else {
		size = n;
		top = 0;
		mas = new T[size];
	}
}

template <class T>
TStack<T>::TStack(TStack<T> &A) {
	top = A.top;
	size = A.size;
	if (size == 0)
		mas = 0;
	else
		mas = new T[size];
	for (int i = 0; i < size; i++) {
		mas[i] = A.mas[i];
	}
}

template <class T>
void TStack<T>::Put(T A) {
	if (IsFull())
	{
		TExeption Ex("full stack", "TStack", "Put", 2);
		throw Ex;
	}
	mas[top] = A;
	top++;
}

template <class T>
T TStack<T>::Get(){
	if (IsEmpty())
	{
		TExeption Ex("empty stack", "TStack", "Get", 3);
		throw Ex;
	}
	else {
		top--;
		return mas[top];
	}
}

template <class T>
int TStack<T>::GetSize() {
	return size;
}

template <class T>
bool TStack<T>::IsFull() {
	if (top >= size)
		return true;
	else
		return false;
}

template <class T>
bool TStack<T>::IsEmpty(){
	if (top == 0)
		return true;
	else
		return false;
}
