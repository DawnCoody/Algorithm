#include <iostream>
using namespace std;

int max(int x, int y, int z) {
    if (x > y && x > z) return x;
    if (y > x && y > z) return y;
    return z;
}

int main() {
    // x1,x2,x3输入的三个数 lease_common_multiple 为最小公倍数，flag 用于标签，max_value 是 x1,x2,x3中最大的数
    int x1, x2, x3, lease_common_multiple = 1, flag = 1, max_value;
    cout << "请输入三个值：";
    cin >> x1 >> x2 >> x3;
    max_value = max(x1, x2, x3);
    for (int i = 2; i <= max_value; i++) {
        // flag设为 1 以便能进入 while 循环体
        flag = 1;
        while (flag == 1) {
            // 立马置为零
            flag = 0;
            if (x1 % i == 0) {
                x1 /= i;
                flag = 1;
            } 
            if (x2 % i == 0) {
                x2 /= i;
                flag = 1;
            }
            if (x3 % i == 0) {
                x3 /= i;
                flag = 1;
            }
            if (flag == 1) {
                // 乘以公因子
                lease_common_multiple *= i;
            }
        }
        // 因为 x1,x2,x3的值变了要重新找最大值
        max_value = max(x1, x2, x3);
    }
    cout << "The lease common multiple is " << lease_common_multiple;

    return 0;
}