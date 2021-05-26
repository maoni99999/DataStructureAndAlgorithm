#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//枚举，将这个栈改成模板形式的，栈可是指向某种数据结构的内存区域，详情见circlelist的不改变链表形式从尾到头打印链表
enum Status {true_,false_};
typedef int stacktype;

class SqStack
{
public:
	stacktype* base;
	stacktype* top;
private:
	int stacksize;
public:
	SqStack(int sizeofstack);
public:
	Status StackEmpty();
	Status PushStack(stacktype data);
	Status UnStack(stacktype& data);
};
//构造函数初始化
SqStack::SqStack(int sizeofstack)
{
	stacksize = sizeofstack;
	this->base = new stacktype[sizeofstack];
	this->top = this->base;
}
//判断是否为空
Status SqStack::StackEmpty()
{
	if (base == top)
		return true_;
	else
		return false_;
}
//
Status SqStack::PushStack(stacktype data)
{
	if ((top - base) == stacksize)
	{
		cout << "stack is full!Push failed!" << endl;
		return false_;
	}
	else
	{
		*top = data;
		top++;
		return true_;
	}

}
//出栈
Status SqStack::UnStack(stacktype& data)
{
	if (top==base)
	{
		cout << "this stack is empty!" << endl;
		return false_;
	}
	else
	{
		data = *(--top);
		return true_;
	}
}
int main1()
{
	SqStack mystack(3);
	while (mystack.StackEmpty() != true_);
	mystack.PushStack(1);
	mystack.PushStack(2);
	cout << "over!" << endl;
	return 0;
}