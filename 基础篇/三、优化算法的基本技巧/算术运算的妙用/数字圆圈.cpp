/**
 * 在圆圈中，把相隔一个数据的连个数称为『一对数』，编写算法求出乘积最大的『一对数』，
 * 编写算法求出乘积最大的一对数和乘积最小的一对数。
 */

#include <iostream>
using namespace std;

int main() {
    // array[x1]与array[y1]的乘积为最大值，array[x2]与array[y2]的乘积为最小值
    int array[100], max = 1, min = 32767, n, x1, y1, x2, y2;
    cout << "请输入有几个数围成一个圈：";
    cin >> n;
    cout << "请输入这几个数：";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++) {
        int x = (n + i - 1) % n;
        int y = (i + 1) % n;
        int temp = array[x] * array[y];
        if (temp > max) {
            max = temp;
            x1 = array[x];
            y1 = array[y];
        }
        if (temp < min) {
            min = temp;
            x2 = array[x];
            y2 = array[y];
        }
    }
    cout << "max = " << x1 << "*" << y1 << "=" << max << endl;
    ;
    cout << "min = " << x2 << "*" << y2 << "=" << min;
    return 0;
}