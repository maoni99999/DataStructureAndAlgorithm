#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;
//关于贪心算法的理解：局部最优导致全局最优，贪心算法可通过排序的方式使题目简单
//糖果题：一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
//个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
//有孩子至少要有一个糖果。求解最少需要多少个糖果。
int candy(vector<int>& ratings) {
	int size = ratings.size();
	if (size < 2) {
		return size;
	}
	vector<int> num(size, 1);
	for (int i = 1; i < size; i++) {
		if (ratings[i] > ratings[i - 1]) {
			num[i] = num[i - 1] + 1;
		}
	}
	for (int i = size-1; i >0; i--) {
		if (ratings[i] < ratings[i - 1]) {
			num[i - 1] = max(num[i - 1], num[i] + 1);
		}
	}
	return accumulate(num.begin(), num.end(), 0);

}
int main()
{
    vector<int> ch{ 1,3,4,1,2,5,2,2,3 };
    int count = candy(ch);
    cout<< "最少发的糖果数"<<count<<endl;
}