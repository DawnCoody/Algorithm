/**
 * 有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
 */

// 分析：蜂房问题可以看做是一个斐波那切数列

#include <iostream>
#include <math.h>
using namespace std;

int honeybee(int);
int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;  
    cout << honeybee(abs(a - b)) << endl;

    return 0;
}

int honeybee(int distance) {
    if (distance == 1) return 1;
    if (distance == 2) return 2;
    return honeybee(distance - 1) + honeybee(distance - 2);
}
