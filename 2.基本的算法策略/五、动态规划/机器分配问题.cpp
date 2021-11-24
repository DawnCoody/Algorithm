/**
 * @file 机器分配问题.cpp
 * @author dawncoody (dawntruecool@gmail.com)
 * @brief 
 *          总公司拥有高效设备M台，准备分给下属的N个分公司。
 *          各分公司若获得这些设备，可以为国家提供一定的盈利。
 *          问：如何分配这M台设备才能使国家得到的盈利最大？
 *          求出最大盈利值。其中M≤15，N≤10。
 *          分配原则：每个公司有权获得任意数目的设备，但总台数不超过设备数M。
 * @version 0.1
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main()

{
    int n, m, v[20][20] = {0}, f[20][20] = {0};

    cout << "输入工厂数：";
    cin >> n;
    cout << "输入机器数：";
    cin >> m;
    for (int i = 1; i <= n; i++) {
        cout << "输入第" << i << "个工程获得的利润表：" << endl;
        for (int j = 1; j <= m; j++) cin >> v[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int maxs = 0;
            for (int k = 0; k <= j; k++)
                maxs = max(maxs, f[i - 1][k] + v[i][j - k]);
            f[i][j] = maxs;
        }
    }

    printf("%d\n", f[n][m]);

    for (int i = 1; i <= n; i++) {
        if (i == 1)
            printf("%d %d\n", i, f[i][i]);
        else
            printf("%d %d\n", i, f[i][i] - f[i - 1][i - 1]);
    }
}