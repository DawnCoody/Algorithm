/**
 * 有 52 张牌，使他们全部正面朝上，第一轮是从第 2 张开始，凡是 2 的倍数位置上的牌翻成正面朝下；
 * 第二轮从 3 开始，凡是 3 的倍数位置上的牌，正面朝上的翻成正面朝下，正面朝下的翻成正面朝上；
 * 第三轮从 4 开始，凡是 4 的倍数位置上的牌，正面朝上的翻成正面朝下，正面朝下的翻成正面朝上；
 * 以此类推，直到翻的牌超过 104 张为止。统计最后有几张牌正面朝上，以及他们的位置号。
 */

#include <iostream>
using namespace std;

int main() {
    // card 代表每一张牌，reverse_amount 表示翻排个数，count 表示最后有几张牌正面朝上，
    int card[53] = {1}, reverse_amount = 0, count = 0;
    for (int i = 2; i <= 52; i++) if (i % 2 == 0) card[i] = 1 - card[i];
    // 外层控制第几轮
    for (int i = 2; reverse_amount < 104; i++) {
        for (int j = i; reverse_amount < 104 && j <= 52; j++, reverse_amount++) {
            if ( j % i == 0) card[j] = 1 - card[j]; // 小技巧
        }
    }
    for (int i = 1; i <=52; i++) {
        if (card[i]) cout << "第" << i << "号牌正面朝上" << endl;
        count += card[i];   // 因为 card[i] = 1 表示正面，所以如果是正面count就加一
    }

    cout << "正面朝上牌的个数为：" << count << endl;

    return 0;
}