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
 *       2)若上一个数的位置是(i,j)，下一个数为((i - 2 + n) % n + 1, (j - 2 + n)
 * % n + 1) 3)若应填的位置虽然没有出界，当是当前数据为
 * n的倍数，则应填在一个数的下面(行加1，列不变)，即取(i % n + 1, j)
 */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // x 为在矩阵中填入的数
    int matrix[100][100] = {0}, x = 1, n;
    cout << "要打印多少阶矩阵：";
    cin >> n;
    int count = 0;
    // 外层循环总共循环 nxn 次
    for (int i = 1, j = (n + 1) / 2; x <= n * n; x++) {
        matrix[i][j] = x;
        if (x % n != 0) {   // 如果当是当前数据不为n的倍数，行减『1』，列减『1』
            i = (i - 2 + n) % n + 1;
            j = (j - 2 + n) % n + 1;
        } else  // 当前数据为 n 的倍数，行加『1』，列不变
            i = (i % n + 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << "\n" << endl;
        for (int j = 1; j <= n; j++) cout << matrix[i][j] << "\t";
    }

    return 0;
}
