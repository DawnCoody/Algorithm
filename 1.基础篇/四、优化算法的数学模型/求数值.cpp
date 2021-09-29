/**
 * 求这样的两个数据：5位数 = 2 x 4 位数，9 个数字互不相同。
 */
#include <iostream>
using namespace std;
bool check(int, int);
int main(int argc, char const *argv[]) {
    for (int wu = 10000; wu < 100000; wu++) {
        for (int si = 1000; si < 10000; si++) {
            if (wu == si * 2) {
                if (check(wu, si)) {
                    printf("%d = 2 * %d\n", wu, si);
                }
            }
        }
    }
    return 0;
}

// 用于校验每一位是否相同
bool check(int wu, int si) {
    int arr[10] = {0};
    for (int i = 0; i < 5; i++) {
        arr[wu % 10]++;
        wu /= 10;
    }
    for (int i = 0; i < 4; i++) {
        arr[si % 10]++;
        si /= 10;
    }
    for (int i = 0; i < 10; i++) {  
        if (arr[i] >= 2) return false;  // 如果有一位有重复就返回 false
    }
    return true;            // 没有重复返回 true
}