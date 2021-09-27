/**
 * 数组中有 n 个数据，要将它们循序循环向后移 k 位，即前面的元素向后移 k 位，后面的元素则循环向前移 k 位，
 * 例：0,1,2,3,4 循环移 3 位后为 2,3,4,0,1 考虑到 n 会很大，不允许用 2xn 以上个空间来完成此题。
 */

#include <iostream>
using namespace std;

int divisor(int a, int b);

int main(int argc, char const *argv[])
{
    // a 为要移动的数据，n 为有几个数据要移动，k 为要移动几位
    int a[100], n, k;
    cout << "Input the number of data: ";
    cin >> n;
    cout << "Input the distant of moving: ";
    cin >> k;
    cout << "Input the data: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    // 求最大公约数
    int greatest_common_divisor = divisor(k, n);

    // 外层循环为分 greatest_common_divisor 组
    for (int i = 0; i < greatest_common_divisor; i++) {
        int change = a[i];  // 存储每组的第一个数据
        int index = i;      // 存储每组的第一个数据的下标

        // 内存循环为每组有多少数据 
        for (int j = 0; j < n / greatest_common_divisor; j++) {
            index = (index + k) % n;    // 向右移动 k 位

            // 将改组的当前元素赋值给改组的下一个元素，改组的下一个元素保存到 change 中
            int temp = a[index];       
            a[index] = change;
            change = temp;
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << "\t" ;


    return 0;
}

// 使用辗转相除法求最大公约数
int divisor(int a, int b) {
    int t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
