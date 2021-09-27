/**
 * 编写算法将数字编号“翻译”成英文编号。
 * 例如：将编号 35706 “翻译” 成英文编号 three-five-seven-zero-six
 */

/**
 * 缺点：当输入的数据 num1 = 0 时，是不能正常运行的，会导致数据下溢
 */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    long num1, num2;
    char eng[][10] = {"zero", "one", "two",   "three", "four",
                      "five", "six", "seven", "eight", "nine"};
    int result[10] = {0}, index = 0; 
    for (int i = 0; i < 10; i++) {
        cout << result[i] << " ";
    }
    cout << "Input a num: ";
    cin >> num1;
    num2 = num1;
    for (index = 0; num2 != 0; index++) {
        result[index] = num2 % 10;
        num2 /= 10;
    }
    cout << num1 << "'s English expression is " << eng[result[index - 1]];
    for (int i = index - 2; i >= 0; i--) {
        cout << "-" << eng[result[i]];
    }
    return 0;
}
