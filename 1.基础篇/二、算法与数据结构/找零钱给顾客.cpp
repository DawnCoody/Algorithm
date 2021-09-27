/**
 * 一个顾客买了价值 x 元的商品，并将 y
 * 元的钱交给售货员，货币面值有：1,2,5,10,20,50,100
 * 编写算法：在各种币值的钱都很充分的情况下，是售货员能用张数最少的钱币找给顾客
 */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // 因为不用最大面币值为 100 所以不用找零钱 100
    int money[] = {0, 50, 20, 10, 5, 2, 1}, a[7] = {0};
    int x, y, z;
    cout << "商品价格：";
    cin >> x;
    cout << "交付金额：";
    cin >> y;

    // 应找零钱
    z = y - x;

    for (int i = 1; i <= 6; i++) {
        a[i] = z / money[i];
        z -= a[i] * money[i];
    }

    cout << y << "-" << x << "=" << z << ": ";
    for (int i = 1; i <= 6; i++) {
        if (a[i] != 0) cout << money[i] << "------" << a[i] << endl;
    }

    return 0;
}
