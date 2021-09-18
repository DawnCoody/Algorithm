/**
 * 一次考试，共考了5们课。统计 50 个学生中至少有 3 们课成绩高于 90 分的人数。
 */
/**
 * 算法设计：
 *      1) 对每个同学，先计算其成绩高于 90 分的课程数目，若超过 3，则累加到满足条件的人数中
 *      2) 用二重循环实现，外层模拟 50 个同学，内存模拟 5 门课程
 */
#include <iostream>
using namespace std;
int main() {
    cout  << "你好" <<endl;
    int subject[5], excellent_subject = 0, amount = 0;
    for (int i = 0; i <= 2; i++) {
        excellent_subject = 0;
        for (int j = 0; j <= 4; j++) {
            cin >> subject[j];
            excellent_subject += subject[j] >= 90;
        }
        if (excellent_subject >= 3) amount++;
    }
    cout << "The amount is "<< amount << endl;
    return 0;
}