/**
 * 一只小猴子摘了若干桃子，每天吃现有桃的一半多一个，到第 10
 * 天时就只有一个桃子了，求原来有多少个桃子？
 */

/**
 * 算法设计：
 *          由于每天的桃子数只依赖前一天的桃子数，所以用一个迭代变量代表桃子个数就可以了。
 */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int a = 1;
    for (int i = 9; i >= 1; i--) a = (a + 1) * 2;
    cout << a << endl;
    return 0;
}
