/**
 * 螺旋阵：任意给定 n 值，按如下螺旋的方式输出方阵。
 * 当 n = 3 时 输出：
 *                   1       2       3       4       5
 *                   16      17      18      19      6
 *                   15      24      25      20      7
 *                   14      23      22      21      8
 *                   13      12      11      10      9
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    // dx 为矩阵的下标行标为 dx[1],列标为 dx[2]，k 为控制每半圈为一个单位，n
    // 是几阶矩阵，reverse 为移动方向，x 为每次打印一个数增加一
    int matrix[100][100], dx[2], reverse, n, x = 1, k;
    dx[0] = 0;
    dx[1] = 1;
    reverse = 1;
    cout << "打印几阶矩阵：";
    cin >> n;
    k = n;
    while (x <= n * n) {
        for (int i = 1; i <= 2 * k - 1; i++) {
            dx[i / (k + 1)] = dx[i / (k + 1)] + reverse;
            matrix[dx[1]][dx[0]] = x++;
        }
        k--;
        reverse = -reverse;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
