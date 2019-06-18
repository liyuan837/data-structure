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
/**
 * 链表简单合并
 */
void unionList(Node* a, Node* b) {
	Node* p = a;
	while (p->next) {
		p = p->next;
	}
	p->next = b;
}/**
  * 单链表倒置
  */
void reverse(Node** head) {
	//[1]单链表为空表或者只有一个元素，直接返回
	if (*head == NULL || (*head)->next == NULL) {
		return;
	}
	Node* p = *head;
	Node* q = p->next;
	Node* r = q->next;
	p->next = NULL;
	while (true) {
		q->next = p;
		if (r == NULL) {
			*head = q;
			break;
		}
		else {
			p = q;
			q = r;
			r = r->next;
		}
	}
}

void printElem(DataType data) {
	cout << data << " ";
}
/**
 * 遍历单链表
 */
void travel(Node* head,void(*fun)(DataType)) {
	Node* p = head;
	while (p) {
		fun(p->data);
		p = p->next;
	}
}

int main()
{
	Node* head1 = NULL;
	insertList(&head1, 0, 1);
	insertList(&head1, 0, 2);
	insertList(&head1, 0, 3);
	insertList(&head1, 0, 4);

	Node* head2 = NULL;
	insertList(&head2, 0,4);
	insertList(&head2, 0, 5);
	insertList(&head2, 0, 1);
	insertList(&head2, 0, 7);
	cout << getElem(head1, 2)->data;
	unionList(head1, head2);
	cout << listLength(head1);

	reverse(&head1);
	travel(head1,printElem);
	cout << getElem(head1,1)->data;
}
