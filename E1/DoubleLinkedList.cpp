#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//����ķ�ʽʵ��˫������ѭ��˫������
//����������������洢������Ϊint�ͣ�������template����������Ķ�������
//c++�����࣬���й��캯��������Ĭ�ϳ�ʼ����������C�Ľṹ�壬�����ڴ�ʱDNode�����ָ��ָ��0xccccc��
struct DNode {
public:
	int data;
	DNode* prior;
	DNode* next;
public:
	DNode() {}
	DNode(int data_, DNode* prior_, DNode* next_)
	{
		this->data = data_;
		this->prior = prior_;
		this->next = next_;
	}
};
//����˫��ѭ������
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void append_last(int t);
	void insert_node(int value, int index);
	void printList();
private:
	DNode* head;
	int count;
private:
	DNode* getnode(int index);
};
//���캯��
DoubleLinkedList::DoubleLinkedList():count(0)
{
	head = new DNode();
	head->next = head->prior = head;
	head->data = -1;
}
//�����������Ժ����.����������С���򣬳�����ֹ���ʹ����ڴ汻�ͷ���
DoubleLinkedList::~DoubleLinkedList()
{
	//�ͷ����нڵ���ռ���ڴ�
	DNode* tmpnode = head->next;
	while (tmpnode != head)
	{
		DNode* p = tmpnode;
		tmpnode = tmpnode->next;
		delete p;
	}
	delete head;
	head = nullptr;

}
DNode* DoubleLinkedList::getnode(int index)
{
	
	if (index<0 || index>count)
		cout << "get node failed, the index is out of the bound!" << endl;
	else
		if (index <= count / 2)
		{
			DNode* index_node = head;
			int i = 1;	
			while (i++ < index)
			{
				index_node = index_node->next;
			}
			return index_node;
		}
		else
		{
			DNode* index_node = head->prior;
			int i = 0;
			while (i++ <=(count - index))
			{
				index_node = index_node->prior;
			}
			return index_node;
		}
	
}
//ʵ��β����ӽڵ�
void DoubleLinkedList::append_last(int t)
{
	DNode* new_node = new DNode(t, head->prior, head);
	head->prior->next = new_node;
	head->prior = new_node;
	new_node->data = t;
	count++;
}
void DoubleLinkedList::insert_node(int value, int index)
{
	if (index == 0)
	{
		//��һ���ڵ�
		DNode* new_node = new DNode(value, head, head);
		head->prior = new_node;
		head->next = new_node;
		new_node->data = value;
		count++;
	}
	else
	{
		DNode* index_last_node = getnode(index);
		DNode* new_node = new DNode(value, index_last_node, index_last_node->next);
		index_last_node->next = new_node;
		new_node->next->prior = new_node;
		new_node->data = value;
		count++;
	}
}
void DoubleLinkedList::printList()
{
	cout << "the list is:" << endl;
	DNode* tmpnode = head;
	tmpnode = tmpnode->next;
	while (tmpnode != head)
	{
		cout << tmpnode->data << endl;
		tmpnode = tmpnode->next;
	}
}
int main3()
{
	DoubleLinkedList* dlist = new DoubleLinkedList();
	dlist->insert_node(1, 0);
	dlist->append_last(2);
	dlist->append_last(3);
	dlist->append_last(4);
	dlist->append_last(5);
	dlist->printList();
	dlist->insert_node(8, 3);
	dlist->printList();
	return 0;
}