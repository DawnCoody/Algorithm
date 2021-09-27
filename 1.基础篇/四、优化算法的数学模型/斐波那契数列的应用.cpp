/**
 * 楼梯上有 n 阶台阶，上楼时可以一步上 1
 * 阶，也可以一步上两阶，编写算法共有多少种不同的上楼方法。
 */

/**
 * 可以找出规律：
 *      当为 1 阶台阶有 1 种方法
 *      当为 2 阶台阶有 2 种方法
 *      当为 3 阶台阶有 3 种方法
 *      当为 4 阶台阶有 5 种方法
 *      当为 5 阶台阶有 8 种方法
 * 可这发现这不就是斐波那切数列嘛
 */

#include <iostream>
using namespace std;

int fibonacci(int n);

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cout << "共有" << fibonacci(n) << "种方案" << endl;
    return 0;
}

int fibonacci(int n) {
    if (n == 1) 
        return 1;
    else if (n == 2)
        return 2;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));  // 斐波那切数列的规律：当前数等于前两个数相加
}