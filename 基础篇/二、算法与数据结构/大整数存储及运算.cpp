/**
 * 编程求当 n <= 100 时，n! 的准确值
 */
/**
 * 算法设计：
 *         累乘的结果是按由低到高位存储在数据 a 中，若存储结果的数组中
 *         每个存储空间只存储一位数字需要的存储空间太多，且对每一位进
 *         行累乘次数也太多。所以将数组定义为长整形，每个元素存储 6 位数字。
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    // carry_over存储超过 6 位数后的进位，temp 存储计算的中间结果，n
    // 为多少数的阶层，count 为记录结果在数组中占多数位
    long a[256] = {0}, carry_over = 0, temp;
    int n, count = 1;
    // 因为阶层的最小为 1 这里就初始化为 1 了
    a[1] = 1;
    cout << "求多少数的阶层：";
    cin >> n;
    for (int i = 2, j; i <= n; i++) {  // i 控制要乘的阶层，如 100!，就控制 2...100
        for (j = 1; j <= count; j++) {     // j 控制数组下标
            temp = a[j] * i + carry_over;  // 这里存储中间值，
            a[j] = temp % 1000000;  // 数组每一位只存储小于等于 6 位数的数
            carry_over = temp / 1000000;  // 存储进位值        
        }
        if (carry_over != 0) {  // 查看是否有最高位进位
            a[j] = carry_over;
            // 每次进位后都需要将进位清零
            carry_over = 0;
            count++;  // 位数加一
        }
    }

    for (int i = count; i >= 1; i--) cout << a[i] << " ";
    cout << endl;
    cout << "------------------------------" << endl;
    cout << n << " != ";
    cout << a[count] << " ";  // 先输出
    for (int i = count - 1; i >= 1; i--) {
        if (a[i] > 99999) {
            cout << a[i] << " ";
        } else if (a[i] > 9999) {
            cout << "0" << a[i] << " ";
        } else if (a[i] > 999) {
            cout << "00" << a[i] << " ";
        } else if (a[i] > 99) {
            cout << "000" << a[i] << " ";
        } else if (a[i] > 9) {
            cout << "0000" << a[i] << " ";
        } else {
            cout << "00000" << a[i] << " ";
        }
    }
    return 0;
}
