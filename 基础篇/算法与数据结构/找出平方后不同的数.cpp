/**
 * 求 x，使 x^2 为一个各位数互不相同的 9 位数
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long x, x1, x2;
    int digit[10], flag, num = 0;

    // x 的估计值为 10000~32000
    for (x = 10000; x < 32000; x++) {
        for (int i = 0; i < 10; i++) digit[i] = 1;
        x1 = x * x;
        x2 = x1;
        flag = 0;
        // 将每一位遍历，如果发现有数重复就break
        for (int i = 1; i <= 9; i++) {
            int temp = x2 % 10;
            x2 /= 10;
            if (1 == digit[temp]) {    // 还没有发现有数重复
                flag++;
                digit[temp] = 0;
            } else      // 有数重复退出该层循环
                break;
        }
        // 如果 falg 等于 9 就说明 x 的每一个数都遍历了一遍，各位数互不相同的
        if (9 == flag) {
            cout << "No." << num << ": n = " << x << "n^2 = " << x1 << endl;
        }
    }
    return 0;
}
