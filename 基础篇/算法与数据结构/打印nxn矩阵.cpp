/**
 * 编程打印如下规律的 nxn 方阵，使左对角线和右对角线上的元素为
 * 0，它们的上方的元素为 1，左边的元素为 2，下方元素为 3，右边的元素为 4
 * 下图是符合条件的五阶矩阵
 *
 *      0   1   1   1   0
 *      2   0   1   0   4
 *      2   2   0   4   4
 *      2   0   3   0   4
 *      0   3   3   3   0
 */
// 分析
/**
 * 主对角线上三角◥元素 i <= j;
 * 主对角线下三角 ◣ 元素 i >= j
 * 辅对角线上三角 ◤ 元素：下标下界为 1 时 i + j <= n + 1，下标下界为 0 时 i + j
 * <= n - 1 辅对角线下三角 ◢ 元素：下标下界为 1 时 i + j >= n + 1，下标下界为 0
 * 时 i + j >= n - 1
 */

#include <iostream>
using namespace std;
int main() {
    int matrix[100][100], n;
    cout << "要打印几阶矩阵: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {  // 对角线
            if (i == j || i + j == n - 1) matrix[i][j] = 0;
            // 矩阵上方
            if (i < j && i + j < n - 1) matrix[i][j] = 1;
            // 矩阵左方
            if (i > j && i + j < n - 1) matrix[i][j] = 2;
            // 矩阵下方
            if (i > j && i + j > n - 1) matrix[i][j] = 3;
            // 矩阵右方
            if (i < j && i + j > n - 1) matrix[i][j] = 4;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << matrix[i][j] << "\t";
        cout << endl;
    }

    return 0;
}