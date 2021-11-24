/**
 * 设计一个算法，把一个真分数表示为埃及分数之和的形式。
 * 所谓埃及分数，是指分子为 1 的分数。如 7/8 = 1 / 2 + 1/3 + 1/24;
 */
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b;
    if (a >= b)
        cout << "input error" << endl;
    else if (a == 1 or b % a == 0) 
        printf("%d/%d=%d");
    return 0;
}
