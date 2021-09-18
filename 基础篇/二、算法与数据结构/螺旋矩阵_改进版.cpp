/**
 * 螺旋阵：任意给定 n 值，按如下螺旋的方式输出方阵。
 * 当 n = 3 时 输出：
 *                  1   8   7
 *                  2   9   6
 *                  3   4   5
 */

#include <iostream>
using namespace std;

int main() {
    // dx 为矩阵的下标行标为 dx[1],列标为 dx[2]，k 为控制每半圈为一个单位，n 是几阶矩阵，reverse 为移动方向，x 为每次打印一个数增加一
    int matrix[100][100], dx[2], k, n, reverse, x = 1;
    dx[0] = 0;
    dx[1] = 1;
    cout << "要打印几阶矩阵: ";
    cin >> n;
    k = n;
    reverse = 1;
    while (x <= n * n) {
        for (int y = 1; y <= 2 * k - 1; y++, x++) {
            // reverse = 1 时处理左下角，reverse = -1 时处理右上角
            dx[y / (k + 1)] = dx[y / (k + 1)] + reverse;   
            matrix[dx[0]][dx[1]] = x;
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