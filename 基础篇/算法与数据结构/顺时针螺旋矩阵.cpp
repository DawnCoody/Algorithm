/**
 * 螺旋阵：任意给定 n 值，按如下螺旋的方式输出方阵。
 * 当 n = 3 时 输出：
 *                  1       2       3       4
 *                  12      13      14      5
 *                  11      16      15      6
 *                  10      9       8       7
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int matrix[100][100], n, x = 1;
    cout << "要打印多少阶矩阵：";
    cin >> n;
    for (int i = 1; i <= n / 2; i++) {
        // 上侧
        for (int j = i; j <= n - i; j++) {
            matrix[i][j] = x++;
        }
        // 右侧
        for (int j = i; j <= n - i; j++) {
            matrix[j][n - i + 1] = x++;
        }
        // 下侧
        for (int j = n - i + 1; j >= i + 1; j--) {
            matrix[n - i + 1][j] = x++;
        }
        // 左侧
        for (int j = n - i + 1; j >= i + 1; j--) {
            matrix[j][i] = x++;
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
