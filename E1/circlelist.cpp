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
//��������β�ڵ�ָ��nullptr����û��ͷ�ڵ㣬�������һ���ڵ㲻��Ϊ��
Node* GenerateList(int number)
{
	//��һ��������ͷ��㣬���Ϊָ�룬����һ��Ҫ��ʼ������ʼ��ָ����ָ���ֵ������ַ�������⣬����ָ��nullptr
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
//������βָ���ʾ��ѭ���б�ע�⣺���漰���������ǣ�ѭ������Ӧ�ø�Ϊwhile(p->next!=head),����null
//����ѭ��������βָ������㣻ͬʱ��ͷ�ڵ�
Node* GenerateCircleList(int number)
{
	//��һ��������ͷ��㣬���Ϊָ�룬����һ��Ҫ��ʼ������ʼ��ָ����ָ���ֵ������ַ�������⣬����ָ��nullptr
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
//�����βָ���ʾ��ѭ������
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
//�ϲ�������βָ���ʾ��ѭ������
Node* MergeTwoCircleList(Node* list1,Node* list2)
{
	Node* head = list1->next;
	list1->next = list2->next->next;
	delete list2->next;
	list2->next = head;
	return list2;
}
//��תһ����������
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
//�ڲ���ת����ķ�ʽ��ͷ��β�����������ջ��,������ʽ
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
//�ڲ���ת����ķ�ʽ��ͷ��β�����������ջ��,�ݹ���ʽ
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