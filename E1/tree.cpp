#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef int ElemType;
const int max_size = 100;
//����˫�׺��ӱ�ʾ��//����
//һЩ�����������ÿ���ڵ��㶼Ҫ����һ������
//���ᵽ���������Ҫ�����ĸ����ҵ�����ֵΪ-1�Ľڵ���У�
//����typedef�����ù�ʽ��CTNode�ṩһ��������ChildPtr
typedef struct CTNode {
	int child;//��ǰ���ӽڵ���±�
	struct CTNode* next;//ָ��ǰ�ڵ�ĺ��ӽڵ�
} *ChildPtr;
typedef struct CTBox {
	ElemType data;//��������еĽڵ������
	int parent;//��ŵ�ǰ�ڵ��˫���±�-���ܹ����ײ���˫�׽ڵ�
	ChildPtr firstchild;
};
//���ṹ
struct PTree {
	CTBox nodes[max_size];
	int r;//����λ��
	int n;//�ڵ���Ŀ
};
int main2()
{
	cout << sizeof(CTNode) << endl;
	cout << sizeof(CTBox) << endl;
	cout << sizeof(PTree) << endl;
	return 0;
}