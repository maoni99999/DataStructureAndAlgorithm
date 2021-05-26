#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//ö�٣������ջ�ĳ�ģ����ʽ�ģ�ջ����ָ��ĳ�����ݽṹ���ڴ����������circlelist�Ĳ��ı�������ʽ��β��ͷ��ӡ����
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
//���캯����ʼ��
SqStack::SqStack(int sizeofstack)
{
	stacksize = sizeofstack;
	this->base = new stacktype[sizeofstack];
	this->top = this->base;
}
//�ж��Ƿ�Ϊ��
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
//��ջ
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