// code-c.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

typedef int DataType;
typedef struct Node {
	DataType data;
	Node* next;
}Node;
/**
* 获取指定位置元素节点
*/
Node* getElem(Node* head, int pos) {
	if (pos < 0) {
		return NULL;
	}
	if (pos == 0) {
		return head;
	}
	Node* p = head;
	for (int i = 0; i < pos && p; i++) {
		p = p->next;
	}
	return p;
}
/**
 * 获取链表节点数量
 */
int listLength(Node* head) {
	int count = 0;
	Node* p = head;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

/**
 * 在指定位置插入元素
 */
bool insertList(Node** head, int pos, DataType data) {
	//[1]判断位置是否合法
	if (pos <0 || pos > listLength(*head)) {
		return false;
	}
	//[2]构建新节点
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	//[3]特殊处理头部插入
	if (pos == 0) {
		newNode->next = *head;
		*head = newNode;
		return true;
	}

	//[4]定位到pos-1节点
	Node* p = *head;
	for (int i = 0; i < pos - 1;i++) {
		p = p->next;
	}
	newNode->next = p->next;
	p->next = newNode;
	return true;
}
/**
 * 刪除指定位置元素节点
 */
bool removeElem(Node** head,int pos) {
	//[1]判断位置是否合法
	if (pos < 0 || pos > listLength(*head)) {
		return false;
	}
	Node* p = (*head);
	//[2]头部删除
	if (pos == 0) {
		*head = p->next; 
		free(p);
		p = NULL;
	}
	//[3]定位pos-1节点
	for (int i = 0; i < pos - 1; i++) {
		p = p->next;
	}
	Node* delNode = p->next;
	p->next = delNode->next;
	free(delNode);
	delNode = NULL;
	return true;
}

int main()
{
	Node* head = NULL;
	insertList(&head, 0, 1);
	insertList(&head, 0, 2);
	insertList(&head, 0, 3);
	insertList(&head, 0, 4);
	cout << getElem(head, 2)->data;
	removeElem(&head, 1);
	cout << getElem(head, 2)->data;
}
