#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
//一个节点
template<class T>
struct DNode
{
public:
	T value;
	DNode* prev;
	DNode* next;
public:
	DNode() { }
	DNode(T t, DNode* prev, DNode* next) {
		this->value = t;
		this->prev = prev;
		this->next = next;
	}
};
//双向链表基本操作
template<class T>
class DoubleLink
{
public:
	DoubleLink();
	~DoubleLink();

	int size();//大小
	int is_empty();//判断是否为空

	T get(int index);//获取节点
	T get_first();//获取首节点
	T get_last();//获取尾节点

	int insert(int index, T t);
	int insert_first(T t);
	int append_last(T t);

	int del(int index);
	int delete_first();
	int delete_last();

private:
	int count;
	DNode<T>* phead;
private:
	DNode<T>* get_node(int index);
};

template<class T>
DoubleLink<T>::DoubleLink() : count(0)
{
	// 创建“表头”。注意：表头没有存储数据！
	phead = new DNode<T>();
	phead->prev = phead->next = phead;
	// 设置链表计数为0
	//count = 0;
}

// 析构函数
template<class T>
DoubleLink<T>::~DoubleLink()
{
	// 删除所有的节点
	DNode<T>* ptmp;
	DNode<T>* pnode = phead->next;
	while (pnode != phead)
	{
		ptmp = pnode;
		pnode = pnode->next;
		delete ptmp;
	}

	// 删除"表头"
	delete phead;
	phead = NULL;
}

// 返回节点数目
template<class T>
int DoubleLink<T>::size()
{
	return count;
}

// 返回链表是否为空
template<class T>
int DoubleLink<T>::is_empty()
{
	return count == 0;
}

// 获取第index位置的节点
template<class T>
DNode<T>* DoubleLink<T>::get_node(int index)
{
	// 判断参数有效性
	if (index < 0 || index >= count)
	{
		cout << "get node failed! the index in out of bound!" << endl;
		return NULL;
	}

	// 正向查找
	if (index <= count / 2)
	{
		int i = 0;
		DNode<T>* pindex = phead->next;
		while (i++ < index) {
			pindex = pindex->next;
		}

		return pindex;
	}

	// 反向查找
	int j = 0;
	int rindex = count - index - 1;
	DNode<T>* prindex = phead->prev;
	while (j++ < rindex) {
		prindex = prindex->prev;
	}

	return prindex;
}

// 获取第index位置的节点的值
template<class T>
T DoubleLink<T>::get(int index)
{
	return get_node(index)->value;
}

// 获取第1个节点的值
template<class T>
T DoubleLink<T>::get_first()
{
	return get_node(0)->value;
}

// 获取最后一个节点的值
template<class T>
T DoubleLink<T>::get_last()
{
	return get_node(count - 1)->value;
}

// 将节点插入到第index位置之前
template<class T>
int DoubleLink<T>::insert(int index, T t)
{
	if (index == 0)
		return insert_first(t);

	DNode<T>* pindex = get_node(index);
	DNode<T>* pnode = new DNode<T>(t, pindex->prev, pindex);
	pindex->prev->next = pnode;
	pindex->prev = pnode;
	count++;

	return 0;
}

// 将节点插入第一个节点处。
template<class T>
int DoubleLink<T>::insert_first(T t)
{
	DNode<T>* pnode = new DNode<T>(t, phead, phead->next);
	phead->next->prev = pnode;
	phead->next = pnode;
	count++;

	return 0;
}

// 将节点追加到链表的末尾
template<class T>
int DoubleLink<T>::append_last(T t)
{
	//增加一个节点，与四个箭头要改，两个从新建节点出去的，一个指向尾节点，一个指向头节点
	//另外两个节点要指向新建节点，分别从头指针和尾指针过来
	DNode<T>* pnode = new DNode<T>(t, phead->prev, phead);//第二个参数为尾节点，第三个参数为头节点
	phead->prev->next = pnode;
	phead->prev = pnode;
	count++;

	return 0;
}

// 删除index位置的节点
template<class T>
int DoubleLink<T>::del(int index)
{
	DNode<T>* pindex = get_node(index);
	pindex->next->prev = pindex->prev;
	pindex->prev->next = pindex->next;
	delete pindex;
	count--;

	return 0;
}

// 删除第一个节点
template<class T>
int DoubleLink<T>::delete_first()
{
	return del(0);
}

// 删除最后一个节点
template<class T>
int DoubleLink<T>::delete_last()
{
	return del(count - 1);
}



// 双向链表操作int数据
void int_test()
{
	int iarr[4] = { 10, 20, 30, 40 };//定义一个数组

	cout << "\n开始测试 int数据" << endl;
	// 创建双向链表
	DoubleLink<int>* pdlink = new DoubleLink<int>();

	pdlink->insert(0, 20);        // 将 20 插入到第5一个位置
	pdlink->append_last(10);    // 将 10 追加到链表末尾
	pdlink->insert_first(30);    // 将 30 插入到第一个位置

	// 双向链表是否为空
	cout << "is_empty()=" << pdlink->is_empty() << endl;
	// 双向链表的大小
	cout << "size()=" << pdlink->size() << endl;

	// 打印双向链表中的全部数据
	int sz = pdlink->size();
	for (int i = 0; i < sz; i++)
		cout << "pdlink(" << i << ")=" << pdlink->get(i) << endl;
}


int main()
{
	int_test();        // 演示向双向链表操作“int数据”。
	system("pause");
	return 0;
}