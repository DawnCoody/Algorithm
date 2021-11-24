/**
 * 在一个n*m的方格中，m为奇数，放置有n*m个数，方格中间的下方有一人，
 * 此人可按照正前方相临的五个方向(方格)前进但不能越出方格。人每走过
 * 一个方格必须取此方格中的数。要求找到一条从底到顶的路径，使其数相加之和为最大。输出和的最大值。
 */
#include <stdio.h>

int main() {
    int a[6][7] = {{16, 4, 3, 12, 6, 0, 3}, {4, -5, 6, 7, 0, 0, 2},
                   {6, 0, -1, -2, 3, 6, 8}, {5, 3, 4, 0, 0, -2, 7},
                   {-1, 7, 4, 0, 7, -5, 6}, {0, -1, 3, 4, 12, 4, 2}};
    int b[6][7], c[6][7];
    int i, j, k;
    int max;
    int flag;

    for (i = 0; i < 6; i++)
        for (j = 0; j < 7; j++) {
            b[i][j] = a[i][j];
            c[i][j] = -1;
        }

    for (i = 1; i < 5; i++) {
        for (j = 0; j < 7; j++) {
            max = 0;
            for (k = j - 2; k <= j + 2; k++) {
                if (k < 0)
                    continue;

                else if (k > 6)
                    break;
                else {
                    if (b[i][j] + b[i - 1][k] > max) {
                        max = b[i][j] + b[i - 1][k];
                        flag = k;
                    }
                }
            }
            b[i][j] = max;
            c[i][j] = flag;
        }
    }

    for (j = 1; j <= 5; j++)  // i=5
    {
        max = 0;
        for (k = j - 2; k <= j + 2; k++) {
            if (k < 0)
                continue;
            else if (k > 6)
                break;
            else {
                if (b[i][j] + b[i - 1][k] > max) {
                    max = b[i][j] + b[i - 1][k];
                    flag = k;
                }
            }
        }
        b[i][j] = max;
        c[i][j] = flag;
    }

    max = 0;
    for (j = 1; j <= 5; j++) {
        if (b[i][j] > max) {
            max = b[i][j];
            flag = j;
        }
    }
    printf("从底到顶最大和值为：%d\n\n", max);
    // temp=c[i][flag];
    printf("从底到顶分别取数：");
    printf("%d", a[i][flag]);

    for (j = i; j > 0; j--) {
        flag = c[j][flag];
        printf("%5d", a[j - 1][flag]);
    }
    printf("\n");
    return 0;
}
