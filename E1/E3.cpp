#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	auto begin = ivec.begin();
	auto end = ivec.end();
	auto  length = begin - end;
	int sought = 3;
	cout << "length" << length << endl;
	auto middle = begin + (end - begin) / 2;
	cout << (end - begin) / 2 << endl;
	while (middle != end && *middle != sought) {
		if (*middle < sought)
			begin = middle + 1;
		else
			end = middle;
		middle = begin + (end - begin) / 2;
	}
	cout << sought << "�������еĵ�" << middle - ivec.begin() << "��λ��" << endl;
	//���ʺ�������������һ���ġ�

}