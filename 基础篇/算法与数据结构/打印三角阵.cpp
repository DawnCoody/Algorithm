/**
 * 编程打印形如下的 nxn 方阵的上三角形：
 *      1   3   6   10  15
 *      2   5   9   14
 *      4   8   13
 *      7   12
 *      11
 */

#include <iostream>

using namespace std;

int main() {
    int matrix[100][100], n, x = 1;
    cout << "要打印几阶方阵：";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            matrix[i - j + 1][j] = x++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j <= n + 1) {
                cout << matrix[i][j] << "\t";
            }
        }
        cout << endl;
    }
    return 0;
}