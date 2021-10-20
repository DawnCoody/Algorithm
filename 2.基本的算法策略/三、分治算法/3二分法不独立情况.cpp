/**
 * 求数列的最大子段和。
 */
/**
 * 算法设计：
 *      如果将所给的序列 a[1:n] 分给长度相等的两段 a[1:(n/2)] 和 a[(n/2) + 1 : n]，分别求出这两段的最大子段和，则 a[1:n] 的最大子段和有 3 种情况
 *          1) a[1:n]的最大子段和与a[1:(n/2)]的最大子段和相同。
 *          2) a[1:n]的最大子段和与a[(n/2) + 1:n]的最大子段和相同。
 *          3) a[1:n]的最大子段和为a[i:j]，且 1 <= i <= (n / 2), (n / 2) + 1 <= j <= n;
 *      情况1和情况2可以递归求得
 *      对于情况3，序列中的元素 a[(n/2)] 与 a[(n/2) + 1] 一定在最大子段中。因此，可以计算出 a[i:(n/2)]的最大值 s1；并计算出 a[(n/2) + 1 : j] 中的最大值 s2. 
 *      则 s1 + s2 即为出现情况 3 时的最优值。
 */
#include <iostream>
using namespace std;

int max_sub_sum(int a[], int left, int right);

int main(int argc, char const *argv[]) {
    int n, a[100];
    cout << "请输入有多少个数：";
    cin >> n;
    cout << "请输入这几个数：";
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "最大和为：" << max_sub_sum(a, 0, n - 1) << endl;
    return 0;
}

int max_sub_sum(int a[], int left, int right) {
    // left_sum、right_sum 为上次返回的最大值，temp_left_sum和temp_right_sum 为当前层递归中求最大值的临时变量
    // center 为 左边界和右边界的中间下标,lefts、rights 分别为 center 左边的最大值和右边的最大值
    int left_sum, right_sum, temp_left_sum = 0, center, temp_right_sum = 0, lefts = 0, rights = 0;
    if (left == right)  // 递归头，左边界等于右边界
        if (a[left] >= 0)   // 如果当前值大于 0 返回 当前值
            return a[left];
        else                // 当前值小于 0 返回 0 
            return 0;
    else {
        center = (left + right) / 2;                            // 取中间值
        left_sum = max_sub_sum(a, left, center);                // 分别向左右两边分治
        right_sum = max_sub_sum(a, center + 1, right);
        for (int i = center; i >= left; i--) {                  // 在 center 左边中找最大值
            temp_left_sum += a[i];
            if (temp_left_sum > lefts) lefts = temp_left_sum;
        }
        for (int i = center + 1; i <= right; i++) {             // 在 center 右边中找最大值
            temp_right_sum += a[i];
            if (temp_right_sum > rights) rights = temp_right_sum;
        }
        // 如果 center 左边的和是最大的，返回左边的值
        if (lefts + rights < left_sum && right_sum < left_sum) return left_sum;
        // 如果 center 右边的和是最大的，返回右边边的值
        if (lefts + rights < right_sum) return right_sum;
        // 如果 center 左边与右边的和是最大的，返回两者和的值
        return lefts + rights;
    }
}
