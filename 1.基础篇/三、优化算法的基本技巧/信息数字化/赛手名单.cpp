/**
 * 两个兵乒球队进行比赛，各出 3 人。甲队为 A、B、C 3 人，乙队为 X、Y、Z 3
 * 人，已抽签决定比赛名单。 有人向队员打听比赛的名单，A 说他不和 X 比，C
 * 说他不能 X、Z 比，请编写算法找出 3 对赛手的名单。
 */

#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    for (char a = 'X'; a <= 'Z'; a++)
        for (char b = 'X'; b <= 'Z'; b++)
            //A和B的对手不相同
            if (a != b) {
                for (char c = 'X'; c <= 'Z'; c++) {
                    //A和C的对手不相同B和C的对手不相同
                    if (c != a && c != b) {
                        //A的对手不是X，C的对手不是X，C的对手不是Z
                        if (a != 'X' && c != 'X' && c != 'Z') {
                            cout << "A vs " << a << endl;
                            cout << "B vs " << b << endl;
                            cout << "C vs " << c << endl;
                        }
                    }
                }
            }
    return 0;
}
