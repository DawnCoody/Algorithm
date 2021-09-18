/**
 * 某校决定由全校学生选举自己的学生会主席。有 5 个候选人，编号分别为 1,2,3,4,5,
 * 选举其中一人为学生会主席，每个学生一张选票，只能填写一人。
 */

#include <iostream>
using namespace std;

int main() {
    int vote, a[6] = {0};
    while (cin >> vote, vote != -1) {
        if (vote >= 1 && vote <= 5) a[vote]++;
        else cout << vote << "输入有误" << endl;
    }
    for (int i = 1; i <= 5; i++) cout << i << " number get " << a[i] << " vote" << endl;
    return 0;
}