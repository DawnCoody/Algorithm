/**
 * 残缺棋盘是一个有 2^kx2^k(k>=1)个方格的棋盘，其中恰有 1 个方格残缺。
 */

#include <stdio.h>
using namespace std;
int count = 0, bord[100][100];
//覆盖以（tr，tc）为左上角坐标，宽为size的棋盘。残缺块或伪残缺块坐标为（dr，dc）
int cover(int tr, int tc, int size, int dr, int dc);
int main() {
    int x, y, k, size = 1;
    scanf("%d%d%d", &k, &x, &y);
    for (int i = 1; i <= k; i++) size = size * 2;  //计算2^k
    cover(0, 0, size, x, y);                   //对原始棋盘进行覆盖
    for (int i = 0; i < size; i++) {            //输出棋盘的覆盖结果
        for (int j = 0; j < size; j++) {
            printf("%-2d ", bord[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int cover(int tr, int tc, int size, int dr, int dc) {
    if (size < 2)
        return 0;  //假如棋盘分割到不足2*2则直接返回（这时候没办法用模板去覆盖棋盘了）
    int s = size / 2;  //表示即将被再次分割后的棋盘大小
    if (dr < (tr + s) && dc < (tc + s)) { //表示对当前输入的棋盘而言，残缺块在左上角部分的子棋盘
        cover(tr, tc, s, dr, dc);  //对左上角子棋盘分割
        count++;
        bord[tr + s - 1][tc + s] = count;  //下面三个赋值语句是用①号模板覆盖
        bord[tr + s][tc + s - 1] = count;
        bord[tr + s][tc + s] = count;
        cover(tr, tc + s, s, tr + s - 1, tc + s);  //对右上角子棋盘分割
        cover(tr + s, tc, s, tr + s, tc + s - 1);  //对左下角子棋盘分割
        cover(tr + s, tc + s, s, tr + s, tc + s);  //对右下角子棋盘分割
    } else if (dr < (tr + s) && dc >= (tc + s))  {  //表示对当前输入的棋盘而言，残缺块在右上角部分的子棋盘
        cover(tr, tc + s, s, dr, dc);  //对右上角子棋盘分割
        count++;
        bord[tr + s - 1][tc + s - 1] = count;  //下面三个赋值语句是用②号模板覆盖
        bord[tr + s][tc + s - 1] = count;
        bord[tr + s][tc + s] = count;
        cover(tr, tc, s, tr + s - 1, tc + s - 1);  //对左上角子棋盘分割
        cover(tr + s, tc, s, tr + s, tc + s - 1);  //对左下角子棋盘分割
        cover(tr + s, tc + s, s, tr + s, tc + s);  //对右下角子棋盘分割
    } else if (dr >= (tr + s) && dc < (tc + s)) {  //表示对当前输入的棋盘而言，残缺块在左下角部分的子棋盘
        cover(tr + s, tc, s, dr, dc);
        count++;
        bord[tr + s - 1][tc + s - 1] = count;  //下面三个赋值语句是用③号模板覆盖
        bord[tr + s - 1][tc + s] = count;
        bord[tr + s][tc + s] = count;
        cover(tr, tc, s, tr + s - 1, tc + s - 1);
        cover(tr, tc + s, s, tr + s - 1, tc + s);
        cover(tr + s, tc + s, s, tr + s, tc + s);
    } else if (dr >= (tr + s) && dc >= (tc + s)) { //表示对当前输入的棋盘而言，残缺块在右下角部分的子棋盘
        cover(tr + s, tc + s, s, dr, dc);
        count++;
        bord[tr + s - 1][tc + s - 1] = count;  //下面三个赋值语句是用④号模板覆盖
        bord[tr + s - 1][tc + s] = count;
        bord[tr + s][tc + s - 1] = count;
        cover(tr, tc, s, tr + s - 1, tc + s - 1);
        cover(tr, tc + s, s, tr + s - 1, tc + s);
        cover(tr + s, tc, s, tr + s, tc + s - 1);
    }
}