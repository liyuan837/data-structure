#include <iostream>
using namespace std;

/**
 * ˳���ṹ�嶨��
 */
#define LISTSIZE 100
typedef int DataType;
typedef struct SeqList
{
	DataType data[LISTSIZE];
	int length;
}SeqList;

/**
 * ˳����ʼ��
 */
void initList(SeqList* list) {
	list->length = 0;
}
/**
 * ���Ա��п�
 */
bool listEmpty(SeqList* list) {
	return list->length == 0;
}
/**
 * ���˳���������Ԫ��
 */
void clearList(SeqList* list) {
	list->length = 0;
}
/**
 * ��ȡ˳���������Ԫ�ظ���
 */
int listLength(SeqList* list) {
	return list->length;
}
/**
 * ��ȡ���Ա�ָ��λ�õ�Ԫ��
 */
DataType* getElem(SeqList* list, int i) {
	if (i < 0 || i > list->length - 1) {
		return NULL;
	}
	return &list->data[i];
}
/**
 * ��ȡԪ����˳����е�λ��
 */
int locateElem(SeqList* list, DataType x) {
	for (int i = 0;i < list->length;i++) {
		if (list->data[i] == x) {
			return i;
		}
	}
	return -1;
}
/**
 * ��Ԫ�ز���ָ��λ��
 */
int insertList(SeqList* list, int pos, DataType elem) {
	//[1]�ж���������
	if (list->length == LISTSIZE) {
		return -1;
	}
	//[2]�ж��Ƿ�Խ��
	if (pos < 0 || pos > list->length) {
		return -1;
	}
	//[3]Ԫ�غ���
	for (int i = list->length;i > pos;i--) {
		list->data[i] = list->data[i - 1];
	}
	//[4]����ֵ��˳���������
	list->data[pos] = elem;
	list->length++;
	return pos;
}

/**
 * ɾ��˳���ָ��λ��Ԫ��
 */
int removeElem(SeqList* list, int pos) {
	//[1]�ж�Խ��
	if (pos < 0 || pos > list->length - 1) {
		return -1;
	}
	//[2]ǰ��
	for (int i = pos;i < list->length - 1;i++) {
		list->data[i] = list->data[i + 1];
	}
	//[3]˳�����--
	list->length--;
	return 1;
}

/**
 * ��ӡ˳���
 */
void printList(SeqList* list) {
	for (int i = 0;i < list->length;i++) {
		cout << list->data[i] << " ";
	}
	cout << endl;
}

/**
 * ��ӡԪ��
 */
void printElem(DataType elem) {
	cout << elem << " ";
}

/**
 * ����˳���
 */
void travel(SeqList* list, void(*visitFun)(DataType)) {
	for (int i = 0;i < list->length;i++) {
		visitFun(list->data[i]);
	}
}

void unionList(SeqList* list1, SeqList* list2) {
	if (list1->length + list2->length > LISTSIZE) {
		return;
	}
	for (int i = 0;i < list2->length;i++) {
		if (locateElem(list1, list2->data[i]) < 0) {
			insertList(list1, list1->length, list2->data[i]);
		}
	}
}

int main1()
{
	SeqList list1, list2;
	initList(&list1);
	initList(&list2);

	insertList(&list1, 0, 1);
	insertList(&list1, 0, 3);
	insertList(&list1, 0, 2);
	printList(&list1);

	insertList(&list2, 0, 2);
	insertList(&list2, 1, 5);
	insertList(&list2, 2, 7);

	unionList(&list1, &list2);
	printList(&list1);

	travel(&list1, printElem);
	return 0;
}