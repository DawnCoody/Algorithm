/**
 * 魔方阵是我国古代发明的一种数字游戏：n 阶魔方是指这样的一种方式，
 * 它的每一行、每一列以及对角线上的各数之和为一个相同的常数，这个常数是：n x
 * (n^2 + 1) / 2
 * 此常数被称为魔方阵常数。由于偶次阶魔方阵(n=偶数)求解起来比较困难，这里只考虑
 * n 为奇数的情况。 以下就是一个 n = 3 的魔方矩阵 6   1   8 7   5   3 2   9   4
 * 它的各行、各列及对角线上的元素之和为 15
 */
/**
 * 算法设计：
 *       1)将 1 填在方阵第一行的中间，即(1， (n + 1) / 2) 位置  （这个无所谓）
 *       2)若上一个数的位置是(i,j)，下一个数为((i - 2 + n) % n + 1, (j - 2 + n) % n + 1)
 *       3)若应填的位置虽然没有出界，当是已经填有数据的话，则应填在一个数的下面(行加1，列不变)，即取(i % n + 1, j)
 */

#include <iostream>
using namespace std;
int main() {
    // x 为 1-n*n 存的数，a(行)、b(列) 为给矩阵存值的中间数
    int array[100][100] = {0}, x = 1, n, a, b;
    cout << "几阶矩阵：";
    cin >> n;
    if (!(n % 2)) {
        cout << "输入错误：";
        return -1;
    }

    // 给魔方矩阵赋值，开始赋值从 (1, (n + 1) / 2) 开始
    for (int i = 1, j = (n + 1) / 2; x <= n * n; x++) {
        array[i][j] = x;
        // 先将当前的 i,j存起来
        a = i, b = j;
        // 行减『1』，列减『1』这里不是简单的减一，当越界的时候从 n 开始
        i = (i - 2 + n) % n + 1, j = (j - 2 + n) % n + 1;
        // 若该位置已经填有数据的话，则应填在上一个数的下面，此时存的 i，j就起作用了
        if (array[i][j] != 0) {
            // 行加『1』，列不变，当 i 越界的时候从 1 开始
            i = a % n + 1;
            j = b;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << "\n" << endl;
        for (int j = 1; j <= n; j++) 
            cout << array[i][j] << "\t";
    }

    return 0;
}