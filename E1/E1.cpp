#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& children, vector<int>& cookies)
{
    sort(children.begin(), children.end());
    sort(children.begin(), children.end());
    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size())
    {
        if (children[child] <= cookies[cookie]) ++child;
        ++cookie;
    }
    return child;
}
//int main()
//{
//    vector<int> ch{ 1,3,4 };
//    vector<int> co{ 1,2,4,5 };
//    int count = findContentChildren(ch, co);
//    cout<< "能填满肚子的人"<<count<<endl;
//}



