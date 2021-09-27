/**
 * 输入任意 5 个数 x1,x2,x3,x4,x5 每两个相邻数之间填上一个运算符。在填入 4
 * 个运算符 "+、-、*、/" 后，使得表达式值为一个指定值 y(y由键盘输入)。
 * 求出所有满足条件的表达式
 */
#include <iostream>
using namespace std;
int main() {
    // sign 符号标志（正负号），symbol_mapping 为符号映射，total 为结果总数
    int sign, symbol_mapping[5], total = 0;
    // number 为输入的数，result 为累加器，temp 若当前运算符 为 +(-)时，temp 存储运算符的左项值；若当前运算符为*(/)时，temp 存储两数乘(除)后结果
    float number[6], result = 0, temp;
    char symbols[5] = {' ', '+', '-', '*', '/'};
    printf("请输入 5 个数：");
    for (int i = 1; i <= 5; i++) {
        cin >> number[i];
    }
    printf("请输入结果：");
    cin >> number[0];

    // symbol_mapping 遍历所有符号，5个数之间有4个运算符因此有 4 层循环，而共有 4 个符号(+,-,*,/) 所以每层循环循环 4 次
    for (symbol_mapping[1] = 1; symbol_mapping[1] <= 4; symbol_mapping[1]++)
        if (symbol_mapping[1] < 4 || number[2] != 0)    // 这里 if 是为了防止除号右边出现 0 
            for (symbol_mapping[2] = 1; symbol_mapping[2] <= 4; symbol_mapping[2]++)
                if (symbol_mapping[2] < 4 || number[3] != 0)
                    for (symbol_mapping[3] = 1; symbol_mapping[3] <= 4; symbol_mapping[3]++)
                        if (symbol_mapping[3] < 4 || number[4] != 0)
                            for (symbol_mapping[4] = 1; symbol_mapping[4] <= 4; symbol_mapping[4]++)
                                if (symbol_mapping[4] < 4 || number[5] != 0) {
                                    result = 0;
                                    temp = number[1];
                                    sign = 1;
                                    for (int i = 1; i <= 4; i++) {
                                        switch (symbol_mapping[i]) {
                                            case 1:
                                                // +
                                                result += sign * temp;
                                                sign = 1;
                                                temp = number[i + 1];
                                                break;
                                            case 2:
                                                // -
                                                result += sign * temp;
                                                sign = -1;
                                                temp = number[i + 1];
                                                break;
                                            case 3:
                                                // *    如果是 * or / 就直接运算，这样就辨别出优先顺序(让 * / 先算 + - 后算)
                                                temp *= number[i + 1];
                                                break;
                                            case 4:
                                                // /
                                                temp /= number[i + 1];
                                                break;
                                        }
                                    }
                                    if (result + sign * temp == number[0]) {
                                        total++;
                                        cout << "total " << total << ":";
                                        for (int j = 1; j <= 4; j++)
                                            cout << number[j] << symbols[symbol_mapping[j]];
                                        cout << number[5] << "=" << number[0] << endl;
                                    }
                                }
    if (total == 0) cout << "Non solution" << endl;
    return 0;
}