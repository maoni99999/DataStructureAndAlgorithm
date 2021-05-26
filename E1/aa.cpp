#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int direction[8][2] = { { 2, 1 },{ 1, 2 },{ -1, 2 },
{ -2, 1 },{ -2, -1 },{ -1, -2 },{ 1, -2 },{ 2, -1 } }; //方向
bool flag[9][9];//标记是否走过
struct Horse {
	char x;
	char y;
	int step;
};
int main()
{
	int row, column;
	vector<string> data;
	cin >> row >> column;
	for (int i = 0; i < row; i++)
	{
		cin >> data[i];
	}

		struct Horse hs;
		hs.x = 0; hs.y = 0; hs.step = 0;
		queue <Horse> lq;
		lq.push(hs);
		while (!lq.empty()) {
			struct Horse hs1;
			hs1.x = lq.front().x;
			hs1.y = lq.front().y;
			hs1.step = lq.front().step;
			lq.pop();
			if (hs1.x == row-1 && hs1.y == column-1) {
				cout << hs1.step << endl;;
			}
			else {
				for (int z = 0; z < 8; z++) {
					struct Horse ho;
					ho.x = hs1.x + direction[z][0];
					ho.y = hs1.y + direction[z][1];
					ho.step = hs1.step + 1;
					if (ho.x >= 1 && ho.x <= 8 && ho.y >= 1
						&& ho.y <= 8
						&& flag[ho.x][ho.y] == false) {
						lq.push(ho);
						flag[ho.x][ho.y] = true;
					}
				}
			}
		}
	
	return 0;
}
