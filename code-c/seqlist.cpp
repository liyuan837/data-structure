#include <iostream>
using namespace std;

/**
 * 顺序表结构体定义
 */
#define LISTSIZE 100
typedef int DataType;
typedef struct SeqList
{
	DataType data[LISTSIZE];
	int length;
}SeqList;

/**
 * 顺序表初始化
 */
void initList(SeqList* list) {
	list->length = 0;
}
/**
 * 线性表判空
 */
bool listEmpty(SeqList* list) {
	return list->length == 0;
}
/**
 * 清除顺序表中所有元素
 */
void clearList(SeqList* list) {
	list->length = 0;
}
/**
 * 获取顺序表中数据元素个数
 */
int listLength(SeqList* list) {
	return list->length;
}
/**
 * 获取线性表指定位置的元素
 */
DataType* getElem(SeqList* list, int i) {
	if (i < 0 || i > list->length - 1) {
		return NULL;
	}
	return &list->data[i];
}
/**
 * 获取元素在顺序表中的位置
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
 * 将元素插入指定位置
 */
int insertList(SeqList* list, int pos, DataType elem) {
	//[1]判断数组已满
	if (list->length == LISTSIZE) {
		return -1;
	}
	//[2]判断是否越界
	if (pos < 0 || pos > list->length) {
		return -1;
	}
	//[3]元素后移
	for (int i = list->length;i > pos;i--) {
		list->data[i] = list->data[i - 1];
	}
	//[4]插入值，顺序表长度自增
	list->data[pos] = elem;
	list->length++;
	return pos;
}

/**
 * 删除顺序表指定位置元素
 */
int removeElem(SeqList* list, int pos) {
	//[1]判断越界
	if (pos < 0 || pos > list->length - 1) {
		return -1;
	}
	//[2]前移
	for (int i = pos;i < list->length - 1;i++) {
		list->data[i] = list->data[i + 1];
	}
	//[3]顺序表长度--
	list->length--;
	return 1;
}

/**
 * 打印顺序表
 */
void printList(SeqList* list) {
	for (int i = 0;i < list->length;i++) {
		cout << list->data[i] << " ";
	}
	cout << endl;
}

/**
 * 打印元素
 */
void printElem(DataType elem) {
	cout << elem << " ";
}

/**
 * 遍历顺序表
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