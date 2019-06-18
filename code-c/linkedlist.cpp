//// code-c.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//using namespace std;
//
//typedef int datatype;
//typedef struct node {
//	datatype data;
//	node* next;
//}node;
///**
//* 获取指定位置元素节点
//*/
//node* getelem(node* head, int pos) {
//	if (pos < 0) {
//		return null;
//	}
//	if (pos == 0) {
//		return head;
//	}
//	node* p = head;
//	for (int i = 0; i < pos && p; i++) {
//		p = p->next;
//	}
//	return p;
//}
///**
// * 获取链表节点数量
// */
//int listlength(node* head) {
//	int count = 0;
//	node* p = head;
//	while (p) {
//		count++;
//		p = p->next;
//	}
//	return count;
//}
//
///**
// * 在指定位置插入元素
// */
//bool insertlist(node** head, int pos, datatype data) {
//	//[1]判断位置是否合法
//	if (pos <0 || pos > listlength(*head)) {
//		return false;
//	}
//	//[2]构建新节点
//	node* newnode = (node*)malloc(sizeof(node));
//	newnode->data = data;
//	newnode->next = null;
//
//	//[3]特殊处理头部插入
//	if (pos == 0) {
//		newnode->next = *head;
//		*head = newnode;
//		return true;
//	}
//
//	//[4]定位到pos-1节点
//	node* p = *head;
//	for (int i = 0; i < pos - 1;i++) {
//		p = p->next;
//	}
//	newnode->next = p->next;
//	p->next = newnode;
//	return true;
//}
///**
// * 刪除指定位置元素节点
// */
//bool removeelem(node** head,int pos) {
//	//[1]判断位置是否合法
//	if (pos < 0 || pos > listlength(*head)) {
//		return false;
//	}
//	node* p = (*head);
//	//[2]头部删除
//	if (pos == 0) {
//		*head = p->next; 
//		free(p);
//		p = null;
//	}
//	//[3]定位pos-1节点
//	for (int i = 0; i < pos - 1; i++) {
//		p = p->next;
//	}
//	node* delnode = p->next;
//	p->next = delnode->next;
//	free(delnode);
//	delnode = null;
//	return true;
//}
///**
// * 链表简单合并
// */
//void unionlist(node* a, node* b) {
//	node* p = a;
//	while (p->next) {
//		p = p->next;
//	}
//	p->next = b;
//}/**
//  * 单链表倒置
//  */
//void reverse(node** head) {
//	//[1]单链表为空表或者只有一个元素，直接返回
//	if (*head == null || (*head)->next == null) {
//		return;
//	}
//	node* p = *head;
//	node* q = p->next;
//	node* r = q->next;
//	p->next = null;
//	while (true) {
//		q->next = p;
//		if (r == null) {
//			*head = q;
//			break;
//		}
//		else {
//			p = q;
//			q = r;
//			r = r->next;
//		}
//	}
//}
//
//void printelem(datatype data) {
//	cout << data << " ";
//}
///**
// * 遍历单链表
// */
//void travel(node* head,void(*fun)(datatype)) {
//	node* p = head;
//	while (p) {
//		fun(p->data);
//		p = p->next;
//	}
//}
//
//int main1()
//{
//	node* head1 = null;
//	insertlist(&head1, 0, 1);
//	insertlist(&head1, 0, 2);
//	insertlist(&head1, 0, 3);
//	insertlist(&head1, 0, 4);
//
//	node* head2 = null;
//	insertlist(&head2, 0,4);
//	insertlist(&head2, 0, 5);
//	insertlist(&head2, 0, 1);
//	insertlist(&head2, 0, 7);
//	cout << getelem(head1, 2)->data;
//	unionlist(head1, head2);
//	cout << listlength(head1);
//
//	reverse(&head1);
//	travel(head1,printelem);
//	cout << getelem(head1,1)->data;
//	return 0;
//}
