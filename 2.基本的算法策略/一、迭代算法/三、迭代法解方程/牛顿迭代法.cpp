#include <math.h>

#include <iostream>
using namespace std;

int f(float a, float b, float c, float d);

int main(int argc, char const *argv[]) {
    // 系数
    float a, b, c, d;
    cout << "请输入系数:";
    cin >> a >> b >> c >> d;
    cout << "方程根为: " << f(a, b, c, d) << endl;
    return 0;
}

int f(float a, float b, float c, float d) {
    // x0 存储上次算出来的根的近似值，x1 存储根
    float x1 = 0, x0 = 1, f0, f1;
    do {
        x0 = x1;
        // f0 为原函数
        f0 = ((a * x0 + b) * x0 + c) * x0 + d;
        // f1 为 f0 的导函数
        f1 = (3 * a * x0 + 2 * b) * x0 + c;
        x1 = x0 - f0 / f1;
    } while (abs(x1 - x0) >= 1e-4);

    return x1;
}
