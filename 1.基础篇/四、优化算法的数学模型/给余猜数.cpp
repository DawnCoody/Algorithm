/**
 * 完成给“余”猜数的游戏f:
 *      心里想好一个 1~100 之间的整数 x，将它分别除以 3,4和7并得到 3
 * 个余数。把这 3 个余数输入计算机，计算机马上能猜出这个数。
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b, c, d;
    cout << "请输入你想的数中的除以 3 的余数：";
    cin >> a;
    cout << "请输入你想的数中的除以 4 的余数：";
    cin >> b;
    cout << "请输入你想的数中的除以 7 的余数：";
    cin >> c;
    // 其中 28 称为 a 的系数，21 称为 b 的系数，36 称为 c 的系数
    d = 28 * a + 21 * b + 36 * c;

    while (d > 84) {
        d -= 84;
    }
    cout << "your number was " << d;

    return 0;
}
