/**
 * 编写算法对输入的一个整数，判断它能否被3,5,7整除，并输入以下信息之一：
 *      能同时被3,5,7整除
 *      能被其中两个（指出是哪两）整除
 *      能被其中一个数（要指出哪一个）整除
 *      不能被 3,5,7 任一个整除
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long n;
    int check;
    cout << "Please enter a number: ";
    cin >> n;
    // 这里与找次品题目类似，check 的范围是 0~7可以表示 8 种情况
    check = (n % 3 == 0) + (n % 5 == 0) * 2 + (n % 7 == 0) * 4;
    switch (check) {
        case 0:
            cout << "none" << endl;
            break;
        case 1:
            cout << "3" << endl;
            break;
        case 2:
            cout << "5" << endl;
            break;
        case 3:
            cout << "3 and 5" << endl;
            break;
        case 4:
            cout << "7" << endl;
            break;
        case 5:
            cout << "3 and 7" << endl;
            break;
        case 6:
            cout << "5 and 7" << endl;
            break;
        case 7:
            cout << "All" << endl;
            break;
    }
    return 0;
}
