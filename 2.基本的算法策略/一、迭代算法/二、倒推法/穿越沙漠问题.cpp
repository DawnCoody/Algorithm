/**
 * 一辆吉普车穿越 1000 km 的沙漠。吉普车的总装油量为 500 加仑，耗油率为
 * 1加仑/km。
 * 由于沙漠汇总没有油库，必须先用这辆车在沙漠中建立临时油库。若吉普车用最少的耗油量
 * 穿越沙漠，应该在哪些地方建立油库，以及各处存储的油量。
 */

/**
 * 数学模型：
 * 第一段长度为 500 km 且第一个加油点储油量为 500
 * 第二段中为了储备油，吉普车在这段的行程必须有往返。下面讨论怎样走效率高：
 *      1.首先不计方向这段应走奇数次(保证最后向终点方向走)
 *      2.每次向终点进行时吉普车是满载的。
 *      3.这个加油点要存储下一加油点的储油量以及建立下一加油路上的油耗。
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    // distance 为当前站点到终点的距离，oil 为总油量，k 为第几站点(倒推：第一站点为终点)
    int distance = 500, oil = 500, k = 1;
    do {
        printf("storepoint %d, distance %d, oilquantity %d\n", k, 1000 - distance, oil);
        k++;
        // 不计方向这段应走奇数次(保证最后向终点方向走)
        distance += 500 / (k * 2 - 1);
        // 每两站点至少要消耗 500加仑 油量
        oil = 500 * k;
    } while (distance < 1000);

    oil = 500 * (k - 1) + (1000 - distance) * (2 * k - 1);
    printf("storepoint %d, distance %d, oilquantity %d\n", k, 0, oil);
    return 0;
}
