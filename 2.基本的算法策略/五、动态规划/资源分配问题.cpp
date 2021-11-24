/**
 * @file 资源分配问题.cpp
 * @author dawncoody (dawntruecool@gmail.com)
 * @brief
 *       设有资源 n (n为整数)，分配给 m 个项目，gi(x) 为第 i 个项目分得资源 x
 * (x为整数) 所得的利润。求总利润最大的资源
 * @version 0.1
 * @date 2021-11-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#define N 100
using namespace std;
// a[.][.][0]存储原始数据
// a[.][.][1]存储存储动态规划过程
// a[.][.][2]存储最优化路径
int main() {
    // a[i][j]=k;表示前i个工程投资j所获得最大利润时给第i个工程分配的资源数
    int a[N][N];
    // gain记录第i个工程分配的资源数
    int gain[N];
    // f[i]表示当前投资总投资i时获得的最大利润
    double f[N];
    // pre_f[i]表示上一个项目投资总投资i时获得的最大利润
    double pre_f[N];
    // q[i]记录某个工程的利润表
    double q[N];
    cout << "输入工程数：";
    int m;
    cin >> m;

    cout << "输入总资源数：";
    int n;
    cin >> n;
    cout << "输入第1个工程获得的利润表：" << endl;
    for (int i = 0; i <= n; ++i) {
        cin >> q[i];
        f[i] = q[i];
        pre_f[i] = q[i];
        a[1][i] = i;
    }
    cout << endl;

    for (int k = 2; k <= m; ++k) {
        cout << "输入第" << k << "个工程获得的利润表：" << endl;
        for (int i = 0; i <= n; ++i) {
            cin >> q[i];
            f[i] = 0;
            a[k][i] = 0;
        }
        for (int i = 0; i <= n; ++i)  // i为总投资数
        {
            cout << "资源数为" << i << "时" << endl;
            for (int j = 0; j <= i; ++j)  // j为给第k个工程的投资数
            {
                if (q[j] + pre_f[i - j] > f[i]) {
                    a[k][i] = j;
                    f[i] = q[j] + pre_f[i - j];
                    a[k][i] = j;
                }
                cout << q[j] + pre_f[i - j] << ' ';
            }
            cout << endl;
        }
        cout << "当前最大利润表如下：" << endl;
        for (int i = 0; i <= n; ++i) {
            pre_f[i] = f[i];
            cout << "f[" << i << "]:" << f[i] << ' ';
        }
        cout << endl << endl;
    }
    int rest = n;
    for (int i = m; i >= 1; --i) {
        gain[i] = a[i][rest];
        rest = rest - gain[i];
    }
    for (int i = 1; i <= m; ++i) {
        cout << "第" << i << "个项目投资" << gain[i] << endl;
    }
    cout << "总利润：" << f[n] << endl;
    return 0;
}