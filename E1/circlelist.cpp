#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<queue>

using namespace std;
struct Node {
	int data;
	Node* next;
};
//单链表，且尾节点指向nullptr；且没有头节点，即链表第一个节点不是为空
Node* GenerateList(int number)
{
	//第一步，生成头结点，结点为指针，所以一定要初始化，初始化指的是指针的值，即地址不能任意，这里指向nullptr
	Node* head;
	head = nullptr;
	Node* p1, * p2;
	p1 = nullptr;
	p2 = nullptr;
	for (int i = 1; i <= number; i++)
	{
		p1 = (Node*)malloc(sizeof(Node));
		p1->data = i;
		if (head == nullptr)
		{
			head = p1;
			p2 = p1;
		}
		p2->next = p1;
		p2 = p1;
	}
	p2->next = nullptr;
	return head;
}
//建立用尾指针表示的循环列表，注意：在涉及遍历操作是，循环条件应该改为while(p->next!=head),而非null
//建立循环链表用尾指针更方便；同时带头节点
Node* GenerateCircleList(int number)
{
	//第一步，生成头结点，结点为指针，所以一定要初始化，初始化指的是指针的值，即地址不能任意，这里指向nullptr
	Node* head;
	head = nullptr;
	Node* realhead;
	realhead = (Node*)malloc(sizeof(Node));
	realhead->data = -1;

	Node* p1, * p2;
	p1 = nullptr;
	p2 = nullptr;
	for (int i = 1; i <= number; i++)
	{
		p1 = (Node*)malloc(sizeof(Node));
		p1->data = i;
		if (head == nullptr)
		{
			head = p1;
			p2 = p1;
		}
		p2->next = p1;
		p2 = p1;
	}
	realhead->next = head;
	p2->next = realhead;
	return p2;
}
//
void PrintList(Node* list)
{
	if (list == 0)
	{
		cout << "list is null" << endl;
	}
	while (list != 0)
	{
		cout << list->data << endl;
		list = list->next;
	}
}
//输出用尾指针表示的循环链表
void PrintCircleList(Node* list)
{
	if (list == 0)
	{
		cout << "list is null" << endl;
	}
	Node* head = list->next;
	list = list->next->next;
	while (list!= head)
	{
		cout << list->data << endl;
		list = list->next;
	}
	//do {
	//	cout << list->data << endl;
	//	list = list->next;
	//} 	while (list!= head);

}
//合并两个用尾指针表示的循环链表
Node* MergeTwoCircleList(Node* list1,Node* list2)
{
	Node* head = list1->next;
	list1->next = list2->next->next;
	delete list2->next;
	list2->next = head;
	return list2;
}
//反转一个单向链表
Node* ReverseList(Node* list)
{
	Node* tmpNode = list;
	Node* preNode = nullptr;
	while (tmpNode)
	{
		Node* nextNode = tmpNode->next;
		tmpNode->next = preNode;
		preNode = tmpNode;
		tmpNode = nextNode;
	}
	list = preNode;
	return list;
}
//在不反转链表的方式从头到尾输出链表（利用栈）,迭代形式
void PrintListReversely_iter(Node* node)
{
	stack<Node*> stackspace;
	Node* phead = node;
	while (node != nullptr)
	{
		stackspace.push(node);
		node = node->next;
	}
	while (!stackspace.empty())
	{
		phead = stackspace.top();
		cout << phead->data << endl;
		stackspace.pop();
	}
}
//在不反转链表的方式从头到尾输出链表（利用栈）,递归形式
void PrintListReversely_Recusive(Node* node)
{
	if (node == nullptr)
		return;
	else
	{
		//if(node->next!=nullptr)
		//{ 
			PrintListReversely_Recusive(node->next);
		//}
		
		cout << node->data << endl;;
	}
}

int main7()
{
	//Node* Mynode1 = GenerateCircleList(3);
	//Node* Mynode2 = GenerateCircleList(4);
	//Node* MergeNode = MergeTwoCircleList(Mynode1, Mynode2);
	//PrintCircleList(MergeNode);
	Node* node1 = GenerateList(5);
	PrintListReversely_iter(node1);
	PrintListReversely_Recusive(node1);
	return 0;
	//Mynode = ReverseList(Mynode);
	//PrintList(Mynode);
}