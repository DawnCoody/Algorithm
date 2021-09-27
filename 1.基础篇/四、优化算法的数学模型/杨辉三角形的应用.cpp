/**
 * 求 n 次二项式的系数，如(a + b)^n
 */

#include <iostream>
using namespace std;

void coefficient(int[], int);

int main(int argc, char const *argv[]) {
    // a 为存储的系数，n 为指数
    int a[100], n;
    cin >> n;
    // 使用递归的方式
    coefficient(a, n);
    for (int i = 1; i <= n + 1; i++) cout << a[i] << "\t";
    cout << endl;

    return 0;
}

void coefficient(int a[], int n) {
    if (n == 1) {   // 当是杨辉三角形的第一层次时
        a[1] = 1;
        a[2] = 1;
    } else {        // 杨辉三角形的非第一层次时
        coefficient(a, n - 1);  // 递归找到第一层
        a[n + 1] = 1;           // 最后一项系数为 1
        // 这里的 for 循环移动要倒过来
        for (int i = n; i >= 2; i--) a[i] = a[i] + a[i - 1];
    }
}
