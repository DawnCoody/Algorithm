/**
 * 警察抓了 a,b,c,d 4 名偷窃嫌疑犯，其中只有一个是小偷。审问中：
 *  a：我不是小偷
 *  b：c是小偷
 *  c：小偷肯定是 d
 *  d：c 在冤枉人
 * 现在已经知道 4 个人中 3 个说的是真话，一个说的是假话，问到底谁是小偷？
 */

/**
 * 算法设计：
 *      用变量 x 存放小偷的编号，则 x 的取值范围从 1 取到 4
 */

#include <iostream>
using namespace std;

int main () {
    int x;
    for (int x = 1; x <= 4; x++) {
        if (3 == ((x != 1) + (x == 3) + (x == 4) + (x !=4))) cout << char(x + 96) << " is a thief" << endl;
    }
    return 0;
}