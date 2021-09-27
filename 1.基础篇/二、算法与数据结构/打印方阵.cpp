/**
 * 编写程序打印如图所示 nxn 方阵
 *      1   1   1   1   1
 *      1   2   2   2   1
 *      1   2   3   2   1
 *      1   2   2   2   1
 *      1   1   1   1   1
 */

#include <iostream>
using namespace std;

int main() {
    // n 表示打印几阶矩阵，x 表示给矩阵的赋值，reverse 控制矩阵的下标，layer 控制圈数（每半圈 - 1）
    int array[100][100], n, x = 1, reverse = 1, layer;
    // dx[1] 为数组下标 x，dx[0] 为数组下标 y
    int dx[2];
    dx[0] = 0;
    dx[1] = 1;
    cout << "要打印几阶矩阵：";
    cin >> n;
    layer = n;
    int count = 1;
    while (x <= n - 2) {    // 控制每一圈矩阵
        for (int i = 1; i <= 2 * layer - 1; i++) {
            dx[i / (layer + 1)] += reverse;
            array[dx[1]][dx[0]] = x;
        }
        if (layer % 2 == 0) {
            x++;
        }
        layer--;
        reverse = -reverse;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}