/**
 * 有一堆棋子，2枚2枚地数，最后余 1 枚；3枚3枚的数，最后余 2 枚；5 枚 5 枚的数，最后余 4 枚；
 * 6 枚 6 枚地数，最后余 5 枚；只有 7 枚 7 枚地数，最后正好数完。编程求出这堆棋子最少有多少枚
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    for (int i = 1; ; i++)
    {
        if (i % 7 == 0 && i % 6 == 5 && i % 5 == 4 && i % 3 == 2 && i % 2 == 1) {
            cout << "最少有：" << i << "枚棋子" << endl;
            break;
        }
    }
    
    return 0;
}
