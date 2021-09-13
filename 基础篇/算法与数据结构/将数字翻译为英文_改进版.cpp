/**
 * 编写算法将数字编号“翻译”成英文编号。
 * 例如：将编号 35706 “翻译” 成英文编号 three-five-seven-zero-six
 */

/**
 * 可以存储 0 开头的编号，如 “0001”
 */
#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const* argv[]) {
    char eng[][10] = {"zero", "one", "two",   "three", "four",
                      "five", "six", "seven", "eight", "nine"};
    int length;
    char *num, index = 0;
    cout << "Input number: ";
    gets(num);
    length = strlen(num);
    if (0 == length) 
        cout << "Input error!" << endl;
    else {
        cout << num << "'s English expression " << eng[num[0] - 48];
        for (int i = 1; i <= length - 1; i++) {
            cout << "-" << eng[num[i] - 48];
        }
    }
    return 0;
}
