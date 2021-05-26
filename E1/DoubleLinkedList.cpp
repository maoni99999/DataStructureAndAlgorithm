#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//用类的方式实现双向链表循环双向链表
//假设我们链表里面存储的数据为int型，可以用template操作想操作的对象类型
//c++定义类，类有构造函数，可以默认初始化（类似于C的结构体，开辟内存时DNode对象的指针指向0xccccc）
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
//构建双向循环链表
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
//构造函数
DoubleLinkedList::DoubleLinkedList():count(0)
{
	head = new DNode();
	head->next = head->prior = head;
	head->data = -1;
}
//析构函数，稍后完成.对于我这种小程序，程序终止不就代表内存被释放嘛
DoubleLinkedList::~DoubleLinkedList()
{
	//释放所有节点所占的内存
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
//实现尾端添加节点
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
		//第一个节点
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