/**
 * 心里想好一个 1~100之间的整数 x，将它分别除以 3,5 和 7 并得到 3 个余数。
 * 把这 3 个余数输入计算机，计算机能马上猜出这个数。
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b, c, d;
    cout << "请输入你想的数中的除以 3 的余数：";
    cin >> a;
    cout << "请输入你想的数中的除以 5 的余数：";
    cin >> b;
    cout << "请输入你想的数中的除以 7 的余数：";
    cin >> c;
    // 其中 70 称为 a 的系数，21称为 b 的系数，15 称为 c 的系数
    d = 70 * a + 21 * b + 15 * c;

    // 结果可能比 100 大，这时要减去 3,5,7 的最小公倍数
    while (d > 105)
    {
        d -= 105;
    }
    cout << "your number was " << d;
    

    return 0;
}
