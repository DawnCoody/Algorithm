/**
 * 12 个小朋友手拉手站成一个圆圈，从某一小朋友开始报数，
 * 报到 7的那个小朋友退出圈外，然后他的下一位重新报“1”。
 * 这样继续下去，直到最后只剩下一个小朋友。求解这个小朋友原来站在什么位置上
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    // children 为游戏人数，start 游戏为开始编号，out_ring_number 为淘汰编号，out_ring_count 为淘汰人数，count 为当前数到了多少个小朋友了
    int kids[100], children, start, out_ring_number, out_ring_count = 0, count;
    cout << "Input numbers of game: ";
    cin >> children;
    cout << "Input serial number of game start: ";
    cin >> start;
    cout << "Input number of out_ring: ";
    cin >> out_ring_number;

    for (int i = 1; i <= children; i++) {
        // 这里需要设置为 1 不能是 0，为了方便数数
        kids[i] = 1;
    }
    // 这里 start-- 因为后面的是为了包含 start 本身的标号要数数，可不是因为数组下标的原因哦(^-^)~~, 况且数组下标我从 1 开始
    start--;
    cout << "wash out: ";
    for (; out_ring_count < children - 1; out_ring_count++) {
        count = 0;
        while (count < out_ring_number)
        {
            start++;
            if (start > children) start = 1;
            count += kids[start];
        }
        cout << start << " ";
        kids[start] = 0;
    }

    // 找出剩余最后一个玩家
    for (int i = 1; i <= children; i++) {
        if (kids[i] == 1) cout << "i = " << i << endl;
    }

    return 0;
}
