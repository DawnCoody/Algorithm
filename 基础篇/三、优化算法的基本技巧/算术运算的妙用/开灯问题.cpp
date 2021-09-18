/**
 * 有从 1 到 n 一次编号的 n 个同学和 n 盏灯。1 号同学将所有的灯都关掉；
 * 2 号同学将编号为 2
 * 的倍数的做相反的处理(该号灯如打开的，则关掉;关闭时，则打开) ；
 * 3 号同学则将编号为 3的倍数的灯
 * 做相反的处理(该号灯如打开的，则关掉;关闭时，则打开);以后的同学都将
 * 自己的编号的倍数的灯，作相反处理。问经过n 个同学后，哪些灯是打开着的？
 */

#include <iostream>
using namespace std;
int main() {
    int array[1000] = {0}, n;
    cout << "请输入有几同学：" << endl;
    cin >> n;
    // 外层循环枚举的是同学
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k * i <= n; k++) {  // k 为倍数
            //  模拟开关灯，当为 1 时结果就为 0 表示关灯，当为 0 时结果为 1 表示开灯
            array[i * k] = 1 - array[i * k];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (array[i] == 1) cout << i << "\t";
    }

    return 0;
}