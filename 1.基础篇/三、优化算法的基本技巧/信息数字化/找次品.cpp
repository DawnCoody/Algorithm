/**
 * 有 10 箱产品，每箱有 1000 件，正品每件 100 克。其中有几箱是次品，
 * 每件次品比正品轻 10 克，问能否用秤只秤一次，就找出哪几箱是次品。
 */

#include <math.h>

#include <iostream>
using namespace std;
int main() {
    // n 为有几箱子，k 每次为 w1 中最大以 2 为底的指数
    int n, k;
    // w1 开始存的是预计总重量，后面存的是与 w2 的差，w2 存的是实际总重量
    long w1, w2;
    cout << "Input the number of boxes: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << i << "box take" << pow(2, i - 1) << endl;
        w1 += pow(2, i - 1);
    }
    w1 *= 100;
    cout << "normal weight " << w1 << endl;
    cout << "Input realiaty weight: " << endl;
    cin >> w2;
    w1 = (w1 - w2) / 10;    // 实际总重量轻多少
    while (w1 != 0) {
        k = log(w1) / log(2);   // 找最大的指数
        cout << k + 1 << " is bad" << endl;
        w1 -= pow(2, k);        // 减去最大指数
    }

    return 0;
}