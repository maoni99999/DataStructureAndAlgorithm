#include <iostream>
#include <vector>
#include <algorithm>
#include "stdio.h"
using namespace std;
typedef char ElemType;
const int max_size = 100;
//基于二叉树三种递归形式的遍历算法，可以建立二叉树，建立方法也按遍历的方法建立
typedef struct BiNode {
	ElemType data;
	BiNode* lchild, * rchild;
}BiNode, * BiTree;
//先序遍历
//我觉得不太好理解的是如果为空就返回
void PreTraverse(BiTree& T)
{
	if (T != nullptr)
	{
		cout << T->data << endl;
		PreTraverse(T->lchild);
		PreTraverse(T->rchild);
	}
}
//建立一颗二叉树
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
 //复制一颗二叉树
bool CopyTree(BiTree OrigianlTree, BiTree& NewTree) {
	if (OrigianlTree == nullptr)
	{
		NewTree = nullptr;
		return false;
	}
	//重点，且同意出错的点就在于如果为空，也要将新指针指向空
	else
	{
		NewTree = new BiNode;
		NewTree->data = OrigianlTree->data;
		CopyTree(OrigianlTree->lchild, NewTree->lchild);
		CopyTree(OrigianlTree->rchild, NewTree->rchild);
		return true;
	}
}
//计算二叉树的深度
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
//求总节点数
//递归太巧妙了
int TreeNodeNumber(BiTree T)
{
	if (T == nullptr)
		return 0;
	else
	{
		return TreeNodeNumber(T->lchild) + TreeNodeNumber(T->rchild) + 1;
	}
}
//求叶子节点数：
//叶子节点数=左子树上的叶子节点数+右子树上的叶子节点数
//叶子节点数是该节点的左孩子和右孩子都为nullptr，则记录一个叶子,return 1
//如果有一个不为空，说明它不是叶子节点，它是一棵树，然后再分别统计它的左孩子和右孩子上有多少个叶子节点，加起来即可；
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
//寻找二叉树某个节点的下一节点（中序遍历），即后继节点
//方法：既然给了二叉树的某个结点，且二叉树存储着指向父结点的指针（next），
//那我们可以先找到根节点，再对树进行中序遍历，最后根据中序遍历结果找到给定结点的下一结点
//中序遍历得到的节点值用一个数组vector暂存，索引到等于value的下一个节点即可
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

//线索二叉树：将空节点利用起来，空左孩子指向该节点的前驱，空右孩子指向该节点的后继
//注意：这里的的后继和前驱与双亲、孩子是不同的概念，
//如：中序遍历的序列CBEGDFA，G的前驱是E，后继是D
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