// 二分法求解方程 f(x) = 0 根

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // x 为根，x1 为 x 左边的一个值，x2 为 x 的右边的一个值，f1 为 x1 对应的结果，f2 为 x2 对应的结果。f 为接近 0 的结果
    float x, x1 = 0, x2 = 2, f1, f2, f;
    cin >> x1 >> x2;
    f1 = x1 * x1 * x1 / 2 + 2 * x1 * x1 - 8;
    f2 = x2 * x2 * x2 / 2 + 2 * x2 * x2 - 8;
    if (f1 * f2 > 0) {
        cout << "没有实根" << endl;
        return 0;
    } 
    do
    {
        x = (x1 + x2) / 2;
        f = x * x * x / 2 + 2 * x * x - 8;
        if (f == 0) break;  // 说明已经有根了
        if (f1 * f > 0) {   // 说明根在 x 的右边
            x1 = x;         // 从[x1,x2]缩小 为[x, x2]
        } else {
            x2 = x;         // 从[x1,x2]缩小 为[x1, x]
        }
    } while (abs(f) >= 1e-4);   // 趋近于零的精度
    cout << "result = " << x;

    return 0;
}