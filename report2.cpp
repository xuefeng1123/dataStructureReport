#include<cstdio>
#include<iostream>
using namespace std;

#define MAX_SIZE 15

typedef struct{
	int intArray[MAX_SIZE];
	int size;
}orderList;

orderList* initOrderList() {
	orderList* list = (orderList*)malloc(sizeof(orderList));
	list->size = 0;
	return list;
}

void showOrderList(orderList* list) {
	cout << "\nlist:\n";
	for (int i = 0; i < list->size; i++) {
		cout << "list[" << i << "] = " << (list->intArray)[i] << "\n";
	}
}

void insert(orderList* list, int location, int elements[],int elementsSize) {
	if (list->size == 0) {
		for (int i = 0; i < elementsSize; i++) {
			(list->intArray)[i] = elements[i];
		}
		list->size = elementsSize;
		showOrderList(list);
		return;
	}
	if (location > list->size || location < 1) {
		cout << "ERROR: the location not exists in the list!\n" << endl;
		return;
	}
	if (elementsSize + list->size > MAX_SIZE) {
		cout << "ERROR: insert too much data!\n" << endl;
		return;
	}
	for (int i = list->size - 1; i >= location - 1; i--) {
		(list->intArray)[i + elementsSize] = (list->intArray)[i];
	}
	for (int j = 0; j < elementsSize; j++) {
		(list->intArray)[location + j - 1] = elements[j];
	}
	list->size += elementsSize;
	showOrderList(list);
}

void deleteOneElement(orderList* list, int location) {
	if (location > list->size || location < 1) {
		cout << "ERROR: the location not exists in the list!\n" << endl;
		return;
	}
	for (int i = location - 1; i < list->size - 1; i++) {
		(list->intArray)[i] = (list->intArray)[i + 1];
	}
	(list->intArray)[list->size - 1] = 0;
	list->size--;
	showOrderList(list);
}

int main() {
	int a[5] = { 2,3,6,3,23 };
	int b[2] = { 4,4 };
	int c[10] = { 2,3,6,3,23,2,3,6,3,23 };
	orderList* list =  initOrderList();
	insert(list, 0, a, 5);
	insert(list, 3, b, 2);
	insert(list, 7, b, 2);
	insert(list, 10, b, 2);
	insert(list, 3, c, 10);
	deleteOneElement(list, 2);
	deleteOneElement(list, 1);
	deleteOneElement(list, 7);
	deleteOneElement(list, 7);
	int o;
	cin >> o;
}