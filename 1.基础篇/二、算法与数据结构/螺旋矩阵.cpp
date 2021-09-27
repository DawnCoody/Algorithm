/**
 * 螺旋阵：任意给定 n 值，按如下螺旋的方式输出方阵。
 * 当 n = 3 时 输出：
 *                  1   8   7
 *                  2   9   6
 *                  3   4   5
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int matrix[100][100], n, x;
    cout << "请输入螺旋矩阵的阶数：";
    cin >> n;
    x = 1;
    for (int i = 1; i <= n / 2; i++) {
        // 左侧
        for (int j = i; j <= n - i; j++) {
            matrix[j][i] = x++;
        }
        // 下方
        for (int j = i; j <= n - i; j++) {
            matrix[n + 1 - i][j] = x++;
        }
        // 右侧
        for (int j = n + 1 - i; j >= i + 1; j--) {
            matrix[j][n + 1 - i] = x++;
        }
        // 上侧
        for (int j = n + 1 - i; j >= i + 1; j--) {
            matrix[i][j] = x++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
