#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef int ElemType;
const int max_size = 100;
//树的双亲孩子表示法//查找
//一些基本概念：树的每个节点你都要分配一个索引
//它提到，如果我们要找树的根，找到索引值为-1的节点就行，
//这里typedef的作用公式给CTNode提供一个新名字ChildPtr
typedef struct CTNode {
	int child;//当前孩子节点的下标
	struct CTNode* next;//指向当前节点的孩子节点
} *ChildPtr;
typedef struct CTBox {
	ElemType data;//存放在树中的节点的数据
	int parent;//存放当前节点的双亲下标-》能够轻易查找双亲节点
	ChildPtr firstchild;
};
//树结构
struct PTree {
	CTBox nodes[max_size];
	int r;//根的位置
	int n;//节点数目
};
int main2()
{
	cout << sizeof(CTNode) << endl;
	cout << sizeof(CTBox) << endl;
	cout << sizeof(PTree) << endl;
	return 0;
}