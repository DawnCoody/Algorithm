/**
 * A,B,C,D,E 5 人为某次竞赛的前五名，他们在名次公布前猜名次。
 * A说：B 得第三名，C得第五名
 * B说：D 得第二名，E得第四名
 * C说：B 得第一名，E得第四名
 * D说：C 得第一名，B得第二名
 * E说：D 得第二名，A得第三名。
 * 结果每个人都猜对了一半，实际名次是什么呢？
 */

#include <iostream>

using namespace std;

int main() {
    for (int a = 1; a <= 5; a++)
        for (int b = 1; b <= 5; b++)
            // a 不能和 b 同名次
            if (a != b)
                for (int c = 1; c <= 5; c++)
                    // c 不能和 （b与a） 同名次
                    if (a != c && b != c)
                        for (int d = 1; d <= 5; d++)
                            // d 不能和 （a、b、c）同名次
                            if (d != a && d != b && d != c) {
                                int e = 15 - a - b - c - d;
                                // 该 if 为 A,B,C,D,E 的猜测
                                if ((b == 3) + (c == 5) == 1 && (d == 2) + (e == 4) == 1 && (b == 1) + (e == 4) == 1 && (c == 1) + (b == 2) == 1 && (d == 2) + (a == 3) == 1) {
                                    printf("a, b, c, d = %d, %d, %d, %d, %d", a, b, c, d, e);
                                }
                            }

    return 0;
}