/**
 * 编写算法解如下数字谜
 *  A B C A B
 * x        A
 *  D D D D D
 */

// 将算式变形为除法，即 DDDDDD / A = ABCAB.
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int A, B, C, D;
    long E, F;
    for (A = 3; A <= 9; A++) {
        for (D = 1; D <= 9; D++) {
            E = D * 100000 + D * 10000 + D * 1000 + D * 100 + D * 10 + D;
            if (E % A == 0) {
                F = E / A;
                if (F / 10000 == A && (F % 100) / 10 == A)  // 如果被乘数第 1 位数和倒数第二个数都等于 A(从左往右数)
                    if (F / 1000 % 10 == F % 10)            // 如果被乘数第 2 位数和倒数第 1 个数都等于 F
                    {
                        cout << F << "*" << A << "=" << E;
                    }
                    
                
            }
        }
    }
    return 0;
}
