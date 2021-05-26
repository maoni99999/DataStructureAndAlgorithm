#include <iostream>
#include <vector>
#include <algorithm>
#include "stdio.h"
using namespace std;
typedef char ElemType;
const int max_size = 100;
//���ڶ��������ֵݹ���ʽ�ı����㷨�����Խ�������������������Ҳ�������ķ�������
typedef struct BiNode {
	ElemType data;
	BiNode* lchild, * rchild;
}BiNode, * BiTree;
//�������
//�Ҿ��ò�̫�����������Ϊ�վͷ���
void PreTraverse(BiTree& T)
{
	if (T != nullptr)
	{
		cout << T->data << endl;
		PreTraverse(T->lchild);
		PreTraverse(T->rchild);
	}
}
//����һ�Ŷ�����
char Tdata[] = "abc##de#g##f##hi##j##";
void Create2btree(BiTree& T)
{
	
	static int i = 0;
	
	if (Tdata[i] != '\0')
	{
		//cout << Tdata[i] << endl;
		if (Tdata[i] == '#')
		{
			T = nullptr;
			i++;
		}
		else
		{
			if (!(T = new BiNode))
				return;
			T->data = Tdata[i];
			i++;
			Create2btree(T->lchild);
			Create2btree(T->rchild);
		}

	}
	//cout << "construct finished" << endl;
	return;

}
 //����һ�Ŷ�����
bool CopyTree(BiTree OrigianlTree, BiTree& NewTree) {
	if (OrigianlTree == nullptr)
	{
		NewTree = nullptr;
		return false;
	}
	//�ص㣬��ͬ�����ĵ���������Ϊ�գ�ҲҪ����ָ��ָ���
	else
	{
		NewTree = new BiNode;
		NewTree->data = OrigianlTree->data;
		CopyTree(OrigianlTree->lchild, NewTree->lchild);
		CopyTree(OrigianlTree->rchild, NewTree->rchild);
		return true;
	}
}
//��������������
//
int m = 0;
int n = 0;
int TreeDepth(BiTree OriginalTree)
{
	if (OriginalTree == nullptr)
		return 0;
	else
	{
		m = TreeDepth(OriginalTree->lchild);
		n = TreeDepth(OriginalTree->rchild);
		if (m > n) return m + 1;
		else return n + 1;
	}
}
//���ܽڵ���
//�ݹ�̫������
int TreeNodeNumber(BiTree T)
{
	if (T == nullptr)
		return 0;
	else
	{
		return TreeNodeNumber(T->lchild) + TreeNodeNumber(T->rchild) + 1;
	}
}
//��Ҷ�ӽڵ�����
//Ҷ�ӽڵ���=�������ϵ�Ҷ�ӽڵ���+�������ϵ�Ҷ�ӽڵ���
//Ҷ�ӽڵ����Ǹýڵ�����Ӻ��Һ��Ӷ�Ϊnullptr�����¼һ��Ҷ��,return 1
//�����һ����Ϊ�գ�˵��������Ҷ�ӽڵ㣬����һ������Ȼ���ٷֱ�ͳ���������Ӻ��Һ������ж��ٸ�Ҷ�ӽڵ㣬���������ɣ�
int TreeLeadNode(BiTree T)
{
	if (T == nullptr)
		return 0;
	if (T->lchild == nullptr && T->rchild == nullptr)
		return 1;
	else
	{
		return TreeLeadNode(T->lchild) + TreeLeadNode(T->rchild);
	}
}
//Ѱ�Ҷ�����ĳ���ڵ����һ�ڵ㣨���������������̽ڵ�
//��������Ȼ���˶�������ĳ����㣬�Ҷ������洢��ָ�򸸽���ָ�루next����
//�����ǿ������ҵ����ڵ㣬�ٶ���������������������������������ҵ�����������һ���
//��������õ��Ľڵ�ֵ��һ������vector�ݴ棬����������value����һ���ڵ㼴��
static vector<BiTree> list;
void InOrder(BiTree tree)
{
	
	if (tree != nullptr)
	{
		InOrder(tree->lchild);
		list.push_back(tree);
		InOrder(tree->rchild);
	}
}
void FindNextNode(BiTree tree,const char c)
{
	InOrder(tree);
	for(int i=0;i<list.size();i++)
	{
		if ((list[i]->data) == c)
		{
			if ((i + 1) >= list.size())
			{
				cout << "this node do not have the next node" << endl;
				return;
			}
			cout <<"the next node value is "<< list[i + 1]->data << endl;
	        return; 
		}
	}
	cout << "No EXIST the value of node is " << c << endl;

}

//���������������սڵ�����������������ָ��ýڵ��ǰ�������Һ���ָ��ýڵ�ĺ��
//ע�⣺����ĵĺ�̺�ǰ����˫�ס������ǲ�ͬ�ĸ��
//�磺�������������CBEGDFA��G��ǰ����E�������D
int main()
{
	BiTree realTree;
	Create2btree(realTree);
	FindNextNode(realTree, 'j');
	//PreTraverse(realTree);
	//BiTree CopyRealTree;
	//CopyTree(realTree, CopyRealTree);
	//PreTraverse(CopyRealTree);
	//cout << "the amount of the node:" << TreeNodeNumber(realTree) << endl;

	return 0;
}